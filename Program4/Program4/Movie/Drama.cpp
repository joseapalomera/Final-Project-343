//
//  Drama.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Drama.h"

Drama::Drama(int stock, string director, string title, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
    setMovieType('D');
}

Drama::~Drama()
{
    
}

bool Drama::operator==(const Drama& d)const
{
    return true;
}

bool Drama::operator!=(const Drama& d)const
{
     return true;
}
bool Drama::operator>(const Drama& d) const
{
     return true;
}
bool Drama::operator<(const Drama& d) const
{
     return true;
}
