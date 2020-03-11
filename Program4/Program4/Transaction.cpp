//
//  Transaction.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Transaction.h"

Transaction::Transaction(){}

//Transaction::Transaction(Customer *client, Movie *selection)
//{
//    customer = client;
//    movie = selection;
//}

Transaction::~Transaction()
{
    //customer = NULL;
    movie = NULL;
}

void Transaction::doTrans(){}

ostream& operator<<(ostream &out, const Transaction &t)
{
    
    return out;
}

void Transaction::print(ostream &out)const
{
    
}
