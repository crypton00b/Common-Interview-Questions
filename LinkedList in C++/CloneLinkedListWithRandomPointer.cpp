//A linked list with a next pointer and a randome pointer are given clone the list

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include<unordered_map>
using namespace std;

class list
{
private:

public:
    struct node
    {
        int data;
        struct node *next;
        struct node *random;
    };

    struct node *head,*tail;
    void add(int );
    list();
    void disp(struct node *);
    int count();
    struct node * clonelistwithash(struct node *);
    struct node *createrandomlist(struct node *);
    struct node *clonelistwithouthash(struct node *);


protected:
};
list::list()
{
    head=tail=NULL;
}

void list::add(int data)
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
void list::disp(struct node *h1)
{
    struct node *temp=h1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        cout<<temp->random->data<<"\n";
        temp=temp->next;
    }
}

list ::node *list::createrandomlist(struct node *h1)
{
    struct node *temp=h1;
    while(temp->next!=NULL)
    {
        if(temp->next->next==NULL)
        {
            temp->random=h1->next;
            break;
        }
        temp->random=temp->next->next;
        temp=temp->next;
    }
    temp->next->random=h1;
    return h1;

}
list::node * list::clonelistwithash(struct node *h1)
{
    unordered_map<struct node*,struct node *>ht;
    struct node *x=h1;
    struct node *y;
    while(x!=NULL)
    {
        y=(struct node *)malloc(sizeof(struct node));
        y->data=x->data;
        y->next=NULL;
        y->random=NULL;
        ht.insert(pair<struct node*,struct node *>(x,y));
        x=x->next;

    }
    x=h1;
    while(x!=NULL)
    {
        y=ht.at(x);
        y->random=ht.at(x->random);
        if(x->next==NULL)
        {
            y->next=NULL;
        }
        else
        {
            y->next=ht.at(x->next);

        }
        x=x->next;
    }
    return ht.at(h1);

}
list::node *list::clonelistwithouthash(struct node *h1)
{
    struct node *temp=h1,*temp2,*temp3;
    int flag=0;
    while(temp!=NULL)
    {

        temp2=(struct node *)malloc(sizeof(struct node));
        if(flag==0){
            temp3=temp2;
        flag=1;
        }
        temp2->data=temp->data;
        temp2->next=temp->random;
        temp->random=temp2;
        temp=temp->next;

    }
    temp=h1;
    while(temp!=NULL)
    {
        temp2=temp->random;
        temp2->random=temp2->next->random;
        temp=temp->next;
    }
    temp=h1;
    int i=0;
    while(temp!=NULL)
    {
        temp2=temp->random;

        temp->random=temp2->next;
        if(temp->next==NULL)
        {

            temp2->next=NULL;
        }
        else
        {
            temp2->next=temp->next->random;
        }  //cout<<"test"<<i++;
        temp=temp->next;

    }
    return temp3;
}


int main()
{
    list obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(12);
    obj.add(13);
    obj.disp(obj.createrandomlist(obj.head));
    obj.disp(obj.clonelistwithash(obj.createrandomlist(obj.head)));
    obj.disp(obj.clonelistwithouthash(obj.createrandomlist(obj.head)));

    //obj.disp1(obj.mergelist(obj.head,obj1.head));


    return 0;
}
