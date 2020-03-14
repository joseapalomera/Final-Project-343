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
        cerr << "ERROR: Invalid customer input file" << endl;
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
        cerr << "ERROR: Invalid command input file" << endl;
        return;
    }
    
    string currentLine;
    
    // Looping throught each line in the commands data file
    while(getline(commandsFile, currentLine))                                // SKIPPING OVER FIRST LINE
    {
        // store in information of the first char
        char commandType, movieType;
        commandsFile >> commandType;
        
        // Switch statement for which command is attempted
        switch(commandType)
        {
            // If the transaction is a borrow
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
                
                // Switch statement for which category the movie belongs to
                switch(movieType)
                {
                    // Classic movie
                    case 'C':
                    {
                        int releaseMonth, releaseYear;
                        commandsFile >> releaseMonth >> releaseYear;
                        
                        string firstName, lastName;
                        commandsFile >> firstName >> lastName;
                        
                        string majorActor = firstName + " " + lastName;
                        
                        // Checking if their movie choice is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, selection);
                        
                        // If the movie is in the database
                        if (validMovie)
                        {
                            // Creating a transaction object
                            Transaction *t = new Borrow('B', selection);
                            
                            // Completing the transaction and adding to the customers history for a valid transaction
                            if (customer->borrowIsValid('C', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            // Dellocating data for an invalid return
                            else
                            {
                                delete t;
                                t = NULL;
                            }
                        }
                        break;
                    }
                    // Drama movie
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
                    // Comedy movie
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
                        cerr << "ERROR: Invalid movie type" << endl;
                    }
                }
                break;
            }
            // If the transaction is a return
            case 'R':
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
                
                // Switch statement for which category the movie belongs to
                switch(movieType)
                {
                    // Classic movie
                    case 'C':
                    {
                    int releaseMonth, releaseYear;
                    commandsFile >> releaseMonth >> releaseYear;
                    
                    string firstName, lastName;
                    commandsFile >> firstName >> lastName;
                    
                    string majorActor = firstName + " " + lastName;
                    
                    // Checking if their movie choice is valid and getting it if it is true
                    Movie *selection;
                    bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, selection);
                    
                    // If the movie is in the database
                    if (validMovie)
                    {
                        // Creating a transaction object
                        Transaction *t = new Return('R', selection);
                        
                        // Completing the transaction and adding to the customers history for a valid transaction
                        if (customer->returnIsValid('C', t))
                        {
                            t->doTrans();
                            customer->addTransaction(t);
                        }
                        // Dellocating data for an invalid return
                        else
                        {
                            delete t;
                            t = NULL;
                        }
                    }
                        break;
                    }
                    // Drama movie
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
                    // Comedy movie
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
                        cerr << "ERROR: Invalid movie type " << movieType << endl;
                    }
                }
                break;
            }
            // If the command is to show the inventory of the store
            case 'I':
            {
                viewMovies();
                break;
            }
            // If the command is to show the history of the customer
            case 'H':
            {
                // store id of the customer
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // output history for customer if the the customer is in the system
                if (customer != NULL)
                {
                    customer->viewHistory();
                }
                break;
            }
            default:
            {
                cerr << "ERROR: Invalid command type " << commandType << endl;
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
