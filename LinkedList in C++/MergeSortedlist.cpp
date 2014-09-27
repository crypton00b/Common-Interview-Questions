
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Mergesortlist
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
    Mergesortlist();
    void disp1(struct node *);
    void disp();
    int count();
    struct node * mergelist(struct node *,struct node *);

protected:
};

Mergesortlist::Mergesortlist()
{
    head=tail=NULL;
}

void Mergesortlist::add(int data)
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
void Mergesortlist::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int Mergesortlist::count()
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

void Mergesortlist::disp1(struct node *h)
{
    struct node *temp=h;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
Mergesortlist:: node * Mergesortlist::mergelist(struct node *h1,struct node *h2)
{
    struct node *result=NULL;
    if(h1==NULL&&h2==NULL)return 0;
    if(h2==NULL)return h1;
    if(h1==NULL)return h2;
    if(h1->data<=h2->data)
    {
        result=h1;
        result->next=mergelist(h1->next,h2);
    }
    else
    {
        result=h2;
        result->next=mergelist(h1,h2->next);
    }
    return result;

}

int main()
{
    Mergesortlist obj,obj1;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(12);
    obj.add(13);
    printf("the first list\n");
    obj.disp();
    printf("\n\n");
    obj1.add(9);
    obj1.add(11);
    obj1.add(15);
    obj1.add(16);
    obj1.add(17);
    obj1.add(18);
    obj1.add(19);
    obj1.add(20);
    printf("the sec list\n");
    obj1.disp();
    printf("\n\n");

    obj.disp1(obj.mergelist(obj.head,obj1.head));


    return 0;
}

