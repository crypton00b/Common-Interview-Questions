
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;



class PrintfromEnd
{
    private:
    struct node
    {
        int data;
        struct node *next;
    };
public:
    PrintfromEnd();
    struct node *head,*tail;
    void add(int );
    void disp();
    int count();
    void printing(struct node *);


protected:
};


PrintfromEnd::PrintfromEnd()
{
    head=tail=NULL;
}

void PrintfromEnd::add(int data)
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
void PrintfromEnd::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int PrintfromEnd::count()
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


void PrintfromEnd::printing(struct node *h)
{
    if(h==NULL)return;

    else{
    printing(h->next);
    printf("%d\n",h->data);

    }

}


int main()
{
    PrintfromEnd obj;
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
    obj.printing(obj.head);

return 0;

}

