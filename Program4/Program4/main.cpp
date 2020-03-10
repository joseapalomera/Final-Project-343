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
     Business b;
     
     b.buildMovies("data4movies.txt");
     b.buildCustomers("data4customers.txt");
     b.buildTransactions("data4commands.txt");
     b.executeTransactions();
     
     */
    
    cout << "Testing..." << endl;
    
    ifstream movieFile("data4movies.txt");
    if(!movieFile)
    {
        cout << "File could not be opened" << endl;
        return 1;
    }
    
    Business b;
    b.buildMovies(movieFile);
    b.viewMovies();
    
    return 0;
}
