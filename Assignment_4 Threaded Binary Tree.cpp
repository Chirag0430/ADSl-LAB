/*
Name:- Chirag Patil
Roll no : 2213795
Batch : SY 11-B
Date : 08-03-2023
                Assignment-4
Problem Statement: Create an inorder threaded binary search tree and perform the traversals.
*/
#include<iostream>
using namespace std;
class Node
{
public:
    int data,lbit,rbit;
    Node *left,*right;
};
class TBT
{
public:
    Node *head,*root;
    TBT()
    {
        root=NULL;
        head=NULL;
    }
    void create(int num);
    void insert(Node*trav, Node*temp);
    void inorder( Node*temp);
    void display();
};
void TBT :: create(int num)
{
    Node *trav,*temp;
    temp= new Node();
    temp->data=num;
    temp->lbit=0;
    temp->rbit=0;
    if(root==NULL)
    {
        head=new Node;
        head->data=65656;
        head->lbit=1;
        head->rbit=1;
        head->left=temp;
        head->right=head;
        temp->left=head;
        temp->right=head;
        root=temp;
    }
    else{
        trav=root;
        insert(trav,temp);
    }

}
void TBT::insert(Node *trav, Node*temp)
{
    if(temp->data<trav->data)
    {
        if(trav->lbit==0)
        {
            temp->left=trav->left;
            temp->right=trav;
            trav->left=temp;
            trav->lbit=1;
        }
        else
        {
            insert(trav->left,temp);
        }
    }
    if(temp->data>trav->data)
    {
        if(trav->rbit==0)
        {
            temp->right=trav->right;
            temp->left=trav;
            trav->right=temp;
            trav->rbit=1;
        }
        else
        {
            insert(trav->right,temp);
        }
    }
}
void TBT :: inorder(Node *temp)
{
    if(root==NULL)
    {
        cout<<"Tree not present";
    }
    else
    {
        while(temp!=head)
        {
            while(temp->lbit==1)
            {
                temp=temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rbit==0 && temp->right!=head)
            {
                temp=temp->right;
                cout<<temp->data<<" " ;
            }
            temp=temp->right;

        }
    }
}
void TBT :: display()
{
    Node *temp=root;
    int n,data;
    cout<<"Enter the number of data you want to insert: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element no "<<i+1<<" : ";
        cin>>data;
        create(data);
    }

    cout<<"Inoder Traversal : ";
    inorder(root);


}

int main()
{
    TBT t;
    t.display();
}
