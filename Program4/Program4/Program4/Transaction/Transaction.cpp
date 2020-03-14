//
//  Transaction.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Transaction.h"

Transaction::Transaction()
{
    setCustomerID(-1);
}

Transaction::~Transaction()
{
    movie = nullptr;
}

Transaction::Transaction(char transactionType, int customerID, Movie *selection)
{
    setTransactionType(transactionType);
    setCustomerID(customerID);
    setMovie(selection);
}

void Transaction::setCustomerID(int customerID)
{
    this->customerID = customerID;
}

int Transaction::getCustomerID()const
{
    return this->customerID;
}

void Transaction::setTransactionType(char type)
{
    this->transactionType = type;
}

char Transaction::getTransactionType()const
{
    return this->transactionType;
}

void Transaction::setMovie(Movie *movie)
{
    this->movie = movie;
}

Movie* Transaction::getMovie()const
{
    return this->movie;
}

void Transaction::doTrans(){}

void Transaction::display()const{}

