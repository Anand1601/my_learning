package com.vishwa.MovieBookingSystem.service.Impl;

import com.vishwa.MovieBookingSystem.Services.impl.CityServiceImpl;
import com.vishwa.MovieBookingSystem.dao.CityDao;
import com.vishwa.MovieBookingSystem.enteties.City;
import com.vishwa.MovieBookingSystem.exceptions.CityDetailsNotFoundException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

@SpringBootTest
public class CityServiceImplTest {

    @Mock
    private CityDao cityDao;

    @InjectMocks
    private CityServiceImpl cityService;

    City city;

    List<City> cities;

    @BeforeEach
    public void addFunctionalityToMockedDao(){
        Mockito.when(cityDao.save(new City("Bangalore"))).
                thenReturn(new City(1,"Bangalore"));

        //Mock the functionality is CityDao
        Mockito.when(cityDao.findById(2)).
                thenReturn(Optional.of(new City(2, "Mumbai")));

        Mockito.when(cityDao.save(new City(2,"MumbaiNew"))).
                thenReturn(new City(2,"MumbaiNew"));

        Mockito.when(cityDao.findByCityName("Mumbai")).
                thenReturn(new City(2,"Mumbai"));


        cities = new ArrayList<>();
        cities.add(new City("New Delhi"));
        cities.add(new City("Pune"));
        Mockito.when(cityDao.findAll()).thenReturn(cities);
        Mockito.when(cityDao.saveAll(cities)).thenReturn(cities);
    }

    //acceptCityDetails
    @Test
    public void TestAcceptCityDetails(){

        city = new City("Bangalore");
        City savedCity = cityService.acceptCityDetails(city);
        Assertions.assertNotNull(savedCity);
        Assertions.assertEquals(1,savedCity.getCityId());

    }

    //acceptMultipleCityDetails
    @Test
    public void TestAcceptMultipleCityDetails(){
    List<City> saveList = cityService.acceptMultipleCityDetails(cities);

        Assertions.assertNotEquals(0, Objects.requireNonNull(saveList).size());
    }
    //updateCityDetails
    @Test
    public void TestUpdateCityDetails() throws CityDetailsNotFoundException {

        city = new City("MumbaiNew");
        City updatedCity = cityService.updateCityDetails(2,city);

        Assertions.assertNotNull(updatedCity);
        Assertions.assertEquals(2,updatedCity.getCityId());

    }

    //getCityDetails
    @Test
    public void TestGetCityDetails() throws CityDetailsNotFoundException {
        City savedCity = cityService.getCityDetails(2);
        Assertions.assertNotNull(savedCity);
    }

    //getCityDetailsByCityName
    @Test
    public void TestGetCityDetailsByCityName() throws CityDetailsNotFoundException {
        City savedCity = cityService.getCityDetailsByCityName("Mumbai");
        Assertions.assertNotNull(savedCity);
    }

    //deleteCity


    //getAllCityDetails
    @Test
    public void TestGetAllCityDetails(){
        List<City> savedCities = cityService.getAllCityDetails();
        Assertions.assertNotEquals(0,savedCities.size());

    }

}
