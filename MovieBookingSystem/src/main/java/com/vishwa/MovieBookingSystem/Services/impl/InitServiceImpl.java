package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.*;
import com.vishwa.MovieBookingSystem.dao.*;
import com.vishwa.MovieBookingSystem.enteties.*;
import com.vishwa.MovieBookingSystem.exceptions.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

@Service
public class InitServiceImpl implements InitService {

    @Autowired
  private CityService cityService;

    @Autowired
   private UserTypeDao userTypeDao;

    @Autowired
    private StatusService statusService;

    @Autowired
    private MovieService movieService;

    @Autowired
    private UserService userService;

    @Autowired
    private TheatreService theatreService;

    @Autowired
    private MovieTheatreService movieTheatreService;

    @Autowired
    private BookingService bookingService;

    @Autowired
            private LanguageService languageService;

    //Cooking data
            List<Status> statuses = new ArrayList<>();
            Movie movie1=new Movie();
            Movie movie2= new Movie();
            List<City> cities=new ArrayList<>();
            List<UserType> userTypes = new ArrayList<>();
            Theatre theatre1= new Theatre();
            Theatre theatre2= new Theatre();
            MovieTheatre movieTheatre1 = new MovieTheatre();
               User user1 = new User();
                Booking booking1 = new Booking();
                List<Language> languages = new ArrayList<>();

             @Override
    public void init() throws UserTypeDetailsNotFoundException, UserNameAlreadyExistsException,
                     MoiveTheatreDetailsNotFoundException, MovieDetailNotFoundException,
                     TheatreDetailsNotFoundException, UserDetailsNotFoundException,
                     MovieTheatreDetailsNotFoundException {
        /*
        * write the logic to store data inside the database in different tables
        * */


        /*
        * add cities
        * to do this you can use cityDao or acceptCityDetails both will do the same but it is better
        * use cityService
        * ## if use can do the task using service don't use dao in any layer except DAL ##
        * */
        createCities();

        //add user types
        createUserTypes();

        //add statuses
        createStatuses();

        //add Movies
        createMovie();

        //add users
        addCustomer();

        //add theatres
                 addTheatres();


                 //add MovieTheatre
                 addMovieTheatre();

                 //add Booking
                 addBooking();

                 //add Language
                 addLanguages();


             }

    private void addLanguages() {
        languages.add(new Language("Hindi"));
        languages.add(new Language("English"));
        languages.forEach(language ->languageService.acceptLanguageDetails(language) );
    }

    private void addBooking() throws MoiveTheatreDetailsNotFoundException, UserDetailsNotFoundException, MovieTheatreDetailsNotFoundException {
        booking1.setBookingDate(LocalDateTime.of(2019, 1, 8, 0, 10));
        booking1.setUser(user1);
        booking1.setNoOfSeats(150);
        booking1.setMovieTheatre(movieTheatre1);
        bookingService.acceptBookingDetails(booking1);
    }

    private void addMovieTheatre() throws MovieDetailNotFoundException, MoiveTheatreDetailsNotFoundException, TheatreDetailsNotFoundException {
        movieTheatre1.setMovie(movie1);
        movieTheatre1.setTheatre(theatre2);
        movieTheatreService.acceptMovieTheatreDetails(movieTheatre1);
    }

    private void addTheatres() {
        theatre1.setTheatreName("PVR");
        theatre1.setCity(cities.get(0));
        theatre1.setTicketPrice(500);
        theatreService.acceptTheatre(theatre1);

        theatre2.setTheatreName("Kanak");
        theatre2.setTicketPrice(800);
        theatre2.setCity(cities.get(1));
        theatreService.acceptTheatre(theatre2);
    }

    private void addCustomer() throws UserNameAlreadyExistsException, UserTypeDetailsNotFoundException {

        user1.setUserName("User1");
        user1.setFirstName("anand");
        user1.setLastname("bharti");
        user1.setDateOfBirth(LocalDateTime.of(2000,1,12,0,0));
        user1.setPassword("12345");
        user1.setUserType(userTypes.get(0));
        userService.acceptUserDetails(user1);
    }

    private void createMovie() {

        movie1.setMovieName("Movie1_Name");
        movie1.setTrailerUrl("Movie_T_URL");
        movie1.setStatus(statuses.get(1));
        movie1.setMovieDescription("Movie1 description");
        movie1.setDuration(120);
        movie1.setCoverPhotoUrl("Movie1_CoverUrl");
        movie1.setReleaseDate(LocalDateTime.of(2018,4,27,5,30));
        movieService.acceptMovieDetails(movie1);

          movie2.setMovieName("Avengers: Endgame");
    movie2.setMovieDescription("After Thanos, an intergalactic warlord, disintegrates half of " +
        "the universe, the Avengers must reunite and assemble again to reinvigorate their " +
        "trounced allies and restore balance.");
    movie2.setReleaseDate(LocalDateTime.of(2019, 4, 26, 5, 30));
    movie2.setDuration(180);
    movie2.setCoverPhotoUrl("cover-photo-url");
    movie2.setTrailerUrl("trailer-url");
    movie2.setStatus(statuses.get(1));
    movie2 = movieService.acceptMovieDetails(movie2);
    }

    private void createStatuses() {

        statuses.add(new Status("UPCOMING"));
        statuses.add(new Status("RELEASED"));
        statuses.add(new Status("BLOCKED"));
        statuses.forEach(status -> statusService.acceptStatusDetails(status));
    }

    private void createUserTypes() {

        userTypes.add(new UserType("Customer"));
        userTypes.add(new UserType("Admin"));
        userTypes.forEach(userType-> userTypeDao.save(userType));
    }

    private void createCities() {

        cities.add(new City("Patna"));
        cities.add(new City("Bangalore"));
        cities.add(new City("Kolkata"));
        cities.add(new City("Mumbai"));
        cities.forEach(city -> cityService.acceptCityDetails(city));
    }
}
