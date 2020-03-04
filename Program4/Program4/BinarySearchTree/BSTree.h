//
//  BSTree.h
//  Program4
//
//  Created by Jose Palomera on 3/4/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h

#include "Movie.h"
using namespace std;

class BSTree
{
public:
    BSTree();
    ~BSTree();
    
    bool Insert(Movie *inserting);
    
    // displays the contents of a tree to cout
    void Display() const;
    void Empty();
    bool isEmpty() const;
    
private:
    struct Node
    {
        Movie *pMov = NULL;
        Node *right = NULL;
        Node *left = NULL;
    };
    Node *root;
    
    // Recursive helpers
    bool RecInsert(Node* currentNode, Movie* inserting);
    void RecPrint(Node* currentNode) const;
};

#endif /* BSTree_h */
