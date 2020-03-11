//
//  Business.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Business.h"

Business::Business(string movieFile)
{
    theInventory.buildInventory(movieFile);
}

Business::~Business()
{
    
}

void Business::buildCustomers(ifstream &file)
{
    string theLine;
    
    while(getline(file, theLine))
    {
        int theId;
        string firstName, lastName;
        
        file >> theId >> lastName >> firstName;
        
        Customer *theCustomer = new Customer();
        
        theCustomer->setId(theId);
        theCustomer->setLastName(lastName);
        theCustomer->setFirstName(firstName);
        customers.addCustomer(theCustomer);
        
    }
    
}

void Business::buildTransactions(string transactions)
{
    
}

void Business::executeTransactions()
{
    
}

void Business::viewMovies()
{
    
    cout << endl;
    theInventory.viewInventory();
}

void Business::viewCustomers()
{
    cout << "Customers: \n" << endl;
    Customer *temp = customers.getCustomer(8888);
    cout << *temp << endl;
}
