//
//  Movie.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Movie.h"

Movie::Movie()
{
    setMovieType('M');
}

Movie::Movie(char movieType, int stock, string director, string title, int releaseYear)
{
    setMovieType(movieType);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

void Movie::setData(ifstream &file)
{
    int stock, releaseYear;
    string director, title;
    
    file.ignore(1);
    file >> stock;
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

Movie::~Movie(){}

void Movie::setMovieType(char movieType)
{
    this->movieType = movieType;
}

void Movie::setStock(int stock)
{
    this->stock = stock;
}

void Movie::setDirector(string director)
{
    this->director = director;
}

void Movie::setTitle(string title)
{
    this->title = title;
}

void Movie::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

//Method implemented here so that the Classic object
//can overload it
void Movie::setMajorActor(string majorActor){}

bool Movie::setReleaseMonth(int month)
{
    //If the month is out of the range
    if(month < 1 || month >= 13)
    {
        //Inform the business of the invalid month
        cerr << "ERROR: Invalid month" <<endl;
        return false;
    }
    
    return true;
}

char Movie::getMovieType() const
{
    return movieType;
}

int Movie::getStock() const
{
    return stock;
}

string Movie::getDirector() const
{
    return director;
}

string Movie::getTitle() const
{
    return title;
}

int Movie::getReleaseYear( )const
{
    return releaseYear;
}

string Movie::getMajorActor()const
{
    return NULL;
}

int Movie::getReleaseMonth()const
{
    return NULL;
}

bool Movie::increaseStock()
{
    //Increases the stock of a movie by 1
    stock++;
    return true;
}

bool Movie::decreaseStock()
{
    //Checks to see if the movie is able to decrease stock
    if(stock == 0)
    {
        return false;
    }
    
    //If yes, then the stock decreases by 1
    stock--;
    return true;
}

Movie* Movie::operator=(const Movie &c)
{
    return this;
}

void Movie::display()const
{
    //Displays the movie's credentials
    cout << getMovieType() << ", " << getStock() << ", " << getDirector()
    << ", " << getTitle() << ", " << getReleaseYear() << endl;
}

