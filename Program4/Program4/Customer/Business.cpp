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
    
    string currentLine;
    
    // Looping throught each line in the customer data file
    while(getline(customersFile, currentLine)) // SKIPPING OVER THE FIRST LINE
    {
        int userID;
        string firstName, lastName;
        
        // Reading in information from the file
        customersFile >> userID >> lastName >> firstName;
        
//        cout << userID << endl;
//        cout << lastName << endl;
//        cout << firstName << endl;
        
        // Create and add customer to hash table if the userID is valid
        if (userID > 999 && userID < 10000)
        {
            Customer *theCustomer = new Customer();
        
            // Setting the customers data accordingly
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
    
    string currentLine;
    
    // Looping throught each line in the commands data file
    while(getline(commandsFile, currentLine)) // SKIPPING OVER FIRST LINE
    {
        // store in information of the first char
        char type;
        commandsFile >> type;
        
        switch(type)
        {
            case 'B':
            {
                // read in account number
                
                // attempt to get account first, if invalid just continue;
                
                // reading in D for DVD IGNORE
                // store category type
                
                    // if type is classic
                        // store release month, year, major actor
                        // Classic temp;
                        // call findClassicMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else if type is drama
                        // store release month, year, major actor
                        // Drama temp;
                        // call findDramaMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else if type is comedy
                        // store release month, year, major actor
                        // Comedu temp;
                        // call findComedyMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else invalid category
                        // cout << "ERROR: Invalid command type" << endl;
                break;
            }
            case 'R':
            {
                // read in account number
                
                // attempt to get account first, if invalid just continue;
                
                // reading in D for DVD IGNORE
                // store category type
                
                    // if type is classic
                        // store release month, year, major actor
                        // Classic temp;
                        // call findClassicMovie with given information
                        // if it returned true then make Return object
                            // if return is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else if type is drama
                        // store release month, year, major actor
                        // Drama temp;
                        // call findDramaMovie with given information
                        // if it returned true then make Return object
                            // if Return is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else if type is comedy
                        // store release month, year, major actor
                        // Comedy temp;
                        // call findComedyMovie with given information
                        // if it returned true then make Return object
                            // if return is valid then add to history of customer
                        // else error message should already be outputted
                
                    // else invalid category
                        // cout << "ERROR: Invalid command type" << endl;
                break;
            }
            case 'I':
            {
                viewMovies();
                break;
            }
            case 'H':
            {
                // store id of the customer
                // if not in our parameters just ERROR: and continue;
                // attempt to get account first, if invalid just after outputting error continue;
                // else just call view history of pulled customer object
                break;
            }
            default:
            {
                
            }
        }
    }
}

void Business::viewMovies()
{
    cout << "Movies:" << endl;
    movies.viewInventory();
}

void Business::viewCustomers()
{
    cout << "Customers:" << endl;
    Customer *temp = customers.getCustomer(8888);
    cout << *temp << endl;
}
