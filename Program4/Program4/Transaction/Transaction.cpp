//
//  Transaction.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Transaction.h"

Transaction::Transaction(){
    setCustomerID(-1);
}

Transaction::~Transaction(){
    
}

void Transaction::setCustomerID(int customerID){
    this->customerID = customerID;
}

void Transaction::doTrans(){
    
}

ostream& operator<<(ostream &out, const Transaction &t){
    
    return out;
}

void Transaction::print(ostream &out)const{
    
}

