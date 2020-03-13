//
//  Drama.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Drama_h
#define Drama_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
    //Constructors
    Drama();
    Drama(int stock, string director, string title, int releaseYear);
    ~Drama();
    
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
#endif /* Drama_h */
