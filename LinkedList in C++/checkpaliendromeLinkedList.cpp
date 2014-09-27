#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include<unordered_map>

using namespace std;


class checkpaliendrome
{
    public:
        checkpaliendrome();
        struct node
    {
        int data;
        struct  node *next;

    };
    struct node *head,*tail;
    void add(int );
    void disp();
    int count();
    void checkpalien();
    protected:
    private:
};



checkpaliendrome::checkpaliendrome()
{
    head=tail=NULL;
}
void checkpaliendrome::add(int data)
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
void checkpaliendrome::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int checkpaliendrome::count()
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
void checkpaliendrome::checkpalien()
{
    struct node *fptr=head,*sptr=head,*head1=NULL,*head2=NULL;
    while(fptr!=NULL && fptr->next!=NULL)
    {

        fptr=fptr->next->next;
        sptr=sptr->next;
    }
    printf("value is \n%d",fptr->data);
    if(fptr==NULL)
    {
        head1=head;
        while(head->next!=sptr)
        {
            head=head->next;

        }
        head->next=NULL;
        head2=sptr;
        tail->next=NULL;
    }
    else
    {
        printf("\n%d",sptr->data);
        head1=head;
        while(head->next!=sptr)
        {

            head=head->next;
        }

        head->next=NULL;
        head2=sptr->next;
        tail->next=NULL;
    }


    struct node *temp=NULL,*newnode=NULL;
    while(head2!=NULL)
    {

        newnode=head2->next;
        head2->next=temp;
        temp=head2;
        head2=newnode;


    }
    //printf("\n%d",temp->data);

    int flag=0;
    while(head1!=NULL && temp!=NULL)
    {
        printf("\n%d\n%d",head1->data,temp->data);
        if(head1->data!=temp->data)
        {
            flag=1;
            break;
        }
        head1=head1->next;
        temp=temp->next;
    }
    if(flag)
    {
        printf("it is not a paliendrome");
    }
    else
    {
        printf("it is  a paliendrome");
    }
}

int main()
{

    checkpaliendrome obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(4);
    obj.add(9);
    obj.add(8);
    obj.add(6);
    obj.add(5);
    obj.add(3);
    obj.add(2);
    obj.disp();

    obj.checkpalien();
    return 0;
}

