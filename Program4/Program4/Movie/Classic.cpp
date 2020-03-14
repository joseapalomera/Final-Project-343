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

Classic::Classic(int stock, string director, string title, string majorActor, int releaseMonth,  int releaseYear)
{
    setMovieType('C');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
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
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> firstName >> lastName >> releaseMonth >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor((firstName + " " + lastName));
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
}

void Classic::setMajorActor(string majorActor)
{
    this->majorActor = majorActor;
}

string Classic::getMajorActor()const
{
    return this->majorActor;
}

bool Classic::setReleaseMonth(int month)
{
    //if the month is out of range
    if(month < 1 || month >= 13)
    {
        //Inform the business of the invalid month
        cerr << "ERROR: Invalid month " << month << endl;
        return false;
    }
    
    this->releaseMonth = month;
    return true;
}

int Classic::getReleaseMonth()const
{
    return this->releaseMonth;
}

bool Classic::operator==(const Movie& cla)const
{
    //If both stocks are the same
    if(getStock() == cla.getStock())
    {
        //If both directors are the same
        if(getDirector().compare(cla.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(cla.getTitle()) == 0)
            {
                //If both release months are the same
                if(getReleaseMonth() == cla.getReleaseMonth())
                {
                    //If both release years are the same
                    if(getReleaseYear() == cla.getReleaseYear())
                    {
                        //If both major actors are the same
                        if(getMajorActor().compare(cla.getMajorActor()) == 0)
                        {
                            //Return true if all the variables are equal
                            return true;
                        }
                    }
                }
            }
        }
    }
    //Return false if one of the variables are different
    return false;
}

bool Classic::operator!=(const Movie& cla)const
{
     return !(*this == cla);
}

bool Classic::operator>(const Movie& cla) const
{
    //If the current release year is greater than the other movie
    if (getReleaseYear() > cla.getReleaseYear())
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current release year is equal to the other movie
    else if (getReleaseYear() == cla.getReleaseYear())
    {
        //If so, check the release months and see if the current month is greater
        if (getReleaseMonth() > cla.getReleaseMonth())
        {
            //If so, return true
            return true;
        }
        //Otherwise, check the release months and see if they are equal
        else if (getReleaseMonth() == cla.getReleaseMonth())
        {
            //If equal, compare the major actor's names
            if (getMajorActor().compare(cla.getMajorActor()) > 0)
            {
                //Return true if the current Classic is greater than the other one
                return true;
            }
            else
            {
                //Return false if the current major actor is less than the other one
                return false;
            }
        }
        else
        {
            //Return false if the current release month is less
            return false;
        }
    }
    else
    {
        //Return false if the current release year is less
        return false;
    }
}

bool Classic::operator<(const Movie& cla) const
{
    //If the current release year is less than the other movie
     if (getReleaseYear() < cla.getReleaseYear())
     {
         //Return true
         return true;
     }
    //Otherwise, check to see if the current release year is equal to the other movie
     else if (getReleaseYear() == cla.getReleaseYear())
     {
         //If so, check the release months and see if the current month is less
         if (getReleaseMonth() < cla.getReleaseMonth())
         {
             //If so, return true
             return true;
         }
         //Otherwise, check the release months and see if they are equal
         else if (getReleaseMonth() == cla.getReleaseMonth())
         {
             //If equal, compare the major actor's names
             if (getMajorActor().compare(cla.getMajorActor()) < 0)
             {
                 //Return true if the current Classic is less than the other one
                 return true;
             }
             else
             {
                 //Return false if the current major actor is greater than the other one
                 return false;
             }
         }
         else
         {
             //Return false if the current release month is greater
             return false;
         }
     }
     else
     {
         //Return false if the current release year is greater
         return false;
     }
}

Movie* Classic::operator=(const Movie &c)
{
    //Replaces the current Classic movie
    //with new information from a different movie
    setStock(c.getStock());
    setDirector(c.getDirector());
    setTitle(c.getTitle());
    setMajorActor(c.getMajorActor());
    setReleaseMonth(c.getReleaseMonth());
    setReleaseYear(c.getReleaseYear());
    
    return this;
}

void Classic::display()
{
    //Displays the Classic movie object's credentials
    cout << getMovieType() << ", " << getStock()
    << ", " << getDirector() << ", " << getTitle()
    << ", " << getMajorActor() << " " << getReleaseMonth()
    << " " << getReleaseYear() << endl;
}
