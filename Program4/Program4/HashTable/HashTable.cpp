//
//  HashTable.cpp
//  Program4
//
//  Created by Jose Palomera on 3/3/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"

HashTable::HashTable()
{
    tableSize = 100;
    
    hashTable = new item[tableSize];
    
    for(int i = 1; i < sizeof(hashTable); i++)
    {
        //hashTable[i] = new item;
        hashTable[i].next = nullptr;
    }

}

HashTable::~HashTable()
{
    
}

int HashTable::hash(int number)
{
    
    int hash = number;
    int index;
    
    index = hash % tableSize;
    
    return index;
}
/*
void HashTable::addCustomer(Customer *cust)
{
    int index = hash(cust->getId());
    
    if(hashTable[index].c == nullptr)
    {
        hashTable[index].c = cust;
    }
    else
    {
        item *ptr = &hashTable[index];
        item *n = new item;
        n->c = cust;
        n->next = nullptr;
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
            
        ptr->next = n;
    }
}
*/
void HashTable::display()
{
    for(int i = 0; i < sizeof(hashTable); i++)
    {
        cout << hashTable[i].c << endl;
    }
    
}
    
