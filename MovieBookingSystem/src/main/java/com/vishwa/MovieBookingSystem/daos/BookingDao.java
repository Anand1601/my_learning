package com.vishwa.MovieBookingSystem.daos;

import com.vishwa.MovieBookingSystem.enteties.Booking;
import org.springframework.data.jpa.repository.JpaRepository;

public interface BookingDao extends JpaRepository<Booking,Integer> {

}
