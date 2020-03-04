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
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
    
public:
    Classic(int stock , string director, string title, string majorActor, int releaseMonth, int releaseYear);
    ~Classic();
    
    void setMajorActor(string actor);
    string getMajorActor()const;
    
    void setReleaseMonth(int month);
    int getReleaseMonth()const;
    
    bool operator==(const Classic& c)const;
    bool operator!=(const Classic& c)const;
    bool operator>(const Classic& c) const;
    bool operator<(const Classic& c) const;
    
private:
    string majorActor;
    int releaseMonth;
    
};

#endif /* Classic_h */
