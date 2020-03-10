//
//  main.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Business.h"
#include "Inventory.h"
#include "HashTable.h"
#include "Customer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*
     Here we create the movie BSTs for the business
     */
    cout << "Testing insertion of movies:" << endl;
    
    ifstream movieFile("data4movies.txt");
    if(!movieFile)
    {
        cout << "Movie file could not be opened" << endl;
        return 1;
    }
    
    Business b;
    b.buildMovies(movieFile);
    b.viewMovies();
    
    /*
     Here we then create the HashTable that will contain the customers
     */
    ifstream customerFile("data4customers.txt");
    if(!customerFile)
    {
        cout << "Customer file could not be opened" << endl;
        return 1;
    }
    
    cout << "Testing the HashTable: " << endl;
    b.buildCustomers(customerFile);
    b.viewCustomers();
    return 0;
}
