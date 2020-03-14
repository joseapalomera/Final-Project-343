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
#include <fstream>
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;
class Customer
{
public:
    Customer();
    Customer(int customerID, string firstName, string lastName);
    ~Customer();
    
    bool addTransaction(Transaction *t);
    friend ostream& operator<<(ostream &out, const Customer &cust);
    
    bool setData(ifstream &file);
    bool setId(int cusId);
    void setLastName(string lastN);
    void setFirstName(string firstN);
    
    int getId()const;
    string getLastName()const;
    string getFirstName()const;
    
    Customer& operator=(const Customer& c);
    bool operator==(const Customer& cust)const;
    bool operator!=(const Customer& cust)const;
    
    bool returnIsValid(char movieType, Transaction const *borrowing) const;
    bool borrowIsValid(char movieType, Transaction const *returning) const;
    void viewHistory() const;
    
private:
    int id;
    string lastName;
    string firstName;
    vector<Transaction*> history;
};

#endif /* Customer_h */
