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
#include <fstream>

#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Inventory
{
private:
    vector<Classic> classics;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    
    void DeleteMovies();
    
public:
    //Constuctors
    Inventory();
    ~Inventory();
    
    //Builds an inventory
    void buildInventory(string const &movieFile);
    
    //Methods that help display the movies in the inventory
    void viewClassics();
    void viewComedies();
    void viewDramas();
    void viewInventory();
    
    //Methods that retrieve movies from the inventory
    bool findClassicMovie(int month, int year, string title, Classic &selection);
    bool findComedyMovie(string title, int releaseYear, Comedy &selection);
    bool findDramaMovie(string director, string title, Drama &selection);
    
    
};
#endif /* Inventory_h */