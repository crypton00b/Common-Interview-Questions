//Insert node in the  correct place in a linked list
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include<unordered_map>

using namespace std;
class InsertNodeInSortedList
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
public:

    struct node *head,*tail;
    void add(int );
    void disp();
    int count();
    InsertNodeInSortedList();
    void InsertingNode(int );

protected:
};


InsertNodeInSortedList::InsertNodeInSortedList()
{
    head=tail=NULL;
}

void InsertNodeInSortedList::add(int data)
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
void InsertNodeInSortedList::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int InsertNodeInSortedList::count()
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


//effiecent method to insert the node
void InsertNodeInSortedList::InsertingNode(int dat1)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    struct node *x=head;
    while(dat1>x->next->data)
    {
        x=x->next;
    }
    temp->data=dat1;
    temp->next=x->next;
    x->next=temp;

}


int main()
{
    InsertNodeInSortedList obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(11);
    obj.add(12);
    obj.add(13);
    obj.disp();

    obj.InsertingNode(7);
    obj.disp();

    return 0;
}


