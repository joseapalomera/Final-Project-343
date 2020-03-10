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
private:
    struct item
    {
        Customer *c;
        item *next;
    };
    
    int tableSize;
    
    item* hashTable;
    
public:
    HashTable();
    ~HashTable();
    int hash(int number);
    
    void addCustomer(Customer *c);
    void display();
    
};
#endif /* HashTable_h */
