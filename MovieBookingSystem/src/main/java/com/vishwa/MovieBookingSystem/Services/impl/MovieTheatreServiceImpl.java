package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.Services.MovieTheatreService;
import com.vishwa.MovieBookingSystem.Services.TheatreService;
import com.vishwa.MovieBookingSystem.dao.MovieTheatreDao;
import com.vishwa.MovieBookingSystem.enteties.MovieTheatre;
import com.vishwa.MovieBookingSystem.exceptions.MoiveTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.TheatreDetailsNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MovieTheatreServiceImpl implements MovieTheatreService {

    @Autowired
    private MovieTheatreDao movieTheatreDao;

    @Autowired
    private TheatreService theatreService;

    @Autowired
    private MovieService movieService;



    @Override
    public MovieTheatre acceptMovieTheatreDetails(MovieTheatre movieTheatre) throws MovieDetailNotFoundException, MoiveTheatreDetailsNotFoundException, TheatreDetailsNotFoundException {
        movieService.getMovieDetails(movieTheatre.getMovie().getMovieId());
      theatreService.getTheatreDetails(movieTheatre.getTheatre().getTheatreId());
        return movieTheatreDao.save(movieTheatre);
    }

    @Override
    public MovieTheatre getMovieTheatreDetails(int id) throws MovieTheatreDetailsNotFoundException {
        return movieTheatreDao.findById(id).orElseThrow(()->new MovieTheatreDetailsNotFoundException("movieTheatre not found by the id"+id));
    }

    @Override
    public boolean deleteMovieTheatre(int id) throws MovieTheatreDetailsNotFoundException {
        MovieTheatre savedMovieTheatre=getMovieTheatreDetails(id);
        movieTheatreDao.delete(savedMovieTheatre);
    return true;
    }

    @Override
    public List<MovieTheatre> getMovieTheatreDetails() {
        return movieTheatreDao.findAll();
    }
}
