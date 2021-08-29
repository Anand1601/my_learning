package com.vishwa.MovieBookingSystem;

import com.sun.istack.NotNull;
import com.vishwa.MovieBookingSystem.Services.InitService;
import com.vishwa.MovieBookingSystem.Services.MovieService;
import com.vishwa.MovieBookingSystem.dao.MovieDao;
import com.vishwa.MovieBookingSystem.dao.StatusDao;
import com.vishwa.MovieBookingSystem.enteties.Movie;
import com.vishwa.MovieBookingSystem.enteties.Status;
import com.vishwa.MovieBookingSystem.exceptions.MovieDetailNotFoundException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;

import java.time.LocalDateTime;
import java.util.List;


@SpringBootApplication
public class  MovieBookingSystemApplication {

	/**
	* we need the logger object
	 * we're going to use factory design pattern for logging
	*/
	 private static final Logger LOGGER = LoggerFactory.getLogger(MovieBookingSystemApplication.class);

	public static void main(String[] args) {

		/*
		return type of  SpringApplication.run(MovieBookingSystemApplication.class, args);
		is application context
		 */
		ApplicationContext ctx= SpringApplication.run(MovieBookingSystemApplication.class, args);
		System.out.println("Hello spring");

      LOGGER.debug("writing for debug");
      LOGGER.info("writing for info");
      LOGGER.warn("writing for warning");
      LOGGER.error("writing for warning");


	}

	/*
	* this is the way to execute something in the very beginning when application is starting up
	* */


	@Bean
	CommandLineRunner init(InitService initService){
		return args -> {
			initService.init();
		};
	}



}
