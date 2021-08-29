package com.vishwa.MovieBookingSystem.Services;

import com.vishwa.MovieBookingSystem.enteties.Booking;
import com.vishwa.MovieBookingSystem.exceptions.BookingDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MoiveTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.UserDetailsNotFoundException;

import java.util.List;

public interface BookingService {

    public Booking acceptBookingDetails(Booking booking)
            throws MoiveTheatreDetailsNotFoundException,
            UserDetailsNotFoundException, MovieTheatreDetailsNotFoundException;
    public Booking getBookingDetails(int id) throws BookingDetailsNotFoundException;
    public boolean deleteBooking(int id) throws BookingDetailsNotFoundException;
    public List<Booking> getAllBookingDetails();
}
