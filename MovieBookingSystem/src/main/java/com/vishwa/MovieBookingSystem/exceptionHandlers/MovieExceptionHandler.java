package com.vishwa.MovieBookingSystem.exceptionHandlers;

import com.vishwa.MovieBookingSystem.dtos.InvalidResponseDTO;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.MovieInvalidNameException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;

@ControllerAdvice
/*
 * 1. create the object of this class and make it available in spring container
 * 2.Everytime an exception is thrown (only in controller class) this class will be informed
 * 3. exception occurred at any level, if you don't handle that, will finally thrown in controller
 * layer and then this class is responsible to handle that.
 * */
public class MovieExceptionHandler {

    private static final Logger LOGGER = LoggerFactory.getLogger(MovieExceptionHandler.class);

    @ExceptionHandler(value = MovieDetailNotFoundException.class)
    /*
     * this annotation, indicate to this method, that if the given exception happens,
     *  below method should be called
     * */
    public ResponseEntity handleMovieNotFoundException() {
        LOGGER.error("Exception happened, movie id not found");
        return new ResponseEntity("No movie found with given movieId", HttpStatus.BAD_REQUEST);

    }

    @ExceptionHandler(value = MovieInvalidNameException.class)
    public ResponseEntity handleMovieNameInvalidException(){
        InvalidResponseDTO iRD = new InvalidResponseDTO("Movie name passed is empty/not correct",HttpStatus.BAD_REQUEST.toString(),"Movie resource");
        return new ResponseEntity(iRD,HttpStatus.BAD_REQUEST);
        //return new ResponseEntity("Movie name not passed/invalid",HttpStatus.BAD_REQUEST);
    }



}
