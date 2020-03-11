//
//  Transaction.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Transaction_h
#define Transaction_h

#include <iostream>
#include <string>
#include "Customer.h"
#include "Movie.h"
using namespace std;

class Transaction
{
public:
    Transaction();
    Transaction(Customer *customer, Movie *movie);
    ~Transaction();
    
    virtual void doTrans();
    
    friend ostream& operator<<(ostream &out, const Transaction &t);
    virtual void print(ostream &out)const;
    
private:
    Customer *customer;
    Movie *movie;
};

#endif /* Transaction_h */
