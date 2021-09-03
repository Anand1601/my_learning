package com.vishwa.MovieBookingSystem.Services;

/*
* this interface will define methods supported by MovieService
*
* */

import com.vishwa.MovieBookingSystem.dtos.MovieDTO;
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

    default MovieDTO convertToMovieDTO(Movie movie){
        MovieDTO movieDTO =new MovieDTO();
        movieDTO.setMovieId(movie.getMovieId());
        movieDTO.setMovieName(movie.getMovieName());
        movieDTO.setMovieDescription(movie.getMovieDescription());
        movieDTO.setDuration(movie.getDuration());
        movieDTO.setReleaseDate(movie.getReleaseDate());
        movieDTO.setCoverPhotoUrl(movie.getCoverPhotoUrl());
        movieDTO.setStatus_id(movie.getStatus().getStatusId());
        movieDTO.setTrailerUrl(movie.getTrailerUrl());

        return movieDTO;
    }
}
