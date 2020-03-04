//
//  BSTree.cpp
//  Program4
//
//  Created by Jose Palomera on 3/4/20.
//  Copyright © 2020 Jose Palomera. All rights reserved.
//

#include <stdio.h>
#include "BSTree.h"

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    this->Empty();
}

bool BSTree::Insert(Movie *inserting)
{
    // Make inserting the root if the Tree is empty
    if (root == NULL)
    {
        root = new Node;
        root->pMov = inserting;
        return true;
    }
    // Call the recursive insert method that will put it in the appropriate position
    else
    {
        Node *current = root;
        return RecInsert(current, inserting);
    }
}

void BSTree::Display() const
{
    // Tree is empty if the root is null
    if (root == NULL)
    {
        cerr << "ERROR: No Movies currently in the system" << endl;
    }
    // Calls a recursive method that prints each Node in the Tree
    else
    {
        RecPrint(root);
    }
}

void BSTree::Empty()
{
    delete root;
    root = NULL;
}

bool BSTree::isEmpty() const
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BSTree::RecInsert(Node* currentNode, Movie* inserting)
{
    // If the inserting Movie is greater than that of the current Node
    if (inserting > (currentNode->pMov))
    {
        // If we reach the end of a branch where we can add the Movie
        if (currentNode->right == NULL)
        {
            Node *insertMovie = new Node();
            insertMovie->pMov = inserting;
            currentNode->right = insertMovie;
            return true;
        }
        // Recursive call until we reach the end of a branch
        else
        {
            return RecInsert(currentNode->right, inserting);
        }

    }
    // If the inserting Movie is lesser than that of the current Node
    else if(inserting < (currentNode->pMov))
    {
        // If we reach the end of a branch where we can add the Movie
        if (currentNode->left == NULL)
        {
            Node *insertMovie = new Node();
            insertMovie->pMov = inserting;
            currentNode->left = insertMovie;
            return true;
        }
        // Recursive call until we reach the end of a branch
        else
        {
            return RecInsert(currentNode->left, inserting);
        }

    }
    // Failure to add inserting to the Tree
    else
    {
        return false;
    }
}


void BSTree::RecPrint(Node* currentNode) const
{
    // If the current Node has Nodes for both both branches
    if (currentNode->left != NULL && currentNode->right != NULL)
    {
        RecPrint(currentNode->right);
        cout << *(currentNode->pMov) << endl;
        RecPrint(currentNode->left);
    }
    // If the current Node only has a Node for the left branch
    else if (currentNode->left != NULL)
    {
        cout << *(currentNode->pMov) << endl;
        RecPrint(currentNode->left);
    }
    // If the current Node only has a Node for the right branch
    else if (currentNode->right != NULL)
    {
        cout << *(currentNode->pMov) << endl;
        RecPrint(currentNode->right);
    }
    // If the root is the only Node in the tree
    else
    {
        cout << *(currentNode->pMov) << endl;
    }

}
