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
    buildInventory("data4movies.txt");
}

Inventory::Inventory(string const &fileName)
{
    buildInventory(fileName);
}

Inventory::~Inventory()
{
    DeleteMovies();
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

// HAS WEIRD CASE
bool Inventory::findClassicMovie(int releaseMonth, int releaseYear, string majorActor, Classic &selection)
{
    // Searching through the classic movie vector to find the desired movie
    for (int i = 0; i < classics.size(); i++)
    {
        // If we locate the desired movie
        if (releaseMonth == classics[i].getReleaseMonth() && releaseYear == classics[i].getReleaseYear() && majorActor == classics[i].getMajorActor())
        {
            // Return false if it is out of stock
            if (classics[i].getStock() == 0)
            {
                cout << "ERROR: Movie out of stock" << endl;
                // FIND OUT IF THERE IS ANOTHER ONE
                return false;
            }
            
            // In stock so we send the desired movie over and return true
            selection = classics[i];
            return true;
        }
    }
    // No such movie in the database
    cout << "ERROR: Movie not found in database" << endl;
    return false;
}

bool Inventory::findComedyMovie(string title, int releaseYear, Comedy &selection)
{
    // Searching through the comedy movie vector to find the desired movie
    for (int i = 0; i < comedies.size(); i++)
    {
        // If we locate the desired movie
        if (title == comedies[i].getTitle() && releaseYear == comedies[i].getReleaseYear())
        {
            // Return false if it is out of stock
            if (comedies[i].getStock() == 0)
            {
                cout << "ERROR: Movie out of stock" << endl;
                return false;
            }
            
            // In stock so we send the desired movie over and return true
            selection = comedies[i];
            return true;
        }
    }
    // No such movie in the database
    cout << "ERROR: Movie not found in database" << endl;
    return false;
}

bool Inventory::findDramaMovie(string director, string title, Drama &selection)
{
    // Searching through the drama movie vector to find the desired movie
    for (int i = 0; i < dramas.size(); i++)
    {
        // If we locate the desired movie
        if (director == dramas[i].getDirector() && title == dramas[i].getTitle())
        {
            // Return false if it is out of stock
            if (dramas[i].getStock() == 0)
            {
                cout << "ERROR: Movie out of stock" << endl;
                return false;
            }
            
            // In stock so we send the desired movie over and return true
            selection = dramas[i];
            return true;
        }
    }
    // No such movie in the database
    cout << "ERROR: Movie not found in database" << endl;
    return false;
}

void Inventory::DeleteMovies()
{
//    for (int i = 0; i < classics.size(); i++)
//    {
//        Classic *movie = classics[i];
//        delete movie;
//        movie == NULL;
//    }
//
//    for (int i = 0; i < comedies.size(); i++)
//    {
//        Comedy *movie = comedies[i];
//        delete movie;
//        movie == NULL;
//    }
//
//    for (int i = 0; i < dramas.size(); i++)
//    {
//        Classic *movie = dramas[i];
//        delete movie;
//        movie == NULL;
//    }
}
