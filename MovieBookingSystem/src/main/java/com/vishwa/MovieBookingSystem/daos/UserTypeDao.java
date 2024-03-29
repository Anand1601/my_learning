package com.vishwa.MovieBookingSystem.daos;

import com.vishwa.MovieBookingSystem.enteties.UserType;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface UserTypeDao extends JpaRepository<UserType,Integer> {
      Optional<UserType> findByUserTypeName(String userTypeName);
}
