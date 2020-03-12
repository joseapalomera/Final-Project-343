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
    
    virtual void setCustomerID(int customerID);
    virtual int getCustomerID()const;
    
    virtual void setTransactionType(char type);
    virtual char getTransactionType()const;
    
    virtual void setMovie(Movie *movie);
    virtual Movie* getMovie()const;
    
    virtual void doTrans();
    
    virtual void display();
    
protected:
    int customerID;
    Movie *movie;
    char transactionType;
};

#endif /* Transaction_h */
