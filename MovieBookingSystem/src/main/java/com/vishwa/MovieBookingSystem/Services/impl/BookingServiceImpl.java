package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.BookingService;
import com.vishwa.MovieBookingSystem.Services.MovieTheatreService;
import com.vishwa.MovieBookingSystem.Services.UserService;
import com.vishwa.MovieBookingSystem.dao.BookingDao;
import com.vishwa.MovieBookingSystem.enteties.Booking;
import com.vishwa.MovieBookingSystem.enteties.MovieTheatre;
import com.vishwa.MovieBookingSystem.exceptions.BookingDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MoiveTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieTheatreDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.UserDetailsNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookingServiceImpl implements BookingService {

    @Autowired
    public UserService userService;

    @Autowired
    public BookingDao bookingDao;

    @Autowired
    public MovieTheatreService movieTheatreService;

    @Override
    public Booking acceptBookingDetails(Booking booking) throws UserDetailsNotFoundException, MovieTheatreDetailsNotFoundException {
      movieTheatreService.getMovieTheatreDetails(booking.getMovieTheatre().getMovieTheatreId());
      userService.getUserDetails(booking.getUser().getUserId());
        return bookingDao.save(booking);
    }

    @Override
    public Booking getBookingDetails(int id) throws BookingDetailsNotFoundException {
        return bookingDao.findById(id).orElseThrow(()->
                new BookingDetailsNotFoundException("Booking not found for this id:"+id));
    }

    @Override
    public boolean deleteBooking(int id) throws BookingDetailsNotFoundException {
        Booking booking = getBookingDetails(id);
        bookingDao.delete(booking);
        return true;
    }

    @Override
    public List<Booking> getAllBookingDetails() {
        return bookingDao.findAll();
    }

}
