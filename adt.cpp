#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node {
int data;
struct node *next,*ref;
};
void makeset(struct node *head[],int);
void Union(struct node*,struct node*);
void findset(struct node *head[],int t);
int main()
{
   int n,i,j;
   cout<<"Enter the value of n"<<endl;
   cin>>n;
   struct node *head[n],*temp;
   int a[n][n];
   cout<<"Enter the adjacency matrix"<<endl;
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        cin>>a[i][j];
    makeset(head,n);
    cout<<"Makeset complete"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i)
            {
                if(a[i][j]==1)
                Union(head[i],head[j]);
            }
        }
    }
    cout<<"Enter the element to find "<<endl;
    int t;
    cin>>t;
    findset(head,t);
}
void makeset(struct node *head[],int n)
{
    int i;
    struct node *temp;
    for(i=0;i<n;i++)
    {
        temp=(struct node*) malloc(sizeof(struct node));
        temp->data=i+1;
       temp->next=NULL;
        temp->ref=temp;
        head[i]=temp;
    }
}
void Union(struct node *t1,struct node *t2)
{
    struct node *temp=t1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=t2;
    t2->ref=t1->ref;
    cout<<"Union of "<<t1->data<<" and "<<t2->data<<" is complete"<<endl;
}
void findset(struct node *head[],int t)
{
    cout<<(head[t-1]->ref)->data;
}
