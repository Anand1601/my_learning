package com.vishwa.MovieBookingSystem.dao;

import com.vishwa.MovieBookingSystem.enteties.Movie;
import org.springframework.data.jpa.repository.JpaRepository;

import java.time.LocalDateTime;
import java.util.List;


public interface MovieDao extends JpaRepository<Movie,Integer> {
//to support search based on the movie name
    public List<Movie> findByMovieName(String movieName);

    /*
    queries based on multiple columns
    1.query based on name and duration
     */
    public List<Movie> findByMovieNameAndDuration(String name,int duration);
    //find movie greater than given hour
    List<Movie> findByReleaseDateBetween(LocalDateTime start,LocalDateTime end);
    public List<Movie> findByDurationGreaterThanEqual(int duration);
    List<Movie> findByReleaseDateAfter(LocalDateTime releaseDate);
    List<Movie> findByMovieNameContaining(String movieName);
    List<Movie> findByMovieNameIgnoreCase(String movieName);
}
