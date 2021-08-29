package com.vishwa.MovieBookingSystem.dao;

import com.vishwa.MovieBookingSystem.enteties.Status;
import org.springframework.data.jpa.repository.JpaRepository;

public interface StatusDao extends JpaRepository<Status,Integer> {
     Status findByStatusName(String statusName);
}
