//
//  main.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <iostream>
#include "Business.h"

using namespace std;

int main(int argc, const char * argv[]) {
     
    cout << "Testing insertion of movies:" << endl;
    cout << endl;
    
    Business b("data4movies.txt");
    b.viewMovies();

    cout << "Testing for the HashTable: " << endl;
    cout << endl;
    
    b.buildCustomers("data4customers.txt");
    
    Classic *type = new Classic();
    type->setStock(10);
    type->setDirector("Michael Curtiz");
    type->setTitle("Casablanca");
    type->setMajorActor("Ingrid Bergman");
    type->setReleaseMonth(8);
    type->setReleaseYear(1942);
    
    Classic *other = new Classic();
    other->setStock(10);
    other->setDirector("Michael Curtiz");
    other->setTitle("Casablanca");
    other->setMajorActor("Ingrid Bergman");
    other->setReleaseMonth(8);
    other->setReleaseYear(1942);
    
    cout << (*type == *other) << endl;
    
    return 0;
}
//Extra space before title and director
