package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.dao.MovieDao;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@Service
public class MovieServiceImpl implements MovieService {

    @Autowired
    private MovieDao movieDao;

    @Override
    public Movie acceptMovieDetails(Movie movie) {
        /*
        * with the help of MovieDao save into DB
        * */
        return movieDao.save(movie);
    }

    @Override
    public Movie getMovieDetails(int id) throws MovieDetailNotFoundException {
        /*
        * Fetch the movie details based on the id
        * movie.findById(id) will return Optional which has a method orElseThrows
        * orElseThrows: if it does not find any movie then it will throws MovieNotFoundException
        * */
        return  movieDao.findById(id).orElseThrow(() ->new MovieDetailNotFoundException("Movie not found for id"+ id));
    }

    @Override
    public Movie updateMovieDetails(int id, Movie movie) throws MovieDetailNotFoundException {
       //to update movie first get the movie
        Movie savedMovie = getMovieDetails(id);

        //read the attribute from the movie object and update it in savedMovie
        if(isNotNullOrZero(movie.getMovieName()))
        savedMovie.setMovieName(movie.getMovieName());

        //update movieDescription
        if(isNotNullOrZero(movie.getMovieDescription()))
            savedMovie.setMovieDescription(movie.getMovieDescription());

        //update movieDuration
if(isNotNullOrZero(movie.getDuration()))
        savedMovie.setDuration(movie.getDuration());

//update coverPhoto
if(isNotNullOrZero(movie.getCoverPhotoUrl()))
    savedMovie.setCoverPhotoUrl(movie.getCoverPhotoUrl());

//update released date
  if(isNotNullOrZero(movie.getReleaseDate()))
      savedMovie.setReleaseDate(movie.getReleaseDate());
  //update status
  if(isNotNullOrZero(movie.getStatus()))
      savedMovie.setStatus(movie.getStatus());

  //trailer
        if(isNotNullOrZero(movie.getTrailerUrl()))
savedMovie.setTrailerUrl(movie.getTrailerUrl());

        return movieDao.save(savedMovie);
    }

    private boolean isNotNullOrZero(Object obj){
        return obj!=null;
    }

    @Override
    public boolean deleteMovie(int id) throws MovieDetailNotFoundException {
        Movie savedMovie=getMovieDetails(id);
        movieDao.delete(savedMovie);
        return true;
    }

    @Override
    public List<Movie> getAllMoviesDetails() {
        return movieDao.findAll();
    }
}
