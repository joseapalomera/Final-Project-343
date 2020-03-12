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
    
}

Borrow::Borrow(int customerID, Movie *movie)
{
    setCustomerID(customerID);
    setMovie(movie);
}

Borrow::~Borrow()
{
    
}
