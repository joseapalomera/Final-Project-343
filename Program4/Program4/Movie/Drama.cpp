//
//  Drama.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Drama.h"

Drama::Drama()
{
    setMovieType('D');
}

Drama::Drama(int stock, string director, string title, int releaseYear)
{
    setMovieType('D');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

Drama::~Drama()
{
    
}

void Drama::setData(ifstream &file)
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

bool Drama::operator==(const Movie& dram)const
{
    //If both stocks are the same
    if(getStock() == dram.getStock())
    {
         //If both directors are the same
        if(getDirector().compare(dram.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(dram.getTitle()) == 0)
            {
                //If both release years are the same
                if(getReleaseYear() == dram.getReleaseYear())
                {
                     //Return true if all the variables are equal
                    return true;
                }
            }
        }
    }
    //Return false if one of the variables are different
    return false;
}

bool Drama::operator!=(const Movie& dram)const
{
     return !(*this == dram);
}

bool Drama::operator>(const Movie& dram) const
{
    //If the current director is greater than the other movie
    if(getDirector().compare(dram.getDirector()) > 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current director is equal to the other movie
    else if(getDirector().compare(dram.getDirector()) == 0)
    {
        //If so, check to see if the current title is greater than the other movie
        if(getTitle().compare(dram.getTitle()) > 0)
        {
            //If so, return true;
            return true;
        }
        //If the the current title equals the other title
        else if(getTitle().compare(dram.getTitle()) == 0)
        {
            //Return false
            return false;
        }
        else
        {
            //Return false if the current title is less than the other one
            return false;
        }
    }
    else
    {
        //Return false if the current director is less than the other one
        return false;
    }
}

bool Drama::operator<(const Movie& dram) const
{
    //If the current director is less than the other movie
     if(getDirector().compare(dram.getDirector()) < 0)
     {
         //Return true
         return true;
     }
    //Otherwise, check to see if the current director is equal to the other movie
     else if(getDirector().compare(dram.getDirector()) == 0)
     {
         //If so, check to see if the current title is less than the other movie
         if(getTitle().compare(dram.getTitle()) < 0)
         {
             //If so, return true;
             return true;
         }
         //If the the current title equals the other title
         else if(getTitle().compare(dram.getTitle()) == 0)
         {
             //Return false
             return false;
         }
         else
         {
             //Return false if the current title is greater than the other one
             return false;
         }
     }
     else
     {
         //Return false if the current director is greater than the other one
         return false;
     }
}

Movie* Drama::operator=(const Movie &d)
{
    setStock(d.getStock());
    setDirector(d.getDirector());
    setTitle(d.getTitle());
    setReleaseYear(d.getReleaseYear());
    
    return this;
}

void Drama::display()
{
    //Displays the credentials of a Drama movie
    cout << getMovieType() << ", " << getStock() << ", "
    << getDirector() << ", " << getTitle() << ", " << getReleaseYear() << endl;
}
