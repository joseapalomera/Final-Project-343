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
    this->movieType = movieType;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear;
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

bool Movie::operator==(const Movie& m) const
{
    if ((movieType == m.movieType) && (stock == m.stock) && (director == m.director) && (title == m.title) && (releaseYear == m.releaseYear))
    {
        return true;
    }
    
    return false;
}

bool Movie::operator!=(const Movie& m)const
{
    return !(*this == m);
}

bool Movie::operator>(const Movie& m) const // need to complete
{
    return false;
}

bool Movie::operator<(const Movie& m) const // need to complete
{
    return false;
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
