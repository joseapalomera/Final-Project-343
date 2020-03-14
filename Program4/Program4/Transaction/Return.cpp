//
//  Return.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Return.h"

Return::Return()
{
    setTransactionType('R');
}

Return::Return(int customerID, Movie *movie)
{
    setTransactionType('R');
    setCustomerID(customerID);
    setMovie(movie);
}

Return::~Return()
{
    this->movie = nullptr;
}

void Return::doTrans()
{
    this->movie->increaseStock();
}

void Return::display()const
{
    cout << "Returned: ";
    //If the movie type for the return object is C
    //then we must print out the details for the Classic movie
    if(this->movie->getMovieType() == 'C')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getMajorActor() << " "
        << this->movie->getReleaseMonth() << " " << this->movie->getReleaseYear() << endl;
    }
    //Else if the movie type for the return object is F
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
