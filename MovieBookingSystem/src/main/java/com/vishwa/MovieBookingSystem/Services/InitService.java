package com.vishwa.MovieBookingSystem.Services;

//this will be used to initialize data in all the tables of DB

import com.vishwa.MovieBookingSystem.exceptions.*;

public interface InitService {

    //This method when called will initialize the data in the DB
    public void init() throws UserTypeDetailsNotFoundException, UserNameAlreadyExistsException, MoiveTheatreDetailsNotFoundException, MovieDetailNotFoundException, TheatreDetailsNotFoundException, UserDetailsNotFoundException, MovieTheatreDetailsNotFoundException;

}
