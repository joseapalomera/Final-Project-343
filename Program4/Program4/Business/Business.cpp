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
    
    string currentLine;
    
    //Looping through each line in the commands data file
    while(getline(commandsFile, currentLine))
    {
        //Store in information of the first char
        char commandType,  movieType;
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
                    cout << "ERROR: Customer " << customerID << " not found" << endl;
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
                            
                        string majorActor = (firstName + " " + lastName);
                            
                        //There is an issue here because the Movie object "is an abstract class"
                        Classic movie;
                        bool validMovie = theInventory.findClassicMovie(releaseMonth, releaseYear, majorActor, movie);
                        if (validMovie)
                        {
                        Movie &valid = movie;
                        Movie *tryBorrowing = &valid;
                            
                        // Borrow newTransaction(tryBorriwn);
                    
                        // if it returned true then make Borrow object
                        
                        // call method in customer to check valid borrow
                        // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        }
                        break;
                    }
                    case 'D':
                    
                        // store release month, year, major actor
                        // Drama temp;
                        // call findDramaMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        break;
                    
                    case 'F':
                    
                        // store release month, year, major actor
                        // Comedu temp;
                        // call findComedyMovie with given information
                        // if it returned true then make Borrow object
                            // if borrow is valid then add to history of customer
                        // else error message should already be outputted
                        break;
                    
                    default:
                    {
                        // else invalid category
                        // cout << "ERROR: Invalid command type" << endl;
                    }
                    
                }
                
                break;
            }
            case 'R':
               
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
                    bool validMovie = theInventory.findClassicMovie(releaseMonth, releaseYear, majorActor, movie);
                    if (validMovie)
                    {
                        Movie &valid = movie;
                    // if it returned true then make Return object
                        // if return is valid then add to history of customer
                    // else error message should already be outputted
                    }
                        break;
                    }
                    
                    case 'D':
                    
                    // store release month, year, major actor
                    // Drama temp;
                    // call findDramaMovie with given information
                    // if it returned true then make Return object
                    // if Return is valid then add to history of customer
                    // else error message should already be outputted
                    break;
                    
                    case 'F':
                    
                    // store release month, year, major actor
                    // Comedy temp;
                    // call findComedyMovie with given information
                    // if it returned true then make Return object
                    // if return is valid then add to history of customer
                    // else error message should already be outputted
                    break;
                    
                    default:
                    {
                    // else invalid category
                    // cout << "ERROR: Invalid command type" << endl;
                    }
                }
                break;
                
            case 'I':
                
                viewMovies();
                break;
                
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
                    cout << "ERROR: Customer " << customerID << " not found" << endl;
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
    
    cout << endl;
    cout << "Movies:" << endl;
    theInventory.viewInventory();
}
