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
    //BinarySearchTree movies;
    //HashTable customers;
    //queue<Transaction> list;
};
#endif /* Business_h */
