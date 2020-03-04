//
//  Classic.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Classic.h"

Classic::Classic(int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
    setMovieType('C');
}

Classic::~Classic()
{
    
}

void Classic::setMajorActor(string actor)
{
    this->majorActor = actor;
}

string Classic::getMajorActor()const
{
    return this->majorActor;
}

void Classic::setReleaseMonth(int month)
{
    this->releaseMonth = month;
}

int Classic::getReleaseMonth()const
{
    return this->releaseMonth;
}

bool Classic::operator==(const Classic& c)const
{
    return true;
}

bool Classic::operator!=(const Classic& c)const
{
     return true;
}
bool Classic::operator>(const Classic& c) const
{
     return true;
}
bool Classic::operator<(const Classic& c) const
{
     return true;
}
