//
//  Business.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Business.h"

Business::Business(string const &movieFile)
{
    theInventory.buildInventory(movieFile);
}

Business::~Business()
{
    
}

void Business::buildCustomers(string const &customerData)
{
    ifstream file(customerData);
    
    if(!file)
    {
        cout << "ERROR: Invalid customer input file" << endl;
        return;
    }
    
    Customer *theCustomer = nullptr;
    
    while(!file.eof())
    {
        
        theCustomer = new Customer();
        
        if(theCustomer->setData(file))
        {
            if(!customers.addCustomer(theCustomer))
            {
                delete theCustomer;
                theCustomer = nullptr;
            }
            theCustomer = nullptr;
        }
        else
        {
            delete theCustomer;
            theCustomer = nullptr;
        }
        
    }
    
}

void Business::executeCommands(string const &commandData)
{
    ifstream commandsFile(commandData);
    if(!commandsFile)
    {
        cout << "ERROR: Invalid command input file" << endl;
        return;
    }
}

void Business::viewMovies()
{
    
    cout << endl;
    cout << "Movies:" << endl;
    theInventory.viewInventory();
}

void Business::viewCustomers()
{
    cout << "Customers: \n" << endl;
    //Customer *temp = customers.getCustomer(8888);
    //cout << *temp << endl;
}
