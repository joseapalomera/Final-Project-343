//
//  Transaction.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef Transaction_h
#define Transaction_h

#include <iostream>

using namespace std;

class Transaction
{
public:
    Transaction();
    ~Transaction();
    
    void setCustomerID(int customerID);
    
    virtual void doTrans();
    
    friend ostream& operator<<(ostream &out, const Transaction &t);
    virtual void print(ostream &out)const;
    
private:
    int customerID;
    //Movie movie;
};

#endif /* Transaction_h */
