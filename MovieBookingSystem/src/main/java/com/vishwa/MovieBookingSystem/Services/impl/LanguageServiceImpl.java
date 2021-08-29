package com.vishwa.MovieBookingSystem.Services.impl;

import com.vishwa.MovieBookingSystem.Services.LanguageService;
import com.vishwa.MovieBookingSystem.dao.LanguageDao;
import com.vishwa.MovieBookingSystem.enteties.Language;
import com.vishwa.MovieBookingSystem.exceptions.LanguageDetailsNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LanguageServiceImpl implements LanguageService {

    @Autowired
    LanguageDao languageDao;

    @Override
    public Language acceptLanguageDetails(Language language) {
        return languageDao.save(language);
    }

    @Override
    public Language getLanguageDetails(int id) throws LanguageDetailsNotFoundException {
        return languageDao.findById(id).orElseThrow(()->new LanguageDetailsNotFoundException("language not found by the id:"+id));
    }

    @Override
    public Language getLanguageDetailsByLanguageName(String languageName) throws LanguageDetailsNotFoundException {
        return languageDao.findByLanguageName(languageName).orElseThrow(()->new LanguageDetailsNotFoundException("Language not found by the languageName:"+languageName));
    }

    @Override
    public boolean deleteLanguage(int id) throws LanguageDetailsNotFoundException {
        Language savedLanguage=getLanguageDetails(id);
        languageDao.delete(savedLanguage);
    return true;
    }

    @Override
    public List<Language> getAllLanguageDetails() {
        return languageDao.findAll();
    }
}
