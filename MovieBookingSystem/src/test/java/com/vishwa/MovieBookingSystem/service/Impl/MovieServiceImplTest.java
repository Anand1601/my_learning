package com.vishwa.MovieBookingSystem.service.Impl;

/*
=>this class will be used to write the test cases for class MovieServiceImpl
=>this is not unit testing because it will work only if movieDao and movieService both
works fine, so it is Integration testing
*/

import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.Services.impl.MovieServiceImpl;
import com.vishwa.MovieBookingSystem.Services.impl.StatusServiceImpl;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.enteties.Status;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.time.LocalDateTime;

/*
*Because it is outside the project folder we can not use spring
* to do the dependency injection here directly.
*
* To do so we have an annotation @SpringBootTest which tells the spring t0 do the dependency injection
* here also;
*
* */

@SpringBootTest
public class MovieServiceImplTest {

  @Autowired
 private MovieServiceImpl movieService;

  @Autowired
   private StatusServiceImpl statusService;

Movie movie;



@BeforeEach
public void beforeTest(){
    movie = new Movie();
    movie.setMovieName("Name1");
    movie.setMovieDescription("Desc1");
    movie.setCoverPhotoUrl("cov_url");
    movie.setReleaseDate(LocalDateTime.of(2018,10,5,6,0));
    movie.setDuration(200);
    Status status=new Status();
    status.setStatusName("RELEASED");
   statusService.acceptStatusDetails(status);
    movie.setStatus(status);
        movie.setTrailerUrl("T_url");


}


    //test acceptMovieDetails
  @Test
    public void testAcceptMovieDetails(){
       //check if it save the movie or not
     Movie savedMovie = movieService.acceptMovieDetails(movie);
      Assertions.assertNotNull(savedMovie);
      //Assertions.assertNotNull(savedMovie.getMovieId());
    }

    //test getMovieDetails
    @Test
    public void testGetMovieDetails(){

    }

    //test updateMovieDetails

    //test deleteMovie

}
