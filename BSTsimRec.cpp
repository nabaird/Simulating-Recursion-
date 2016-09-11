#include<iostream>
#include<stack>

#include "BSTsimRec.h"

using namespace std;


void bst::InOrderTrav()//Initiates the traversal 
{
    InOrderRecursion(root);
}

void bst::InOrderRecursion(node *nodePntr)//prints on screen the in-order traversal 
{
    if(nodePntr->left)
    {
        InOrderTest(nodePntr->left);
    }
    
    cout<<nodePntr->value<<"\n";

    if(nodePntr->right)
    {
        InOrderTest(nodePntr->right);
    }
}

void bst::InOrder()//Simulates recursion for an in-order traversal 
{
    stack<node*> pointerStack;//a stack is used to keep nodes we want to return to later
    node *nodePntr = root;

    do
    {
        pointerStack.push(nodePntr);
        if(nodePntr->left)//for any subtree, we want to first process the left-most node. So we traverse left while adding nodes to the top of the stack
        {
            nodePntr=nodePntr->left;
        }
        else
        {
            do//when there is no left node we need to back track through the stack, popping off nodes (and processing their data) until we find a node with a right node
            {
                if(!pointerStack.empty())
                {
                    nodePntr=pointerStack.top();
                    pointerStack.pop();
                    cout<<nodePntr->value<<"\n";
                }
                else
                {
                    break;
                }
            }
            while(!nodePntr->right);

            nodePntr=nodePntr->right;//Either we will repeat the process with a right node, or we broke out of the sub-loop because the stack was empty, in which case we are done (nodePntr=nullptr)
        }
    }
    while(nodePntr!=nullptr);
}

void bst::PreOrderTrav()//Initiates the traversal 
{
    PreOrderRecursion(root);
}

void bst::PreOrderRecursion(node *nodePntr)//prints on screen the pre-order traversal 
{
    cout<<nodePntr->value<<"\n";
    
    if(nodePntr->left)
    {
        PreOrderTest(nodePntr->left);
    }
    
    if(nodePntr->right)
    {
        PreOrderTest(nodePntr->right);
    }
}


void bst::PreOrder()//Simulates recursion for an pre-order traversal 
{
    stack<node*> pointerStack;
    node *nodePntr = root;

    do
    {
        pointerStack.push(nodePntr);
        cout<<nodePntr->value<<"\n";//for pre-order traversals, processing the data occurs when nodes are added to the stack 
        if(nodePntr->left)
        {
            nodePntr=nodePntr->left;
        }
        else
        {
            do
            {
                if(!pointerStack.empty())
                {
                    nodePntr=pointerStack.top();
                    pointerStack.pop();
                }
                else
                {
                    break;
                }
            }
            while(!nodePntr->right);

            nodePntr=nodePntr->right;
        }
    }
    while(nodePntr!=nullptr);
}





