//
//  Comedy.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Comedy.h"

Comedy::Comedy(int stock, string director, string title, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
    setMovieType('F');
}

Comedy::~Comedy()
{
    
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
