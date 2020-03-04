//
//  Customer.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Customer.h"

Customer::Customer(){
    setId(-1);
    setLastName("Last Name");
    setFirstName("First Name");
}

Customer::Customer(int id, string lastN, string firstN)
{
    setId(id);
    setLastName(lastN);
    setFirstName(firstN);
}

Customer::~Customer()
{
    
}

void Customer::setId(int cusId)
{
    this->id = cusId;
}

void Customer::setLastName(string lastN)
{
    this->lastName = lastN;
}

void Customer::setFirstName(string firstN)
{
    this->firstName = firstN;
}

int Customer::getId()const
{
    return this->id;
}

string Customer::getLastName()const
{
    return this->lastName;
}

string Customer::getFirstName()const
{
    return this->firstName;
}

bool Customer::addTransaction(Transaction t)
{
    
    history.push_back(t);
    
    return true;
}

bool Customer::operator==(const Customer &cust)const
{
    
    if(this->getId() == cust.getId()){
        if(this->getLastName() == cust.getLastName()){
            if(this->getFirstName() == cust.getFirstName()){
                return true;
            }
        }
    }
    
    return false;
}

bool Customer::operator!=(const Customer &cust)const
{
    return !(*this == cust);
}


ostream& operator<<(ostream &out, const Customer &cust)
{
    
    out << cust.getFirstName() << " " << cust.getLastName();
    out << " " << cust.getId() << ":" << endl;
    return out;
}
