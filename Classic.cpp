//
//  Classic.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Classic.h"

Classic::Classic()
{
    setMovieType('C');
}


Classic::~Classic()
{
    
}

void Classic::setData(ifstream &file)
{
    int stock, releaseMonth, releaseYear;
    string director, title, firstName, lastName;
    
    file.ignore(1);
    file >> stock;
    file.ignore(1);
    getline(file, director, ',');
    getline(file, title, ',');
    file >> firstName >> lastName >> releaseMonth >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(firstName, lastName);
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
}

void Classic::setMajorActor(string firstName, string lastName)
{
    this->actorFirstName = firstName;
    this->actorLastName = lastName;
}

string Classic::getMajorActor()const
{
    return this->actorFirstName + " " +  this->actorLastName + " ";
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

ostream& operator<<(ostream &os, const Classic &other)
{
    os << other.getMovieType() << ", ";
    os << other.getStock() << ",";
    os << other.getDirector() << ",";
    os << other.getTitle() << ", ";
    os << other.getMajorActor();
    os << other.getReleaseMonth() << " ";
    os << other.getReleaseYear() << endl;
    
    return os;
}
