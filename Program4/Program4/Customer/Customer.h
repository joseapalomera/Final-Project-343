//
//  Customer.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Customer_h
#define Customer_h

#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;
class Customer
{
public:
    Customer();
    Customer(int id, string lastName, string firstName);
    ~Customer();
    
    bool addTransaction(Transaction t);
    friend ostream& operator<<(ostream &out, const Customer &cust);
    
    void setId(int cusId);
    void setLastName(string lastN);
    void setFirstName(string firstN);
    
    int getId()const;
    string getLastName()const;
    string getFirstName()const;
    
private:
    int id;
    string lastName;
    string firstName;
    vector<Transaction> history;
};

#endif /* Customer_h */
