//check the length of a linked list is odd/even
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class CheckEvenorOdd
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
public:
    CheckEvenorOdd();
    struct node *head,*tail;
    void add(int );
    void disp();
    int count();
    void checkingNumber();


protected:
};

CheckEvenorOdd::CheckEvenorOdd()
{
    head=tail=NULL;
}

void CheckEvenorOdd::add(int data)
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
void CheckEvenorOdd::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int CheckEvenorOdd::count()
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


void CheckEvenorOdd::checkingNumber()
{
    struct node * fptr=head;
    while(fptr!=NULL && fptr->next!=NULL)
    {
        fptr=fptr->next->next;
        //      printf("1st test");
    }
    if(fptr==NULL)
    {
        printf("the number is even ");
    }
    else
    {
        printf("the number is odd");
    }

}


int main()
{
    CheckEvenorOdd obj;
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
    obj.checkingNumber();



}
