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
    
    Customer *theCustomer = NULL;
    
    // Looping through the customer data file
    while (!customersFile.eof())
    {
        theCustomer = new Customer();
        
        // Attempting to create and add customer to the database
        if (theCustomer->setData(customersFile))
        {
            // If customer can't be added, deallocate the data accordingly
            if (!customers.addCustomer(theCustomer))
            {
                delete theCustomer;
                theCustomer = NULL;
            }
            theCustomer = NULL;
        }
        // Deallocating the data accordingly
        else
        {
            delete theCustomer;
            theCustomer = NULL;
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
        char commandType, movieType;
        commandsFile >> commandType;
        
        switch(commandType)
        {
            case 'B':
            {
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // continue to next iteration of loop if customer isn't in database
                if (customer == NULL)
                {
                    continue;
                }
                
                // reading in the char for DVD which we can ignored
                char format;
                commandsFile >> format;
                
                // store category type
                commandsFile >> movieType;
                
                switch(movieType)
                {
                    case 'C':
                    {
                        int releaseMonth, releaseYear;
                        commandsFile >> releaseMonth >> releaseYear;
                        
                        string firstName, lastName;
                        commandsFile >> firstName >> lastName;
                        
                        string majorActor = firstName + " " + lastName;
                        
                        Classic movie;
                        bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, movie);
                        if (validMovie)
                        {
                            Movie valid = movie;
                            //Movie *tryBorrowing = valid;
                            // Borrow newTransaction(tryBorriwn);
                
                        // if it returned true then make Borrow object
                        
                            // call method in customer to check valid borrow
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        }
                        break;
                    }
                    case 'D':
                    {
                        // store release month, year, major actor
                        // Drama temp;
                        // call findDramaMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        break;
                    }
                    case 'F':
                    {
                        // store release month, year, major actor
                        // Comedu temp;
                        // call findComedyMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        break;
                    }
                    default:
                    {
                    // else invalid category
                        // cout << "ERROR: Invalid command type" << endl;
                    }
                }
                break;
            }
            case 'R':
            {
                // read in account number
                
                // attempt to get account first, if invalid just continue;
                
                // reading in D for DVD IGNORE
                // store category type
                commandsFile >> movieType;
                
                switch(movieType)
                {
                    case 'C':
                    {
                    int releaseMonth, releaseYear;
                    commandsFile >> releaseMonth >> releaseYear;
                    
                    string firstName, lastName;
                    commandsFile >> firstName >> lastName;
                    
                    string majorActor = firstName + " " + lastName;
                    
                    Classic movie;
                    bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, movie);
                    if (validMovie)
                    {
                        Movie valid = movie;
                    // if it returned true then make Return object
                        // if return is valid then add to history of customer
                    // else error message should already be outputted
                    }
                        break;
                    }
                    case 'D':
                    {
                    // store release month, year, major actor
                    // Drama temp;
                    // call findDramaMovie with given information
                    // if it returned true then make Return object
                        // if Return is valid then add to history of customer
                    // else error message should already be outputted
                        break;
                    }
                    case 'F':
                    {
                    // store release month, year, major actor
                    // Comedy temp;
                    // call findComedyMovie with given information
                    // if it returned true then make Return object
                        // if return is valid then add to history of customer
                    // else error message should already be outputted
                        break;
                    }
                    default:
                    {
                    // else invalid category
                        // cout << "ERROR: Invalid command type" << endl;
                    }
                }
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
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // continue to next iteration of loop if customer isn't in database
                if (customer == NULL)
                {
                    continue;
                }
                // output history for customer if the the customer is in the system
                else
                {
                    customer->viewHistory();
                }
                break;
            }
            default:
            {
                cout << "ERROR: Invalid command type " << commandType << endl;
            }
        }
    }
}

void Business::viewMovies()
{
    cout << "Outputting the store's current movies:" << endl;
    movies.viewInventory();
}

void Business::viewCustomers()
{
    cout << "Outputting the store's current customers:" << endl;
    Customer *temp = customers.getCustomer(8888);
    cout << *temp << endl;
}
