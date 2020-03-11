//
//  Comedy.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Comedy.h"

Comedy::Comedy()
{
    setMovieType('F');
}

Comedy::~Comedy()
{
    
}

void Comedy::setData(ifstream &file)
{
    file.ignore(1);
    file >> stock;
    file.ignore(1);
    getline(file, director, ',');
    getline(file, title, ',');
    file >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

bool Comedy::operator==(const Comedy& f)const
{
    if(this->getDirector() == f.getDirector())
    {
        if(this->getTitle() == f.getTitle())
        {
            if(this->getReleaseYear() == f.getReleaseYear())
            {
                return true;
            }
        }
    }
    return false;
}

bool Comedy::operator!=(const Comedy& f)const
{
     return !(*this == f);
}
bool Comedy::operator>(const Comedy& f) const
{
    if(this->getTitle() > f.getTitle())
    {
        return true;
    }
    else if(this->getTitle() < f.getTitle())
    {
        return false;
    }
    else
    {
        //If the titles of the Comedies are the same, we then check to see if the year is different
        if(this->getReleaseYear() > f.getReleaseYear())
        {
            return true;
        }
        else if(this->getReleaseYear() < f.getReleaseYear())
        {
            return false;
        }
    
        //If the function reaches here, this means the Comedies are equal
        return false;
    }
    
}

bool Comedy::operator<(const Comedy& f) const
{
    if(this->getTitle() < f.getTitle())
    {
        return true;
    }
    else if(this->getTitle() > f.getTitle())
    {
        return false;
    }
    else
    {
        //If the titles of the Comedies are the same, we then check to see if the year is different
        if(this->getReleaseYear() < f.getReleaseYear())
        {
            return true;
        }
        else if(this->getReleaseYear() > f.getReleaseYear())
        {
            return false;
        }
    
        //If the function reaches here, this means the Comedies are equal
        return false;
    }
}

ostream& operator<<(ostream &os, const Comedy &other)
{
    os << other.getMovieType() << ", ";
    os << other.getStock() << ",";
    os << other.getDirector() << ",";
    os << other.getTitle() << ", ";
    os << other.getReleaseYear() << endl;
    
    return os;
}
