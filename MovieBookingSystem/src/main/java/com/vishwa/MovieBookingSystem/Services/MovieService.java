package com.vishwa.MovieBookingSystem.Services;

/*
* this interface will define methods supported by MovieService
*
* */

import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;

import java.util.List;


public interface MovieService {

    //it should be able to take a movie request and save it to database
    Movie acceptMovieDetails(Movie movie);

    //to get the movie details based on movie
    Movie getMovieDetails(int id) throws MovieDetailNotFoundException;

    //update the details for the existing movie
    Movie updateMovieDetails(int id,Movie movie) throws MovieDetailNotFoundException;

    // to delete a movie
    boolean deleteMovie(int id)throws MovieDetailNotFoundException;

    //get the list of all the movies
    List<Movie> getAllMoviesDetails();

}
