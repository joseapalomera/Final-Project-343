//
//  Borrow.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
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
    movie = NULL;
}

void Borrow::doTrans()
{
    movie->decreaseStock();
}

void Borrow::display() const
{
    cout << "Borrowed: ";
    movie->display();
}

