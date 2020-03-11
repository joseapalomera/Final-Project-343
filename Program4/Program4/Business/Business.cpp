//
//  Business.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Business.h"

Business::Business(string const &movieData)
{
    // building the movie store inventory
    movies.buildInventory(movieData);
}

Business::~Business(){}

void Business::buildCustomers(string const &customerData)
{
    // Creating file and checking its validity
    ifstream customersFile(customerData);
    if (!customersFile)
    {
        cout << "ERROR: Invalid customer input file" << endl;
        return;
    }
    
    string theLine;
    
    // Looping throught each line in the customer data file
    while(getline(customersFile, theLine))
    {
        int userID;
        string firstName, lastName;
        
        // Reading in information from the file
        customersFile >> userID >> lastName >> firstName;
        
        // Create and add customer to hash table if the userID is valid
        if (userID > 0 && userID < 10000)
        {
            Customer *theCustomer = new Customer();
        
            theCustomer->setId(userID);
            theCustomer->setLastName(lastName);
            theCustomer->setFirstName(firstName);
            customers.addCustomer(theCustomer);
        }
        // Outputs error message for invalid indentification number
        else
        {
            cout << "ERROR: Invalid customer identification number" << endl;
        }
    }
}

void Business::executeCommands(string const &commandData)
{
    // Creating file and checking its validity
    ifstream commandsFile(commandData);
    if (!commandsFile)
    {
        cout << "ERROR: Invalid command input file" << endl;
        return;
    }
}

void Business::viewMovies()
{
    cout << endl;
    cout << "Movies:" << endl;
    movies.viewInventory();
}

void Business::viewCustomers()
{
    cout << "Customers:" << endl;
    Customer *temp = customers.getCustomer(8888);
    cout << *temp << endl;
}
