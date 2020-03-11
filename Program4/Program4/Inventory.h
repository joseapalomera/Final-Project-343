//
//  Inventory.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class Inventory
{
public:
    Inventory();
    Inventory(string const &fileName);
    ~Inventory();
    
    void buildInventory(string const &fileName);
    
    void viewClassics();
    void viewComedies();
    void viewDramas();
    
    void viewInventory();
    
    bool findClassicMovie(int month, int year, string title, Classic &selection);
    bool findComedyMovie(string title, int year, Comedy &selection);
    bool findDramaMovie(string director, string title, Drama &selection);
    
private:
    vector<Classic> classics;
    vector<Comedy> comedies;
    vector<Drama> dramas;
};
#endif /* Inventory_h */
