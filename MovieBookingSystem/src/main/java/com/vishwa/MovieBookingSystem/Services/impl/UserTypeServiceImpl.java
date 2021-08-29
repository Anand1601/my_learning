package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.UserTypeService;
import com.vishwa.MovieBookingSystem.dao.UserTypeDao;
import com.vishwa.MovieBookingSystem.enteties.UserType;
import com.vishwa.MovieBookingSystem.exceptions.UserTypeDetailsNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
@Service
public class UserTypeServiceImpl implements UserTypeService {

    @Autowired
    private UserTypeDao userTypeDao;

    @Override
    public UserType acceptUserType(UserType userType) {
        return userTypeDao.save(userType);
    }

    @Override
    public UserType getUserTypeDetails(int id) throws UserTypeDetailsNotFoundException {
        return userTypeDao.findById(id).orElseThrow(()->new UserTypeDetailsNotFoundException("UserType not found with id:"+id));
    }

    @Override
    public UserType getUserTypeDetailsFromUserTypeName(String userType) throws UserTypeDetailsNotFoundException {
        return userTypeDao.findByUserTypeName(userType).orElseThrow(()-> new UserTypeDetailsNotFoundException("UserType not found with id:"+userType));
    }

    @Override
    public boolean deleteUserType(int id) throws UserTypeDetailsNotFoundException {
        UserType userType=getUserTypeDetails(id);
        userTypeDao.delete(userType);
        return true;
    }

    @Override
    public List<UserType> getAllUserTypeDetails() {
        return userTypeDao.findAll();
    }
}
