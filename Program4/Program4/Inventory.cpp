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

Inventory::Inventory(string const &fileName)
{
    buildInventory(fileName);
}

Inventory::~Inventory()
{
    
}

void Inventory::buildInventory(string const &fileName)
{
    ifstream moviesFile(fileName);
    
    if (!moviesFile)
    {
        cout << "ERROR: Invalid input file" << endl;
        return;
    }
    
    string currentLine;
    
    while(!moviesFile.eof())
    {
        char type;
        
        moviesFile >> type;
        
        switch(type)
        {
            case 'C':
            {
                Classic *c = new Classic();
                c->setData(moviesFile);
                classics.push_back(*c);
                break;
            }
            case 'F':
            {
                Comedy *f = new Comedy();
                f->setData(moviesFile);
                comedies.push_back(*f);
                break;
            }
            case 'D':
            {
                Drama *d = new Drama();
                d->setData(moviesFile);
                dramas.push_back(*d);
                break;
            }
            default:
            {
                cout << "ERROR: Invalid movie type " << type << endl;
                moviesFile.ignore(1000000, '\n');
                break;
            }
        }
    }
}

void Inventory::viewClassics()
{
    for(int i = 0; i < classics.size(); i++)
    {
        cout << classics[i];
    }
    cout << endl;

}

void Inventory::viewComedies()
{
    for(int i = 0; i < comedies.size(); i++)
    {
        cout << comedies[i];
    }
    cout << endl;
}

void Inventory::viewDramas()
{
    for(int i = 0; i < dramas.size(); i++)
    {
        cout << dramas[i];
    }
    cout << endl;
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

bool Inventory::findClassicMovie(int month, int year, string title, Classic &selection)
{
    return false;
}

bool Inventory::findComedyMovie(string title, int year, Comedy &selection)
{
    return false;
}

bool Inventory::findDramaMovie(string director, string title, Drama &selection)
{
    return false;
}
