//
//  Borrow.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Borrow.h"

Borrow::Borrow()
{
    setTransactionType('B');
}

Borrow::Borrow(int customerID, Movie *movie)
{
    setTransactionType('B');
    setCustomerID(customerID);
    setMovie(movie);
}

Borrow::~Borrow()
{
    this->movie = nullptr;
}

void Borrow::doTrans()
{
    this->movie->decreaseStock();
}

void Borrow::display()const
{
    cout << "Borrowed: ";
    //If the movie type for the borrow object is C
    //then we must print out the details for the Classic movie
    if(this->movie->getMovieType() == 'C')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getMajorActor() << " "
        << this->movie->getReleaseMonth() << " " << this->movie->getReleaseYear() << endl;
    }
    //Else if the movie type for the borrow object is F
    //then we must print out the details for the Comedy movie
    else if(this->movie->getMovieType() == 'F')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getReleaseYear() << endl;
    }
    //If the other conditions never happened, then that means we have
    //a Drama movie left to print out the details
    else
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getReleaseYear() << endl;
    }
    
}
