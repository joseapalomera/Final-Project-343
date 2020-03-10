//
//  Movie.cpp
//  Program4
//
//  Created by Gurjepaul Brar on 3/3/20.
//  Copyright © 2020 Gurjepaul Brar. All rights reserved.
//

#include <stdio.h>
#include "Movie.h"

Movie::Movie()
{
    this->movieType = 0;
    this->stock = -1;
    this->director = "";
    this->title = "";
    this->releaseYear = -1;
}

Movie::Movie(char movieType, int stock, string director, string title, int releaseYear)
{
    setMovieType(movieType);
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

bool Movie::increaseStock()
{

    stock++;
    return true;
}

bool Movie::decreaseStock()
{
    if(stock == 0)
    {
        return false;
    }
    
    stock--;
    return true;
}

ostream& operator<<(ostream &os, const Movie &other)
{
    os << other.getMovieType() << ", ";
    os << other.getStock() << ", ";
    os << other.getDirector() << ", ";
    os << other.getTitle() << ", ";
    os << other.getReleaseYear() << endl;
    return os;
}

