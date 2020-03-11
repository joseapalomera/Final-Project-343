//
//  Business.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Business_h
#define Business_h

#include <string>
#include <iostream>
#include <fstream>
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
#include "HashTable.h"
#include "Customer.h"
#include "Transaction.h"
#include "Inventory.h"

using namespace std;

class Business
{
public:
    Business(string const &movieData);
    ~Business();
    
    void buildCustomers(string const &customerData);
    void executeCommands(string const &commandData);
    
    void viewMovies();
    void viewCustomers();
private:
    HashTable customers;
    Inventory movies;
    
};
#endif /* Business_h */
