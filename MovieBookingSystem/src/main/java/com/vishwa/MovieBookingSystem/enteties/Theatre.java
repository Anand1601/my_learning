package com.vishwa.MovieBookingSystem.enteties;

import com.fasterxml.jackson.annotation.JsonManagedReference;

import javax.persistence.*;
import java.util.List;
import java.util.Set;

@Entity
public class Theatre {
    @Id
    @GeneratedValue
    private int theatreId;

   @Column(length = 20, nullable = false, unique = true)
    private String theatreName;

   @Column(nullable = false)
    private float ticketPrice=150.00f;

//creating ManyToOne relationship of Theatre with City (note it does not create relationship of City to theatre)
@ManyToOne
@JoinColumn(name = "City_Id",nullable = false)
@JsonManagedReference
private City city;



    public City getCity() {
        return city;
    }

    public void setCity(City city) {
        this.city = city;
    }


    public int getTheatreId() {
        return theatreId;
    }

    public void setTheatreId(int theatreId) {
        this.theatreId = theatreId;
    }

    public String getTheatreName() {
        return theatreName;
    }

    public void setTheatreName(String theatreName) {
        this.theatreName = theatreName;
    }

    public float getTicketPrice() {
        return ticketPrice;
    }

    public void setTicketPrice(float ticketPrice) {
        this.ticketPrice = ticketPrice;
    }

    @Override
    public String toString() {
        return "Theatre{" +
                "theatreId=" + theatreId +
                ", theatreName='" + theatreName + '\'' +
                ", ticketPrice=" + ticketPrice +
                '}';
    }
}
