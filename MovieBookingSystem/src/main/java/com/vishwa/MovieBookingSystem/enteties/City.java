package com.vishwa.MovieBookingSystem.enteties;

import com.fasterxml.jackson.annotation.JsonBackReference;

import javax.persistence.*;
import java.util.Objects;
import java.util.Set;

@Entity
public class City {
    @Id
    @GeneratedValue
    private int cityId;

@Column(length = 20,nullable = false)
    private String cityName;

//to establish relationship of City with theatres
    @OneToMany(mappedBy = "city",fetch = FetchType.EAGER)
    @JsonBackReference
    private Set<Theatre> theatre;

    public Set<Theatre> getTheatre() {
        return theatre;
    }

    public void setTheatre(Set<Theatre> theatre) {
        this.theatre = theatre;
    }

    public City(){}

    public City(int cityId,String cityName)
    {
        this.cityId=cityId;
        this.cityName=cityName;
    }

    public City(String cityName){
       this.cityName=cityName;
    }

    public int getCityId() {
        return cityId;
    }

    public String getCityName() {
        return cityName;
    }

    public void setCityId(int cityId) {
        this.cityId = cityId;
    }

    public void setCityName(String cityName) {
        this.cityName = cityName;
    }

    @Override
    public String toString() {
        return "City{" +
                "cityId=" + cityId +
                ", cityName='" + cityName + '\'' +
                ", theatre=" + theatre +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        City city = (City) o;
        return Objects.equals(cityName, city.cityName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(cityName);
    }
}
