package com.vishwa.MovieBookingSystem.service.Impl;

import com.vishwa.MovieBookingSystem.Services.StatusService;
import com.vishwa.MovieBookingSystem.Services.impl.StatusServiceImpl;
import com.vishwa.MovieBookingSystem.daos.StatusDao;
import com.vishwa.MovieBookingSystem.enteties.Status;
import com.vishwa.MovieBookingSystem.exceptions.StatusDetailsNotFoundException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@SpringBootTest
public class StatusServiceImplTest {

    @Mock
    private StatusDao statusDao;

    @InjectMocks
    private StatusServiceImpl statusServiceImpl;

    Status status;

    @BeforeEach
    public void beforEach(){
    status = new Status("Released");
        Mockito.when(statusDao.save(status)).thenReturn(status);
        Mockito.when(statusDao.findById(1)).thenReturn(Optional.ofNullable(status));
        Mockito.when(statusDao.findByStatusName("Released")).thenReturn(status);
        List<Status> statuses = new ArrayList<>();
        statuses.add(status);
        Mockito.when(statusDao.findAll()).thenReturn(statuses);

    }

    //test acceptStatusDetails
    @Test
    public void TestAcceptStatusDetails(){
        Status saveStatus = statusServiceImpl.acceptStatusDetails(status);
        Assertions.assertNotNull(saveStatus);
    }

    //Test getStatusDetails
    @Test
    public void TestGetStatusDetails() throws StatusDetailsNotFoundException {
        Status savedStatus = statusServiceImpl.getStatusDetails(1);
        Assertions.assertNotNull(savedStatus);
    }


    // Test getStatusDetailsByStatusName
    @Test
    public void TestGetStatusDetailsByStatusName() throws StatusDetailsNotFoundException {
        Status savedStatus = statusServiceImpl.getStatusDetailsByStatusName("Released");
        Assertions.assertNotNull(savedStatus);
    }

    //Test DeleteStatus
    

    //test getAllStatus
    @Test
    public void TestGetAllStatus(){
        List<Status> statuses = statusServiceImpl.getAllStatusDetails();
        Assertions.assertNotEquals(0,statuses.size());
    }

}
