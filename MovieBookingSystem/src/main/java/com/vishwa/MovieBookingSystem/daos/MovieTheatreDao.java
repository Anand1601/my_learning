package com.vishwa.MovieBookingSystem.daos;

import com.vishwa.MovieBookingSystem.enteties.MovieTheatre;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MovieTheatreDao extends JpaRepository<MovieTheatre,Integer> {
}
