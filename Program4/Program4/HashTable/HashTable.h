//
//  HashTable.h
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include "Customer.h"
using namespace std;

class HashTable
{
    
    static const int sizeOfTable = 100;
    static const int hashTable = 101;
    
private:
    
    struct item
    {
        Customer *c;
        item *next;
    };
    
    struct hashStore
    {
        item *head;
    };
    
    hashStore table[sizeOfTable];
    
public:
    HashTable();
    ~HashTable();
    
    bool addCustomer(Customer *c);
    Customer* getCustomer(int custId);
    
};
#endif /* HashTable_h */
