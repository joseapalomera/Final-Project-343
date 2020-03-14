//
//  Comedy.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Comedy.h"

Comedy::Comedy()
{
    setMovieType('F');
}

Comedy::Comedy(int stock, string director, string title, int releaseYear)
{
    setMovieType('F');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

Comedy::~Comedy()
{
    
}

void Comedy::setData(ifstream &file)
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

bool Comedy::operator==(const Movie& fun)const
{
    //If both stocks are the same
    if(getStock() == fun.getStock())
    {
        //If both directors are the same
        if(getDirector().compare(fun.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(fun.getTitle()) == 0)
            {
                //If both release years are the same
                if(getReleaseYear() == fun.getReleaseYear())
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

bool Comedy::operator!=(const Movie& fun)const
{
     return !(*this == fun);
}

bool Comedy::operator>(const Movie& fun) const
{
    //If the current title is greater than the other movie
    if(getTitle().compare(fun.getTitle()) > 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current title is equal to the other movie
    else if(getTitle().compare(fun.getTitle()) == 0)
    {
        //If so, check to see if the current release year is greater than the other movie
        if(getReleaseYear() > fun.getReleaseYear())
        {
            //If so, return true;
            return true;
        }
        else
        {
            //Return false if the current release year is not greater
            return false;
        }
    }
    else
    {
        //Return false if the current title is less than the other movie
        return false;
    }
}

bool Comedy::operator<(const Movie& fun) const
{
    //If the current title is less than the other movie
    if(getTitle().compare(fun.getTitle()) < 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current title is equal to the other movie
    else if(getTitle().compare(fun.getTitle()) == 0)
    {
        //If so, check to see if the current release year is less than the other movie
        if(getReleaseYear() < fun.getReleaseYear())
        {
            //If so, return true;
            return true;
        }
        else
        {
            //Return false if the current release year is not less
            return false;
        }
    }
    else
    {
        //Return false if the current title is greater than the other movie
        return false;
    }
}

Movie* Comedy::operator=(const Movie &f)
{
    setStock(f.getStock());
    setDirector(f.getDirector());
    setTitle(f.getTitle());
    setReleaseYear(f.getReleaseYear());
    
    return this;
}

void Comedy::display()
{
    //Displays the credentials of a Comedy movie
    cout << getMovieType() << ", " << getStock() << ", "
    << getDirector() << ", " << getTitle() << ", " << getReleaseYear() << endl;
}
