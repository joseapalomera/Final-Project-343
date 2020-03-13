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
    
    static const int sizeOfTable = 100; //Establishes the size of the table
    static const int hashTable = 101;
    
private:
    
    //Struct created to hold the Customer object
    struct item
    {
        Customer *c;
        item *next;
    };
    
    //Struct that will help insert the item by creating a head for the current item in the HashTable
    struct hashStore
    {
        item *head;
    };
    
    hashStore table[sizeOfTable];   //Array that holds the hashStore objects which contains the items
    
public:
    HashTable();
    ~HashTable();
    
    bool addCustomer(Customer *c);  //Method that adds a customer to the table
    Customer* getCustomer(int custId);  //Method that retrieves a customer from the table
    
};
#endif /* HashTable_h */
