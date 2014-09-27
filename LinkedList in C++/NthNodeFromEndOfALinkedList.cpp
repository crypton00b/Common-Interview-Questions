//Find the Nth node from the end of a linked list

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

using namespace std;

class NthNodeFromEnd
{
    private:
    struct node{
    int data;
    struct node *next;
    };
    public:
        NthNodeFromEnd();
       struct node *head,*tail;
       void add(int );
       void disp();
       int findNwithoutptr(int N,NthNodeFromEnd );
       int findNwithptr(int N,NthNodeFromEnd );
       int count();
    protected:

};
//constructor
NthNodeFromEnd::NthNodeFromEnd()
{
    head=tail=NULL;
}

//adding a new node
void NthNodeFromEnd::add(int data)
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

//display
void NthNodeFromEnd::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int NthNodeFromEnd::count()
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
//brute force approach
int NthNodeFromEnd::findNwithoutptr(int n,NthNodeFromEnd obj1)
{
    int m=obj1.count();
    struct node *temp=head;
    int x=(m-n)+1;
    int y=0;
    for(int i=0; i<x-1; i++)
    {
        temp=temp->next;
    }
    y=temp->data;
    return y;



}

//Efficient approach using 2 pointers

int NthNodeFromEnd::findNwithptr(int n,NthNodeFromEnd obj1)
{
    struct node *fptr,*sptr;
    fptr=sptr=head;
    for(int i=0; i<n; i++)
    {
        fptr=fptr->next;
    }
    while(fptr!=NULL)
    {
        fptr=fptr->next;
        sptr=sptr->next;
    }
    return sptr->data;
}


int main()
{
    NthNodeFromEnd obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(4);
    obj.add(7);
    obj.disp();
    printf("the value is \n");
    printf("%d\n",obj.findNwithoutptr(3,obj));
    printf("With ptr\n");
    printf("%d\n",obj.findNwithptr(3,obj));
    return 0;

}



