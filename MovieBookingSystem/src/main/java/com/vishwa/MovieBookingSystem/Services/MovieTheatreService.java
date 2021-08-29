package com.vishwa.MovieBookingSystem.Services;

import com.vishwa.MovieBookingSystem.enteties.MovieTheatre;
import com.vishwa.MovieBookingSystem.exceptions.MoiveTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.TheatreDetailsNotFoundException;

import java.util.List;

public interface MovieTheatreService {
    public MovieTheatre acceptMovieTheatreDetails(MovieTheatre movieTheatre) throws MovieDetailNotFoundException, MoiveTheatreDetailsNotFoundException, TheatreDetailsNotFoundException;
    public  MovieTheatre getMovieTheatreDetails(int id) throws MovieTheatreDetailsNotFoundException;
    public boolean deleteMovieTheatre(int id) throws  MovieTheatreDetailsNotFoundException;
    public List<MovieTheatre> getMovieTheatreDetails();
}
