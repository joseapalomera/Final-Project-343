//
//  Drama.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Drama.h"

Drama::Drama(int stock, string director, string title, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
    setMovieType('D');
}

Drama::~Drama()
{
    
}

bool Drama::operator==(const Drama& d)const
{
    if(this->getDirector() == d.getDirector())
    {
        if(this->getTitle() == d.getTitle())
        {
            if(this->getReleaseYear() == d.getReleaseYear())
            {
                return true;
            }
        }
    }
    
    return false;
}

bool Drama::operator!=(const Drama& d)const
{
     return !(*this == d);
}
bool Drama::operator>(const Drama& d) const
{
    if(this->getDirector() > d.getDirector())
    {
        return true;
    }
    else if(this->getDirector() < d.getDirector()){
        return false;
    }
    else{
        //If the directors of the Dramas are the same, we then check to see if the title is different
        if(this->getTitle() > d.getTitle())
        {
            return true;
        }
        else if(this->getTitle() < d.getTitle())
        {
            return false;
        }
        
        //If the function reaches here, this means the Dramas are equal
        return false;
    }
}
bool Drama::operator<(const Drama& d) const
{
     if(this->getDirector() < d.getDirector())
     {
         return true;
     }
     else if(this->getDirector() > d.getDirector())
     {
         return false;
     }
     else{
         //If the directors of the Dramas are the same, we then check to see if the title is different
         if(this->getTitle() < d.getTitle())
        {
            return true;
        }
        else if(this->getTitle() > d.getTitle())
        {
            return false;
        }
     
         //If the function reaches here, this means the Comedies are equal
         return false;
     }
}
