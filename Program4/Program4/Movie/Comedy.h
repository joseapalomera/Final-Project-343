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
    friend ostream& operator<<(ostream &os, const Comedy *f);
    
public:
    Comedy();
    Comedy(int stock, string director, string title, int releaseYear);
    ~Comedy();
    
    void setData(ifstream &file);
    bool operator==(const Comedy& f)const;
    bool operator!=(const Comedy& f)const;
    bool operator>(const Comedy& f) const;
    bool operator<(const Comedy& f) const;
    
};
#endif /* Comedy_h */
