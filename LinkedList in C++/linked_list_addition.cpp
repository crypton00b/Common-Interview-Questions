#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
int getsize(struct node*);
class list_add
{
public:
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head,*tail;
    void add(int );
    void disp(struct node *);
    int getsize(struct node *);
    void swapnode(struct node *,struct node *);
    struct node *addsamesize(struct node *,struct node *,int *);
    void addlist(struct node *,struct node*,struct node **);

    list_add();
};


list_add::list_add()
{
    head=tail=NULL;
}

void list_add::add(int data)
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
void list_add::disp(struct node * temp1)
{
    struct node *temp=temp1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int list_add::getsize(struct node *h)
{
    int cnt=0;
    struct node *temp=h;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    printf("the count is \n");
    printf("%d\n",cnt);
    return cnt;
}
void list_add:: swapnode(struct node *h1,struct node *h2)
{
    struct node *temp=h1;
    h1=h2;
    h2=temp;

}

list_add:: node *list_add::addsamesize(struct node *h1,struct node *h2,int *carry)
{

    if(h1==NULL)return NULL;

    struct node *result=(struct node*)malloc(sizeof(struct node));
    result->next=addsamesize(h1->next,h2->next,carry);
    int sum=h1->data+h2->data;
    *carry=sum/10;
    sum%=10;
    result->data=sum;
    return result;

}
void list_add::addlist(struct node *h1,struct node *h2,struct node **result)
{
    if(h1==NULL)
    {
        *result=h2;
        return;
    }
    else if(h2==NULL)
    {

        *result=h1;
        return;
    }

    int size1=getsize(h1);
    int size2=getsize(h2);
    int diff=size1-size2;
    if(diff==0)
    {
        *result=addsamesize(h1,h2,&carry);

    }
    else if(diff<0)
    {
        swapnode(h1,h2);

    }else{

    for(int i=0,struct node *cur=h1; i<diff; i++)
    {
        cur=cur->next;
    }
    *result=addsamesize(cur,h2,&carry);



}

}




int main()
{

    list_add obj,obj1,rs;

    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);

    obj.disp(obj.head);

    obj1.add(9);
    obj1.add(5);
    obj1.add(6);
    obj1.add(1);


    obj1.disp(obj1.head);

    obj1.addlist(obj.head,obj1.head,&rs.head);

    return 0;

}
