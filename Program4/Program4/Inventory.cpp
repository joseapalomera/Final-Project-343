//
//  Inventory.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "Inventory.h"

Inventory::Inventory()
{
    
}

Inventory::~Inventory()
{
    
}

void Inventory::buildInventory(ifstream &movies)
{
    
    while(!movies.eof())
    {
            
        char type;
        
        movies >> type;
        
        Classic *c = new Classic();
        Comedy *f = new Comedy();
        Drama *d = new Drama();
        
        switch(type)
        {
            case 'C':
                c->setData(movies);
                //myClassics.push_back(c);
                break;
                
            case 'F':
                f->setData(movies);
                //comedies->Insert(f);
                break;
                
            case 'D':
                d->setData(movies);
                //dramas->Insert(d);
                break;
                
            default:
                cout << "Invalid Movie Type: " << type << endl;
                movies.ignore(1000000, '\n');
                break;
        }
        
    }
    
}

void Inventory::viewClassics()
{
    for(int i = 0;i < myClassics.size(); i++)
    {
        cout << myClassics[i] << endl;
    }
}

void Inventory::viewComedies()
{
    for(int i = 0;i < myComedies.size(); i++)
    {
        cout << myComedies[i] << endl;
    }
}

void Inventory::viewDramas()
{
    for(int i = 0;i < myDramas.size(); i++)
    {
        cout << myDramas[i] << endl;
    }
}

void Inventory::viewInventory()
{
    cout << "Classics:" << endl;
    viewClassics();
    
    cout << "Comedies:" << endl;
    viewComedies();
    
    cout << "Dramas:" << endl;
    viewDramas();
}

/*
Classic* getClassic(int month, int year, string title)
{

}

Comedy* getComedy(string title, int year)
{
    
}

Drama* getDrama(string director, string title)
{

}
*/
