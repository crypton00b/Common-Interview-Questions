//Tortoise and hare problem..........finf the middle of a linkedlist in one go
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class MiddleofLinkedList
{

    private:
    struct node
    {
        int data;
        struct node *next;
    };
public:

    struct node *head,*tail;
     MiddleofLinkedList();
    void add(int );
    void disp();
    int count();
    int returnmiddle();

protected:
};


MiddleofLinkedList::MiddleofLinkedList()
{
    head=tail=NULL;
}

void MiddleofLinkedList::add(int data)
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
void MiddleofLinkedList::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int MiddleofLinkedList::count()
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


int MiddleofLinkedList::returnmiddle()
{
    struct node * fptr=head,* sptr=head;
    while(fptr!=NULL && fptr->next!=NULL)
    {
        fptr=fptr->next->next;
        sptr=sptr->next;
  //      printf("1st test");
    }
     //printf("2nd test");
    return sptr->data;

}


int main()
{
    MiddleofLinkedList obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(11);
    obj.add(12);
    //obj.add(13);
    obj.disp();
    printf("the value is \n%d\n",obj.returnmiddle());
    return 0;


}
