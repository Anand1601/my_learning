package com.vishwa.MovieBookingSystem.Validators;

import com.vishwa.MovieBookingSystem.dtos.MovieDTO;
import com.vishwa.MovieBookingSystem.exceptions.MovieInvalidNameException;
import org.springframework.stereotype.Component;
import org.springframework.validation.Errors;
import org.springframework.validation.Validator;

@Component
public class MovieDTOValidator  {

    public void validate(MovieDTO movieDTO) throws MovieInvalidNameException {

        if(movieDTO.getMovieName()==null||movieDTO.getMovieName().equals(""))
            throw new MovieInvalidNameException();
    }



}
