package com.vishwa.MovieBookingSystem.service.Impl;

import com.vishwa.MovieBookingSystem.Services.impl.TheatreServiceImpl;
import com.vishwa.MovieBookingSystem.daos.TheatreDao;
import org.junit.jupiter.api.BeforeEach;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoSettings;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class TheatreServiceImplTest {

    @Mock
    private TheatreDao theatreDao;

    @InjectMocks
    private TheatreServiceImpl theatreServiceImpl;

    @BeforeEach
    public void beforeTest() {

    }

    //Test acceptTheatre
    // Test getTheatreDetails
//Test updateTheatreDetails
//Test deleteTheatre
//Test getAllTheatreDetails


}
