//
//  Transaction.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
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

Transaction::Transaction(int customerID, Movie *selection)
{
    setCustomerID(customerID);
    movie = selection;
}

void Transaction::doTrans()
{
    
}

void Transaction::setCustomerID(int customerID)
{
    this->customerID = customerID;
}

int Transaction::getCustomerID()const
{
    return this->customerID;
}

ostream& operator<<(ostream &out, const Transaction &t)
{
    
    return out;
}

void Transaction::print(ostream &out)const
{
    
}

