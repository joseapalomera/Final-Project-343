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

#include "Movie.h"
#include "Customer.h"
#include "Transaction.h"
#include "BSTree.h"

using namespace std;

class Business
{
public:
    Business();
    ~Business();
    
    void buildMovies(string movies);
    void buildCustomers(string customers);
    void buildTransactions(string transactions);
    void executeTransactions();
    
private:
    BSTree comedies;
    BSTree dramas;
    BSTree classics;
    
    //HashTable customers;
    queue<Transaction> list;
};
#endif /* Business_h */
