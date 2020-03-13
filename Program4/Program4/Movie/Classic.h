//
//  Classic.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Classic_h
#define Classic_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
    //Constructors
    Classic();
    Classic(int stock, string director, string title, string majorActor,int releaseMonth, int releaseYear);
    ~Classic();
    
    //Setters
    void setData(ifstream &file);
    void setMajorActor(string majorActor);
    bool setReleaseMonth(int month);
    
    //Getters
    string getMajorActor()const;
    int getReleaseMonth()const;
    
    void display();
    
    //Operator overloads
    bool operator==(const Movie& c) const;
    bool operator!=(const Movie& c) const;
    bool operator>(const Movie& c) const;
    bool operator<(const Movie& c) const;
    Movie* operator=(const Movie& c);
    
private:
    //Variables that store the additional information a Classic
    //movie object has
    string majorActor;
    int releaseMonth;
    
};

#endif /* Classic_h */
