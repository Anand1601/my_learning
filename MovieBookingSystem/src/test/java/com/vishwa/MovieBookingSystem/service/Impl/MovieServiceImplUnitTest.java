package com.vishwa.MovieBookingSystem.service.Impl;

import com.vishwa.MovieBookingSystem.Services.impl.MovieServiceImpl;
import com.vishwa.MovieBookingSystem.dao.MovieDao;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.enteties.Status;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.boot.test.context.SpringBootTest;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@SpringBootTest
public class MovieServiceImplUnitTest {

    /*
    * MovieServiceImpl, it depends on MovieDao
    *
    * we need to create a dummy of MovieDao and replace MovieDao present in MovieServiceImpl
    *
    * */

    @Mock     //this the dummy or mocked MovieDao
    private MovieDao movieDao;

    @InjectMocks
    private MovieServiceImpl movieService;

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
    movie.setStatus(status);
    movie.setMovieId(1);
        movie.setTrailerUrl("T_url");

        /*
        * Adding the functionality on MovieDao
        *
        * It says to MovieDao, when same method is called, just return the object back
        *
        * This doesn't involve actual calling of the database
        * */
        Mockito.when(movieDao.save(movie)).thenReturn(movie);
        Mockito.when(movieDao.findById(1)).thenReturn(java.util.Optional.ofNullable(movie));
        List<Movie> savedMovies = new ArrayList<>();
        savedMovies.add(movie);
        Mockito.when(movieDao.findAll()).thenReturn(savedMovies);
}


    //test acceptMovieDetails
  @Test
    public void testAcceptMovieDetails(){
     Movie saveMovie = movieService.acceptMovieDetails(movie);
      Assertions.assertNotNull(saveMovie);
    }

  //getMovieDetails
    @Test
    public void testGetMovieDetails() throws MovieDetailNotFoundException {
        Movie savedMovie = movieService.getMovieDetails(1);
        Assertions.assertNotNull(savedMovie);
    }
  //updateMovieDetails
    @Test
    public void testUpdateMovieDetails() throws MovieDetailNotFoundException {
        Movie updatedMovie = movieService.updateMovieDetails(1,movie);
        Assertions.assertNotNull(updatedMovie);
    }
    //deleteMovie


    //getAllMovieDetails
    @Test
    public void testGetAllMovieDetails(){
        List<Movie> movies = movieService.getAllMoviesDetails();
        Assertions.assertNotEquals(0,movies.size());
    }

}
