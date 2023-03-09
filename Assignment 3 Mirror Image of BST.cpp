/*
Name:- Chirag Patil
Roll no : 2213795
Batch : SY 11-B
Date : 08-02-2023
                Assignment-3
Problem Statement: Create a Binary Search tree and find its mirror image. Print original & new tree
level wise. Find height & print leaf nodes.
*/
#include<iostream>
using namespace std;
class bst;
class node
{
    int data;
    node*left,*right;
public:
    friend class bst;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int data)
    {
        this->data=data; 
        left=NULL;
        right=NULL;
    }
};
class bst
{
    node* root;
    public:
    bst()
    {
        root = NULL;
    }
    void create();
    bool insert(int val);
    void mirror();
    void mirror(node*);
    void inorder();
    void inorder(node*);
};

void bst::create()
{
    int c,val;
    cout<<"How many numbers you want to insert ?"<<endl;
    cin>>c;
    
    for(int i=0;i<c;i++)
    {
        cout<<"Enter number : ";
        cin>>val;
        insert(val);
    }
}
bool bst:: insert(int data)
{
    node *p = new node(data);
    if(root==NULL)
    {
        root = p;
        return 1;
    }
    node *cur=root;
    node *par=root;
    while(cur!=NULL)
    {
        if(data>cur->data)
        {
            par=cur;
            cur=cur->right;
        }
        else if(data<cur->data)
        {
            par=cur;
            cur=cur->left;
        }
        else
        {
            cout<<endl<<"Already exists";
            return false;
        }
    }
    if(data>par->data)
    {
        par->right=p;
        return true;
    }
    else
    {
        par->left=p;
        return true;
    }
}
void bst::mirror()
{
    mirror(root);
}
void bst:: mirror(node* Node)
{
    if(Node==NULL)
    {
        return;
    }
    else
    {
        struct node* temp;
        mirror(Node->left);
        mirror(Node->right);

        temp = Node->left;
        Node->left=Node->right;
        Node->right=temp;

    }
}

void bst::inorder()
{
    inorder(root);
}
void bst::inorder(node* Node)
{
    if(Node)
    {
        inorder(Node->left);
        cout<<Node->data," ";
        inorder(Node->right);
    }
}
int main()
{
    bst b;
    b.create();
    cout<<"Constructed inorder  : ";
    b.inorder();
    b.mirror();
    cout<<endl<<"Mirror inorder : ";
    b.inorder();

    return 0;
}