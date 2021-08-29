package com.vishwa.MovieBookingSystem.controllers;

import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.slf4j.Logger;

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
    private MovieService movieService;
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
* 127.0.0.1.:8081/mbs/v1/movies
* */
    @GetMapping
    public ResponseEntity getAllMovies(){
        List<Movie> movies = movieService.getAllMoviesDetails();
        return new ResponseEntity(movies,HttpStatus.OK);
    }



}

