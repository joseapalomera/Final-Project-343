//
//  main.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <iostream>
#include "Business.h"

#include "Movie.h"
#include "Comedy.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    //Here we create the movie BSTs for the business
     
    cout << "Testing insertion of movies:" << endl;
    
    Business b("data4movies.txt");
    b.viewMovies();

    b.buildCustomers("data4customers.txt");
    b.viewCustomers();
    
    
        return 0;
}
//Extra space before title and director
