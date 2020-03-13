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
    setId(-1);
    setFirstName("");
    setLastName("");
}

Customer::~Customer()
{
    
}

bool Customer::setData(ifstream &file)
{
    int id;
    string firstN, lastN;
    
    //Reads from the individual line in the file
    file >> id >> lastN >> firstN;
    
    //Testing done here to see if we recieved input
    //from the file
    cout << id << " " << lastN << " " << firstN << endl;
    
    //Checks to see if the id is valid
    if(setId(id) != true)
    {
        cout << "ERROR: Customer not created" << endl;
        return false;
    }
    
    //If the id is valid, the rest of the information is stored
    setLastName(lastN);
    setFirstName(firstN);
    
    return true;
    
}

bool Customer::setId(int cusId)
{
    //ID must be in between 999-10000
    //for it to be valid
    if(cusId > 999 && cusId < 10000)
    {
        this->id = cusId;
        return true;
    }
    
    //Returns false and alerts the store if the id is invalid
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
    //Adds a transaction object to the customers transaction history
    history.push_back(t);
    
    return true;
}

Customer& Customer::operator=(const Customer &c)
{
    //If the right handed side is a default Customer object
    if(c.getFirstName() == "" && c.getLastName() == "" && c.getId() == -1)
    {
        //then just return the current Customer
        return *this;
    }
    
    //Otherwise, set the information from the right side to the current Customer
    setFirstName(c.getFirstName());
    setLastName(c.getLastName());
    setId(c.getId());
    
    return *this;
}

bool Customer::operator==(const Customer &cust)const
{
    //If both IDs are the same
    if(this->getId() == cust.getId()){
        //If both last names are the same
        if(this->getLastName().compare(cust.getLastName()) == 0){
            //If both first names are the same
            if(this->getFirstName().compare(cust.getFirstName()) == 0){
                //Then both Customer objects are equal
                return true;
            }
        }
    }
    
    //Return false if any of the conditions above are not true
    return false;
}

bool Customer::operator!=(const Customer &cust)const
{
    return !(*this == cust);
}

bool Customer::returnIsValid(Transaction const *borrowing) const
{
    // Get the movie selection
    Movie *selection = borrowing->getMovie();
    
    int numBorrowed = 0;
    int numReturned = 0;
    
    // Loop through this customers history of transactions
    for (int i = 0; i < history.size(); i++)
    {
        // If we find a transaction with their selected movie
        if (history[i]->getMovie() == selection)
        {
            // If the transaction was a borrow
            if (history[i]->getTransactionType() == 'B')
            {
                numBorrowed++;
            }
            // If the transaction was a return
            else if (history[i]->getTransactionType() == 'R')
            {
                numReturned++;
            }
        }
    }
    
    // the customer can return it if they borrowed it
    if ((numBorrowed + 1) == numReturned)
    {
        return true;
    }
    
    return false;
}

bool Customer::borrowIsValid(Transaction const *returning) const
{
    // Get the movie selection
    Movie *selection = returning->getMovie();
    
    int numBorrowed = 0;
    int numReturned = 0;
    
    // If we find a transaction with their selected movie
    for (int i = 0; i < history.size(); i++)
    {
        // If we find a transaction with their selected movie
        if (history[i]->getMovie() == selection)
        {
            // If the transaction was a borrow
            if (history[i]->getTransactionType() == 'B')
            {
                numBorrowed++;
            }
            // If the transaction was a return
            else if (history[i]->getTransactionType() == 'R')
            {
                numReturned++;
            }
        }
    }
    
    // the customer can borrow since they don't have it borrowed right now
    if (numBorrowed == numReturned)
    {
        return true;
    }
    
    return false;
}

void Customer::viewHistory()
{
    //Prints out the transactions from the history
    for(int i = 0; i < history.size(); i++)
    {
        cout << history[i] << endl;
    }
    
}

void Customer::displayCustomer()
{
    //Displays the customer's credentials
    cout << "Id " << getId() << ": " << getFirstName()
    << " " << getLastName() << endl;
}
