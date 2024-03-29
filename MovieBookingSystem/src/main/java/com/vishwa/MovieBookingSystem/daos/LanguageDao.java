package com.vishwa.MovieBookingSystem.daos;

import com.vishwa.MovieBookingSystem.enteties.Language;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface LanguageDao extends JpaRepository<Language,Integer> {

     Optional<Language> findByLanguageName(String languageName);

}
