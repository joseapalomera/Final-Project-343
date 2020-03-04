//
//  Comedy.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Comedy.h"

Comedy::Comedy(int stock, string director, string title, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
    setMovieType('F');
}

Comedy::~Comedy()
{
    
}

bool Comedy::operator==(const Comedy& f)const
{
    return true;
}

bool Comedy::operator!=(const Comedy& f)const
{
     return true;
}
bool Comedy::operator>(const Comedy& f) const
{
     return true;
}
bool Comedy::operator<(const Comedy& f) const
{
     return true;
}
