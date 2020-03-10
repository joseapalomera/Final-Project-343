//
//  Business.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Business.h"

Business::Business()
{
    
}

Business::~Business()
{
    
}

void Business::buildMovies(ifstream &file)
{
    while(!file.eof())
    {
            
        char type;
        
        file >> type;
        
        Classic *c = new Classic();
        Comedy *f = new Comedy();
        Drama *d = new Drama();
        
        switch(type)
        {
            case 'C':
                c->setData(file);
                classics.Insert(c);
                break;
                
            case 'F':
                f->setData(file);
                comedies.Insert(f);
                break;
                
            case 'D':
                d->setData(file);
                dramas.Insert(d);
                break;
                
            default:
                cout << "Invalid Movie Type: " << type << endl;
                file.ignore(1000000, '\n');
                break;
        }
        
    }
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
    cout << "Classics: \n" << endl;
    classics.Display();
    
    cout << "Comedies: \n" << endl;
    comedies.Display();
    
    cout << "Dramas: \n" << endl;
    dramas.Display();
    
}

void Business::viewCustomers()
{
    cout << "Customers: \n" << endl;
    Customer *temp = customers.getCustomer(8888);
    cout << *temp << endl;
}
