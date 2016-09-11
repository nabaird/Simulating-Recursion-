#include<iostream>
#include<stack>

#include "BSTsimRec.h"

using namespace std;

bst::node::node(int x)
{
    value = x;
    left = nullptr;
    right = nullptr;
}

bst::bst()
{
    root = nullptr;
}

bst::~bst()
{
    if(root)
    {
        Erase(root);
    }
}

bool bst::Add(int x)
{
    if(root)
    {
        return FindLoc(x,root);
    }
    else
    {
        root = new node(x);
        return true;
    }
}

bool bst::Remove(int x)
{
    node* reader = nullptr;
    node* thisRoot = root;
    bool done = false;

    while(thisRoot && !done)
    {
        if(x<thisRoot->value)
        {
            reader = thisRoot;
            thisRoot=thisRoot->left;
        }
        else if(x>thisRoot->value)
        {
            reader = thisRoot;
            thisRoot=thisRoot->right;
        }
        else
        {
            done = true;
        }
    }

    if(thisRoot)//if the node was found
    {
        if(thisRoot->left && thisRoot->right)//node has 2 children
        {

            node* valFinder;
            valFinder = thisRoot->right;
            while(valFinder->left)
            {
                valFinder=valFinder->left;
            }
            int swapVal = valFinder->value;
            Remove(swapVal);

            thisRoot->value = swapVal;
        }
        else if(thisRoot->left)//if node has a left child
        {
            if(x<reader->value)
            {
                reader->left = thisRoot->left;
                delete thisRoot;

            }
            else
            {
                reader->right = thisRoot->left;
                delete thisRoot;

            }
        }
        else if(thisRoot->right)//if node has a right child
        {
            if(x<reader->value)
            {
                reader->left = thisRoot->right;
                delete thisRoot;

            }
            else
            {
                reader->right = thisRoot->right;
                delete thisRoot;

            }
        }
        else//node has 0 children
        {
            delete thisRoot;
            if(x<reader->value)
            {
                reader->left = nullptr;
            }
            else
            {
                reader->right = nullptr;
            }

        }
    return true;
    }
    else
    {
        return false; //the node was not found
    }
}

bool bst::Search(int x)
{
    node* thisRoot= root;
    while(thisRoot)
    {
        if(x<thisRoot->value)
        {
            thisRoot=thisRoot->left;
        }
        else if(x>thisRoot->value)
        {
            thisRoot=thisRoot->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void bst::Clear()
{
    if(root)
    {
       Erase(root);
    }
    root=nullptr;
}

void bst::InOrder()
{
    stack<node*> pointerStack;
    node *nodePntr = root;

    do
    {
        pointerStack.push(nodePntr);
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
                    cout<<nodePntr->value<<"\n";
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

void bst::PreOrder()
{
    stack<node*> pointerStack;
    node *nodePntr = root;

    do
    {
        pointerStack.push(nodePntr);
        cout<<nodePntr->value<<"\n";
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

void bst::InOrderTrav()
{
    InOrderTest(root);
}

void bst::InOrderTest(node *nodePntr)
{

    cout<<nodePntr->value<<"\n";
    if(nodePntr->left)
    {
        InOrderTest(nodePntr->left);
    }


    if(nodePntr->right)
    {
        InOrderTest(nodePntr->right);
    }
}

bool bst::FindLoc(int x, node* thisRoot)//Only called when root is non-null
{
    node* reader = nullptr;
    while(thisRoot)
    {
        if(x<thisRoot->value)
        {
            reader = thisRoot;
            thisRoot=thisRoot->left;
        }
        else if(x>thisRoot->value)
        {
            reader = thisRoot;
            thisRoot=thisRoot->right;
        }
        else if(x==thisRoot->value)
        {
            return false;
        }
    }
    if(x<reader->value)
    {
        reader->left=new node(x);
    }
    else
    {
        reader->right=new node(x);
    }

    return true;
}

void bst::Erase(node* thisRoot)
{
    if(thisRoot->left)
    {
        Erase(thisRoot->left);
    }
    if(thisRoot->right)
    {
        Erase(thisRoot->right);
    }

    delete thisRoot;
}

int main()
{
    bst p;
//    for(int i=0; i<10000000; i++)
//    {
//        p.Add(rand()%10000000);
//    }

//
    p.Add(5);
    p.Add(78);
    p.Add(81);
    p.Add(2);
    p.Add(21);
 p.Add(1);
  p.Add(3);
 p.Add(-11);
  p.Add(-112);
    p.Add(16612);
      p.Add(145612);
    p.InOrder();
    p.PreOrder();
}





