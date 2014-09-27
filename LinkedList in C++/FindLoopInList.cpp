//Find loop in a linked list if there is and the length of the loop
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include<unordered_map>

using namespace std;

class LoopedList
{
    private:
    struct node{
    int data;
    struct node *next;
    };
    public:
        LoopedList();
       struct node *head,*tail;
       void add(int );
       void disp();
       int count();
       void makeLoop(int n);
       void FindPathWithHash();
       void FindpathWithPtr(LoopedList obj);
       void CountofLoop(struct node *,struct node *);
    protected:

};


LoopedList::LoopedList()
{
    head=tail=NULL;
}
void LoopedList::add(int data)
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
void LoopedList::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int LoopedList::count()
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

//making a loop for usage
void LoopedList::makeLoop(int n)
{
    struct node * temp=head;
    for(int i=1; i<n; i++)
    {
        temp=temp->next;
    }
    tail->next=temp;

}

//hash table approach to find the loop
void LoopedList::FindPathWithHash()
{
    unordered_map<int,struct node * >m;
    int i=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        for(unordered_map<int,struct node * >::iterator it=m.begin(); it!=m.end(); ++it)
        {
            if(it->second==temp)
            {
                goto label;
            }
        }
        // m.insert(unordered_map<int,struct node * >::iterator it++,temp);
        m.insert(pair<int,struct node *>(++i,temp));
        temp=temp->next;

    }
label:
    printf(" the circle is on\n");
    printf("%d",temp->data);


}

//Efficient method using 2 pointers
void LoopedList::FindpathWithPtr(LoopedList obj1)
{
    struct node * sptr=head,*fptr=head;
    int loopnotexist=0;
    while(fptr&&sptr&&fptr->next)
    {
        sptr=sptr->next;
        fptr=fptr->next->next;

        if(fptr==sptr)
        {
            loopnotexist=1;
            break;
        }



    }
    if(loopnotexist==1)
    {

        obj1.CountofLoop(fptr,sptr);

        sptr=head;

        //fptr=fptr->next;
        while(sptr!=fptr)
        {

            sptr=sptr->next;
            fptr=fptr->next;

        }
        printf("the loop for ptr case is\n");
        printf("%d",fptr->data);

    }
    else
    {
        printf("Loop doesnt exit");
    }

}

//method to find the count of the loop
void LoopedList::CountofLoop(struct node* fptr1,struct node *sptr1)
{
    int count=1;
    fptr1=fptr1->next;
    while(fptr1!=sptr1)
    {
        fptr1=fptr1->next;
        count++;
    }
    printf(" the count of the loop is\n");
    printf("%d",count);

}
int main()
{

    LoopedList obj;
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
    obj.disp();
    // will make a infinite loop as there is no null point to this
    obj.makeLoop(4);
    //obj.disp();
    obj.FindPathWithHash();
    obj.FindpathWithPtr(obj);
    return 0;
}
