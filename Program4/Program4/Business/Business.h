//
//  Business.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Business_h
#define Business_h

#include <queue>
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
#include "BSTree.h"

using namespace std;

class Business
{
public:
    Business();
    ~Business();
    
    void buildMovies(ifstream &file);
    void buildCustomers(ifstream &file);
    void buildTransactions(string transactions);
    void executeTransactions();
    
    void viewMovies();
    void viewCustomers();
private:
    BSTree comedies;
    BSTree dramas;
    BSTree classics;
    
    HashTable customers;
    queue<Transaction> list;
    
};
#endif /* Business_h */
