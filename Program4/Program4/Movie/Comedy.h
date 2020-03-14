//
//  Comedy.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Comedy_h
#define Comedy_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
    //Constructors
    Comedy();
    Comedy(int stock, string director, string title, int releaseYear);
    ~Comedy();
    
    //Setter
    void setData(ifstream &file);
    
    void display();
    
    //Operator overloads
    bool operator==(const Movie& d) const;
    bool operator!=(const Movie& d) const;
    bool operator>(const Movie& d) const;
    bool operator<(const Movie& d) const;
    Movie* operator=(const Movie& d);
};
#endif /* Comedy_h */
