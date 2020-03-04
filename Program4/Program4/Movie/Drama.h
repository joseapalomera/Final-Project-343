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
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
    Drama(int stock, string director, string title, int releaseYear);
    ~Drama();
    
    bool operator==(const Drama& d)const;
    bool operator!=(const Drama& d)const;
    bool operator>(const Drama& d) const;
    bool operator<(const Drama& d) const;
    
};
#endif /* Drama_h */
