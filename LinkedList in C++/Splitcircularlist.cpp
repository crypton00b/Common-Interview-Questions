#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include<unordered_map>

class Splitcircularlist
{
public:
    struct node
    {
        int data;
        struct  node *next;

    };
    struct node *head,*tail;
    Splitcircularlist();
    void add(int );
    void disp(struct node *);
    int count();
    void makecircular();
    void makelist(Splitcircularlist);

protected:
private:
};


using namespace std;




Splitcircularlist::Splitcircularlist()
{
    head=tail=NULL;
}
void Splitcircularlist::add(int data)
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
void Splitcircularlist::disp(struct node *head1)
{
    struct node *temp=head1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int Splitcircularlist::count()
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
void Splitcircularlist::makecircular()
{
    tail->next=head;
}
void Splitcircularlist::makelist(Splitcircularlist scr)
{
    struct node *fptr=head,*sptr=head,*head1=NULL,*head2=NULL;
    while(fptr->next!=head && fptr->next->next!=head)
    {
        fptr=fptr->next->next;
        sptr=sptr->next;
    }
    if(fptr->next->next==head){
    fptr=fptr->next;
    }
head1=head;
head2=sptr->next;
sptr->next=NULL;
fptr->next=NULL;
scr.disp(head1);
//scr.disp(head2);


}

int main()
{

    Splitcircularlist obj;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(4);
    obj.add(7);
    obj.add(9);
    obj.add(11);
    obj.add(12);
    obj.add(13);
    obj.add(15);
    obj.disp(obj.head);
    // will make a infinite loop as there is no null point to this
    obj.makecircular();
    //obj.disp();
    obj.makelist(obj);
    return 0;
}

