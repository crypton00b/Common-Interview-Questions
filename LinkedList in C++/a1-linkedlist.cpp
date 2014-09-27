
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class shuffleLinkedList
{

    private:
    struct node
    {
        int data;
        struct node *next;
    };
public:

    struct node *head,*tail;
     shuffleLinkedList();
    void add(int );
    void disp(struct node *);
    int count();
    struct node * returnmiddle();
    struct node *shuffled(struct node *,struct node *);

protected:
};


shuffleLinkedList::shuffleLinkedList()
{
    head=tail=NULL;
}

void shuffleLinkedList::add(int data)
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
void shuffleLinkedList::disp(struct node *h)
{
    struct node *temp=h;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int shuffleLinkedList::count()
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


shuffleLinkedList::node * shuffleLinkedList::returnmiddle()
{
    struct node * fptr=head,* sptr=head;
    while(fptr!=NULL && fptr->next!=NULL)
    {
        fptr=fptr->next->next;
        sptr=sptr->next;
  //      printf("1st test");
    }
     //printf("2nd test");
    return sptr;

}

shuffleLinkedList::node * shuffleLinkedList::shuffled(struct node *head,struct node *middle){
struct node *temp,*i=head,*j=middle,*l=head;
while(i->next!=middle){
i=i->next;
}
struct node *k=i;
i=head;
while(i!=k){
temp=i->next;
i->next=j;
k->next=j->next;
j->next=temp;
i=temp;
j=k->next;

}

return l;
}
int main()
{
    shuffleLinkedList obj;
    obj.add(1);
    obj.add(3);
    obj.add(5);
    obj.add(7);
    obj.add(2);
    obj.add(4);
    obj.add(6);
    obj.add(8);
    obj.disp(obj.head);
    obj.disp(obj.shuffled(obj.head,obj.returnmiddle()));
    return 0;


}
