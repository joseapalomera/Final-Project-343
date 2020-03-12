//
//  Borrow.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Borrow_h
#define Borrow_h

#include "Transaction.h"

using namespace std;

class Borrow : public Transaction
{
public:
    Borrow();
    Borrow(int customerID, Movie *movie);
    ~Borrow();
    
};
#endif /* Borrow_h */
