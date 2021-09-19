package com.vishwa.MovieBookingSystem.controllers;

import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.Services.StatusService;
import com.vishwa.MovieBookingSystem.Services.impl.StatusServiceImpl;
import com.vishwa.MovieBookingSystem.Validators.MovieDTOValidator;
import com.vishwa.MovieBookingSystem.dtos.MovieDTO;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.enteties.Status;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieInvalidNameException;
import com.vishwa.MovieBookingSystem.exceptions.StatusDetailsNotFoundException;
import org.modelmapper.ModelMapper;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.slf4j.Logger;

import javax.print.attribute.standard.Media;
import java.util.ArrayList;
import java.util.List;

/*
* End point
* 127.0.0.1:8081/mbs/v1
* root path always -> mbs/v1
* */

@RestController
/*
* 1. act as a @Component
* 2. Give hint to Spring, that whenever a REST call comes,
*    make sure this class is informed , whether I have written the logic for the call or not .
*    if I written the logic then that should be addressed or missed if not.
*
* */
@RequestMapping("/movies")
/*
* it maps the controller class to the respective service class
* the actual URI is
* 127.0.0.1:8081/mbs/v1/movies
* */
public class MovieController {

    private static final Logger LOGGER = (Logger) LoggerFactory.getLogger(MovieController.class);

    @Autowired
    private ModelMapper modelMapper;
    @Autowired
    private MovieService movieService;

     @Autowired
     private   StatusService statusService ;

     @Autowired
    private MovieDTOValidator movieDTOValidator;

    /*
    *127.0.0.1.:8081/mbs/v1/movies/greetings
    *
    *Hello People
    * */
    @GetMapping("/greetings")
    public ResponseEntity helloWorld(){

        /*
        *ResponseEntity:
        * -it's like a mapper which takes object and the status as argument
        * -and responsible for warpping it in proper json formate and than return it bakc to the client
        * who maekes the call
        *
        * */

        LOGGER.info("Inside the hello Wolrld Method");
        return new ResponseEntity("Hello People", HttpStatus.OK);
    }

/*
* Get all movies
* GET 127.0.0.1.:8081/mbs/v1/movies
* */
    @GetMapping
    public ResponseEntity getAllMovies(){
        List<Movie> movies = movieService.getAllMoviesDetails();
        /*
        * we can return the answer directly as ---
        * -->return new ResponseEntity(movies,HttpStatus.OK);
        * but it is wrong to convert the entity class directly to JSON, also it may possible that the entity class contains
        * some more data that you don't want a user/client should know so we should make a new package DTO(data
        * transfer object) which contains corresponding DTO classes for every entity.
        *
        *  */

List<MovieDTO> movieDTOS=new ArrayList<>();

        for(Movie movie:movies)
        {
            movieDTOS.add(movieService.convertToMovieDTO(movie));
        }

return new ResponseEntity(movieDTOS,HttpStatus.OK);

    }

    /*
    * Get Movie on the base of id
    * GET 127.0.0.1:8081/mbs/v1/movies/id
    * @PathVariable used to give the path to the function,and here it will give the value to movieId
    * */
    @GetMapping("/{Id}")
    public ResponseEntity getMovieBasedOnId(@PathVariable(name="Id") int movieId) throws MovieDetailNotFoundException {
        Movie movie =   movieService.getMovieDetails(movieId);


                MovieDTO movieDTO = convertToMovieDTO(movie);
        return new ResponseEntity(movieDTO,HttpStatus.OK);
    }

    /*
    * Creating new movie
    *POST 127.0.0.1:8081/mbs/v1/movies
    * consume = what kind of data the method consume
    * produces = what kind of data the method return or produces
    * @RequestBody = used to convert the JSON to MovieDTO and giving it.
    * */
@PostMapping(consumes = MediaType.APPLICATION_JSON_VALUE,produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity createMovie(@RequestBody MovieDTO movieDTO) throws StatusDetailsNotFoundException, MovieInvalidNameException {

    movieDTOValidator.validate(movieDTO);

        //I need to create the new movie
        //I need to create Movie object from MovieDTO object
    Movie movie = modelMapper.map(movieDTO,Movie.class);
    //movie object should contain status object that must not null :injecting the status object in movie obj
    Status status= statusService.getStatusDetails(movieDTO.getStatus_id());
    movie.setStatus(status);
    Movie savedMovie = movieService.acceptMovieDetails(movie);
        //I need to return the response
        MovieDTO responseBody = modelMapper.map(savedMovie,MovieDTO.class);
        return new ResponseEntity(responseBody,HttpStatus.CREATED);
    }

    /*
    * I would like to update an already existing movie
    * PUT 127.0.0.1:8081/mbs/v1/movies/{movieId}
    * Json body has to be passed
    *
    * */

    @PutMapping(value="/{movieId}",consumes = MediaType.APPLICATION_JSON_VALUE,
            produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity updateMovieDetails(@RequestBody MovieDTO movieDTO,
                                             @PathVariable(name="movieId") int movieId) throws MovieDetailNotFoundException {
        //first check if the movie present in the system or not, if not it will throw the exception
        Movie storedMovie = movieService.getMovieDetails(movieId);

        Movie movieTOBeUpdated = modelMapper.map(movieDTO,Movie.class);
        Movie savedMovie = movieService.updateMovieDetails(movieId,movieTOBeUpdated);

        return new ResponseEntity(modelMapper.map(savedMovie,MovieDTO.class),HttpStatus.ACCEPTED);


    }

    /*
    * to delete existing movie
    * DELETE 127.0.0.1:8081/mbs/v1/movies/{movieId}
    * */
@DeleteMapping(value = "/{movieId}")
public ResponseEntity deleteMovie(@PathVariable(name ="movieId") int id) throws MovieDetailNotFoundException {
    movieService.deleteMovie(id);
    return new ResponseEntity("DELETED",HttpStatus.OK);
}

    /*
    * there are two way to converting the Movie class to MovieDao :
    * one is by using MovieServices which take a lot of code to write
    * the other is using model mapper
    * */
    private MovieDTO convertToMovieDTO(Movie movie)
    {
        return   modelMapper.map(movie,MovieDTO.class);

    }



}

