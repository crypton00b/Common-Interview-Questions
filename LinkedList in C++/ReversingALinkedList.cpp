
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include<unordered_map>

using namespace std;
class ReversingList
{
   private:

public:
 struct node
    {
        int data;
        struct node *next;
    };

    struct node *head,*tail;
    void add(int );
    void disp(struct node *);
    int count();
    ReversingList();
    struct node * reverse();


protected:
};


ReversingList::ReversingList()
{
    head=tail=NULL;
}

void ReversingList::add(int data)
{

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=NULL;
        tail->next=temp;
        tail=temp;

    }

}
void ReversingList::disp(struct node * temp1)
{
    struct node *temp=temp1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int ReversingList::count()
{
    int cnt=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    printf("the count is \n");
    printf("%d\n",cnt);
    return cnt;
}
// Imporatant point to note while u are returning a struct pointer for a function inside a class
  ReversingList::  node * ReversingList :: reverse()
{
    struct node *temp=NULL,*newnode=NULL;
    while(head!=NULL)
    {

        newnode=head->next;
        head->next=temp;
        temp=head;
        head=newnode;


    }

return temp;
}



int main()
{

    ReversingList obj;

    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(11);
    obj.add(12);
    obj.add(13);
    obj.disp(obj.head);
   // obj.reverse();
    obj.disp(obj.reverse());

    return 0;

}
