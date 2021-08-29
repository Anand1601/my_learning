package com.vishwa.MovieBookingSystem.enteties;

import com.fasterxml.jackson.annotation.JsonBackReference;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.Set;

@Entity
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private int userId;

  @Column(name = "first_name", length = 20, nullable = false)
    private String firstName;

  @Column(length = 20)
    private String lastname;

  @Column(length = 20, nullable = false, unique = true)
    private String userName;

  @Column(length = 20, nullable = false)
    private String password;


    @Column(nullable = false)
    private LocalDateTime dateOfBirth;

    @OneToMany(mappedBy = "user",fetch = FetchType.EAGER,cascade = {CascadeType.ALL})
    @JsonBackReference
    private Set<Booking> bookings;

  //user can have more than one phone number
/*
* why we need @ElementCollection here: because in data base one grid can store only one element so if
  we want to store more than one elements we need a new table.
* @CollectionTable: as it is a collection table we use it to customise the collection table.
* joinColumns=@JoinColumn("name") : it is used to customise the primary key name of this table like user_id in this case
* @Column: to customise the column name for the new column like phoneNumber in this case
* */

@ElementCollection
@CollectionTable(name = "user_phone_number",joinColumns = @JoinColumn(name="user_id"))
@Column(name = "mobile_number",nullable = false)
    private Set<Integer> phoneNumbers;

@ManyToOne
@JoinColumn(name = "user_type_id",nullable = false)
private UserType userType;

@ManyToOne
@JoinColumn(name = "language_id")
private Language language;

    public Set<Booking> getBookings() {
        return bookings;
    }

    public void setBookings(Set<Booking> bookings) {
        this.bookings = bookings;
    }

    public Set<Integer> getPhoneNumbers() {
        return phoneNumbers;
    }

    public void setPhoneNumbers(Set<Integer> phoneNumbers) {
        this.phoneNumbers = phoneNumbers;
    }

    public UserType getUserType() {
        return userType;
    }

    public void setUserType(UserType userType) {
        this.userType = userType;
    }

    public Language getLanguage() {
        return language;
    }

    public void setLanguage(Language language) {
        this.language = language;
    }

    public int getUserId() {
        return userId;
     }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public LocalDateTime getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(LocalDateTime dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public Set<Integer> getPhoneNumber() {
        return phoneNumbers;
    }

    public void setPhoneNumber(Set<Integer> phoneNumber) {
        this.phoneNumbers = phoneNumber;
    }



    @Override
    public String toString() {
        return "User{" +
                "userId=" + userId +
                ", firstName='" + firstName + '\'' +
                ", lastname='" + lastname + '\'' +
                ", userName='" + userName + '\'' +
                ", password='" + password + '\'' +
                ", dateOfBirth=" + dateOfBirth +
                ", phoneNumbers=" + phoneNumbers +
                '}';
    }
}
