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
#include "Movie.h"

using namespace std;

class Transaction
{
public:
    Transaction();
    Transaction(int customerID, Movie *movie);
    ~Transaction();
    
    void setCustomerID(int customerID);
    int getCustomerID()const;
    
    virtual void doTrans();
    
    friend ostream& operator<<(ostream &out, const Transaction &t);
    virtual void print(ostream &out)const;
    
private:
    int customerID;
    Movie *movie;
};

#endif /* Transaction_h */
