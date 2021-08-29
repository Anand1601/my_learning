package com.vishwa.MovieBookingSystem.Services;

import com.vishwa.MovieBookingSystem.enteties.User;
import com.vishwa.MovieBookingSystem.exceptions.UserDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.UserNameAlreadyExistsException;
import com.vishwa.MovieBookingSystem.exceptions.UserTypeDetailsNotFoundException;

public interface UserService {
    /*allow the creation of new users
    and not allowed to create user if
    1.it's an existing user
    2.if it is a user of wrong type
    * */
     User acceptUserDetails(User user) throws UserNameAlreadyExistsException, UserTypeDetailsNotFoundException;

     //fetch the user details based on user id
    public User getUserDetails(int id )throws UserDetailsNotFoundException;

    //fetch the user by its name
    public User getUserDetailsByUserName(String username)throws UserDetailsNotFoundException;

    //update the user details
    public User updateUserDetails(int id ,User user)throws UserDetailsNotFoundException,UserNameAlreadyExistsException,UserTypeDetailsNotFoundException;

}
