package com.vishwa.MovieBookingSystem.dao;

import com.vishwa.MovieBookingSystem.enteties.Booking;
import org.springframework.data.jpa.repository.JpaRepository;

public interface BookingDao extends JpaRepository<Booking,Integer> {

}
