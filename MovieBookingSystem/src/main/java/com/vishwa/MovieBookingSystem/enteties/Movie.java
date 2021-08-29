package com.vishwa.MovieBookingSystem.enteties;

import org.codehaus.plexus.classworlds.strategy.Strategy;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.List;

@Entity
@Table(name = "movie")
public class Movie {
    /*this indicates that movieId is primary key
   ** there are two different way to give primary key(it should be unique)
   * 1. give it yourself: but this is very risky because chances of duplicate is very much possible
   * 2.lets handle this database it self: always preferred way.
   *we can do this using GeneratedValue();
     */
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private int movieId;

    @Column(length = 25,nullable = false,unique = true)
    private String movieName;

    @Column(name = "movie_des",length = 500,nullable = false)
    private String movieDescription;

    @Column(nullable = false)
    private int duration;

    @Column(nullable=false)
    private LocalDateTime releaseDate;

    @Column(length = 500,nullable = false)
    private String coverPhotoUrl;

    @Column(length = 500,nullable = false)
    private String trailerUrl;



    @ManyToOne
    @JoinColumn(name="status_id",nullable = false)
    private Status status;

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }



    public int getMovieId() {
        return movieId;
    }

    public void setMovieId(int movieId) {
        this.movieId = movieId;
    }

    public String getMovieName() {
        return movieName;
    }

    public void setMovieName(String movieName) {
        this.movieName = movieName;
    }

    public String getMovieDescription() {
        return movieDescription;
    }

    public void setMovieDescription(String movieDescription) {
        this.movieDescription = movieDescription;
    }

    public LocalDateTime getReleaseDate() {
        return releaseDate;
    }

    public void setReleaseDate(LocalDateTime releaseDate) {
        this.releaseDate = releaseDate;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public String getCoverPhotoUrl() {
        return coverPhotoUrl;
    }

    public void setCoverPhotoUrl(String coverPhotoUrl) {
        this.coverPhotoUrl = coverPhotoUrl;
    }

    public String getTrailerUrl() {
        return trailerUrl;
    }

    public void setTrailerUrl(String trailerUrl) {
        this.trailerUrl = trailerUrl;
    }

    @Override
    public String toString() {
        return "Movie{" +
                "movieId=" + movieId +
                ", movieName='" + movieName + '\'' +
                ", movieDescription='" + movieDescription + '\'' +
                ", releaseDate=" + releaseDate +
                ", duration=" + duration +
                ", coverPhotoUrl='" + coverPhotoUrl + '\'' +
                ", trailerUrl='" + trailerUrl + '\'' +
                ", status=" + status +
                '}';
    }
}
