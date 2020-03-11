//
//  Customer.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Customer.h"

Customer::Customer()
{

}

Customer::~Customer()
{
    
}

bool Customer::setData(ifstream &file)
{
    int id;
    string firstN, lastN;
    
    file >> id >> lastN >> firstN;
    if(setId(id) != true)
    {
        cout << "ERROR: Customer not created" << endl;
        return false;
    }
    
    setLastName(lastN);
    setFirstName(firstN);
    
    return true;
    
}

bool Customer::setId(int cusId)
{
    if(cusId > 999 && cusId < 10000)
    {
        this->id = cusId;
        return true;
    }
    
    cout << "Invalid ID: " << cusId << endl;
    return false;
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

bool Customer::addTransaction(Transaction *t)
{
    
    history.push_back(t);
    
    return true;
}

Customer& Customer::operator=(const Customer &c)
{
    if(c.getFirstName() == "" && c.getLastName() == "" && c.getId() == -1)
    {
        return *this;
    }
    
    setFirstName(c.getFirstName());
    setLastName(c.getLastName());
    setId(c.getId());
    
    return *this;
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

void Customer::viewHistory()
{
    for(int i = 0; i < history.size(); i++)
    {
        cout << history[i] << endl;
    }
    
}

ostream& operator<<(ostream &out, const Customer &cust)
{
    out << "Id " << cust.getId() << ": "
    << cust.getFirstName() << " " << cust.getLastName() << endl;
    return out;
}
