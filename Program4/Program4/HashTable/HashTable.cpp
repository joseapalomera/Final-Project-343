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

    for(int i = 0; i < sizeOfTable; i++)
    {
        table[i].head = nullptr;
    }

}

HashTable::~HashTable()
{
    
}

bool HashTable::addCustomer(Customer *cust)
{
    int index = cust->getId() % hashTable;
    
    item *temp = new item;
    temp->c = cust;
    temp->next = nullptr;
    
    if(table[index].head == nullptr)
    {
        table[index].head = temp;
    }
    else
    {
        item *ptr = table[index].head;
        
        while(ptr->next != nullptr)
        {
            if(cust->getId() == ptr->c->getId())
            {
                cout << "Duplicate Exists: Customer " << cust->getId() << endl;
                temp->c = nullptr;
                delete temp;
                temp = nullptr;
                return false;
            }
            
            ptr = ptr->next;
        }
            
        ptr->next = temp;
        
    }
    
    
    return true;
}
    
Customer* HashTable::getCustomer(int custId)
{
    int index = custId % hashTable;
    
    if(table[index].head == nullptr)
    {
        return nullptr;
    }
    else{
        item *cur = table[index].head;
        
        while(cur != nullptr)
        {
           if(cur->c->getId() == custId)
           {
               return cur->c;
           }
            
            cur = cur->next;
        }
    }
    
    return nullptr;
}
