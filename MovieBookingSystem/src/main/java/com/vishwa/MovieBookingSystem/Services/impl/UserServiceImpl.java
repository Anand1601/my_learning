package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.UserService;
import com.vishwa.MovieBookingSystem.Services.UserTypeService;
import com.vishwa.MovieBookingSystem.dao.UserDao;
import com.vishwa.MovieBookingSystem.enteties.User;
import com.vishwa.MovieBookingSystem.exceptions.UserDetailsNotFoundException;
import com.vishwa.MovieBookingSystem.exceptions.UserNameAlreadyExistsException;
import com.vishwa.MovieBookingSystem.exceptions.UserTypeDetailsNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;
@Service
public class UserServiceImpl implements UserService {
    @Autowired
    UserDao userDao;

    @Autowired
    UserTypeService userTypeService;

    @Override
    public User acceptUserDetails(User user) throws UserNameAlreadyExistsException, UserTypeDetailsNotFoundException {
 if(userDao.findByUserName(user.getUserName()).isPresent())
       {
           throw new UserNameAlreadyExistsException("userName already taken.");
       }

 //check if it is a valid user type or not
      userTypeService.getUserTypeDetails(user.getUserType().getUserTypeId());
       return userDao.save(user);

    }

    @Override
    public User getUserDetails(int id) throws UserDetailsNotFoundException {

        return userDao.findById(id).orElseThrow(()->new UserDetailsNotFoundException("user details not found with the id:"+id));
    }

    @Override
    public User getUserDetailsByUserName(String username) throws UserDetailsNotFoundException {
return userDao.findByUserName(username).orElseThrow(()->new UserDetailsNotFoundException("User not found by username:"+username));

    }

    @Override
    public User updateUserDetails(int id, User user) throws UserDetailsNotFoundException, UserNameAlreadyExistsException, UserTypeDetailsNotFoundException {
        User savedUser=getUserDetails(id);
        if(userDao.findByUserName(user.getUserName()).isPresent())
        {
            throw new UserNameAlreadyExistsException("This username is already taken.");
        }
        userTypeService.getUserTypeDetails(user.getUserType().getUserTypeId());
//name
if(isNotNullOrZero(user.getUserName()))
    savedUser.setUserName(user.getUserName());

//first name
        if(isNotNullOrZero(user.getFirstName()))
            savedUser.setFirstName(user.getFirstName());

        //last name
        if(isNotNullOrZero(user.getLastname()))
            savedUser.setLastname(user.getLastname());

        //password
        if(isNotNullOrZero(user.getPassword()))
            savedUser.setPassword(user.getPassword());

        //DOB
        if(isNotNullOrZero(user.getDateOfBirth()))
            savedUser.setDateOfBirth(user.getDateOfBirth());

        //phone number
        if(isNotNullOrZero(user.getPhoneNumber()))
            savedUser.setPhoneNumber(user.getPhoneNumber());

        //userType
        if(isNotNullOrZero(user.getUserType()))
            savedUser.setUserType(user.getUserType());

        //Language
        if(isNotNullOrZero(user.getLanguage()))
            savedUser.setLanguage(user.getLanguage());

        return userDao.save(savedUser);
    }

    boolean isNotNullOrZero(Object obj)
    {
        return obj!=null;
    }


}

