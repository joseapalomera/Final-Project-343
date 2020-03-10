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
#include "BSTree.h"

using namespace std;

class Inventory
{
private:
    vector<Classic> myClassics;
    vector<Comedy> myComedies;
    vector<Drama> myDramas;
    
public:
    
    Inventory();
    ~Inventory();
    
    void buildInventory(ifstream &theFile);
    
    void viewClassics();
    void viewComedies();
    void viewDramas();
    
    void viewInventory();
    
    /*
    Classic* getClassic(int month, int year, string title); //Come back to see if we return reference
    Comedy* getComedy(string title, int year);
    Drama* getDrama(string director, string title);
    */
};
#endif /* Inventory_h */
