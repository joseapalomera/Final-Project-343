//
//  Return.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
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
    movie = NULL;
}

void Return::doTrans()
{
    movie->increaseStock();
}

void Return::display() const
{
    cout << "Returned: ";
    movie->display();
}
