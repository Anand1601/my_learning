package com.vishwa.MovieBookingSystem.dao;

import com.vishwa.MovieBookingSystem.enteties.Theatre;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface TheatreDao extends JpaRepository<Theatre,Integer> {

public List<Theatre> findByTheatreName(String theaterName);
public List<Theatre> findByTicketPriceLessThan(float price);
public List<Theatre> findByTheatreNameContaining(String theatreName);

}
