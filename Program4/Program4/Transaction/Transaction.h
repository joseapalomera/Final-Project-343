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
    //Constructors
    Transaction();
    Transaction(int customerID, Movie *movie);
    ~Transaction();
    
    //Setters
    virtual void setCustomerID(int customerID);
    virtual void setTransactionType(char type);
    virtual void setMovie(Movie *movie);
    
    //Getters
    virtual int getCustomerID()const;
    virtual char getTransactionType()const;
    virtual Movie* getMovie()const;
    
    virtual void doTrans(); //Method that executes the transaction
    virtual void display(); //Method that displays the transaction
    
protected:
    int customerID;
    Movie *movie;
    char transactionType;
};

#endif /* Transaction_h */
