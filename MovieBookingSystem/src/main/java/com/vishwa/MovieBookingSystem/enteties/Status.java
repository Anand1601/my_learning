package com.vishwa.MovieBookingSystem.enteties;

import javax.annotation.processing.Generated;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
@Entity
public class Status {
    @Id
    @GeneratedValue
    private int statusId;

    @Column(length = 20,nullable = false,unique = true)
    private String statusName;

     public Status() {
  }

  public Status( String statusName) {
    this.statusName = statusName;
  }

    public int getStatusId() {
        return statusId;
    }

    public void setStatusId(int statusId) {
        this.statusId = statusId;
    }

    public void setStatusName(String statusName) {
        this.statusName = statusName;
    }

    public String getStatusName()
    {
        return statusName;
    }

    @Override
    public String toString() {
        return "Status{" +
                "statusId=" + statusId +
                ", statusName='" + statusName + '\'' +
                '}';
    }
}
