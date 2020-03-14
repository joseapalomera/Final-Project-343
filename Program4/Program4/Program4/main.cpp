//
//  main.cpp
//  Program4
//
//  Created by Jay Brar & Jose Palomera on 3/3/20.
//  Copyright © 2020 Jay Brar & Jose Palomera. All rights reserved.
//

#include <iostream>
#include "Business.h"

using namespace std;

int main(int argc, const char * argv[]) {

    Business b("movieTesting.txt");
    b.buildCustomers("customerTesting.txt");
    b.executeCommands("commandsTesting.txt");
    
    
    return 0;
}
//Extra space before title and director
