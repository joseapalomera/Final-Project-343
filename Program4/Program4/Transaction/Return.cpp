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
    
}

Return::Return(int customerID, Movie *movie)
{
    setCustomerID(customerID);
    setMovie(movie);
}

Return::~Return()
{
    
}
