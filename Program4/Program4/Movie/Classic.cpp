//
//  Classic.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Classic.h"

Classic::Classic(int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
    setMovieType('C');
}

Classic::~Classic()
{
    
}

void Classic::setMajorActor(string actor)
{
    this->majorActor = actor;
}

string Classic::getMajorActor()const
{
    return this->majorActor;
}

void Classic::setReleaseMonth(int month)
{
    this->releaseMonth = month;
}

int Classic::getReleaseMonth()const
{
    return this->releaseMonth;
}

bool Classic::operator==(const Classic& c)const
{
    if(this->getDirector() == c.getDirector())
    {
        if(this->getTitle() == c.getTitle())
        {
            if(this->getReleaseYear() == c.getReleaseYear())
            {
                if(this->getReleaseMonth() == c.getReleaseMonth())
                {
                    if(this->getMajorActor() == c.getMajorActor())
                    {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

bool Classic::operator!=(const Classic& c)const
{
     return !(*this == c);
}

bool Classic::operator>(const Classic& c) const
{
    if(this->getReleaseYear() > c.getReleaseYear())
    {
        return true;
    }
    else if(this->getReleaseYear() < c.getReleaseYear())
    {
        return false;
    }
    else
    {
        if(this->getReleaseMonth() > c.getReleaseMonth())
        {
            return true;
        }
        else if(this->getReleaseMonth() < c.getReleaseMonth())
        {
            return false;
        }
        else{
            if(this->getMajorActor() > c.getMajorActor())
            {
                return true;
            }
            else if(this->getMajorActor() < c.getMajorActor())
            {
                return false;
            }
            
            return false;
        }
    }
}
bool Classic::operator<(const Classic& c) const
{
     if(this->getReleaseYear() < c.getReleaseYear())
     {
         return true;
     }
     else if(this->getReleaseYear() > c.getReleaseYear())
     {
         return false;
     }
     else
     {
         if(this->getReleaseMonth() < c.getReleaseMonth())
         {
             return true;
         }
         else if(this->getReleaseMonth() > c.getReleaseMonth())
         {
             return false;
         }
         else{
             if(this->getMajorActor() < c.getMajorActor())
             {
                 return true;
             }
             else if(this->getMajorActor() > c.getMajorActor())
             {
                 return false;
             }
             
             return false;
         }
     }
}
