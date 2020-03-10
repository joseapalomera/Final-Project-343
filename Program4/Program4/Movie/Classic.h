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
    friend ostream& operator<<(ostream &os, const Classic &c);
    
public:
    Classic();
    ~Classic();
    
    void setData(ifstream &file);
    
    void setMajorActor(string firstName, string lastName);
    string getMajorActor()const;
    
    void setReleaseMonth(int month);
    int getReleaseMonth()const;
    
    bool operator==(const Classic& c)const;
    bool operator!=(const Classic& c)const;
    bool operator>(const Classic& c) const;
    bool operator<(const Classic& c) const;
    
    void display();
    
private:
    string actorFirstName;
    string actorLastName;
    int releaseMonth;
    
};

#endif /* Classic_h */
