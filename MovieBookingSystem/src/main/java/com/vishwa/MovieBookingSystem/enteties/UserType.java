package com.vishwa.MovieBookingSystem.enteties;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
@Entity
public class UserType {
    @Id
    @GeneratedValue
    private int userTypeId;

    @Column(length = 20,unique = true)
    private String userTypeName="customer";

    public UserType() {
  }

  public UserType(String userTypeName) {
    this.userTypeName = userTypeName;
  }

    public int getUserTypeId() {
        return userTypeId;
    }

    public void setUserTypeId(int userTypeId) {
        this.userTypeId = userTypeId;
    }

    public String getUserTypeName() {
        return userTypeName;
    }

    public void setUserTypeName(String userTypeName) {
        this.userTypeName = userTypeName;
    }

    @Override
    public String toString() {
        return "UserType{" +
                "userTypeId=" + userTypeId +
                ", userTypeName='" + userTypeName + '\'' +
                '}';
    }
}
