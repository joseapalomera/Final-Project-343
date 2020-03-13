//
//  Return.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Return_h
#define Return_h

#include "Transaction.h"

using namespace std;

class Return : public Transaction
{
public:
    //Constructors
    Return();
    Return(int customerID, Movie *movie);
    ~Return();
    
};
#endif /* Return_h */
