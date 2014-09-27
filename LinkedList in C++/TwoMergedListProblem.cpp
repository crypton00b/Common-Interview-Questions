//2 linked list merge at a point and then go in the same way...find the point where it merges
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class twomergelist
{

private:
    struct node
    {
        int data;
        struct node *next;
    };
public:

    struct node *head,*tail;
    void add(int );
    void disp();
    int count();
    twomergelist();
    void InsertingNode(int );
    void createmergelist(int n,struct node *);
    void usingstack(struct node *,struct node *);
    void usingptrs(struct node *,struct node *);
    void usinghash(struct node *,struct node *);
    void bruteforce(struct node *,struct node *);

protected:
};
twomergelist::twomergelist()
{
    head=tail=NULL;
}

void twomergelist::add(int data)
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
void twomergelist::disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int twomergelist::count()
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

void twomergelist::createmergelist(int n,struct node *h)
{
    struct node *temp=head;
    for(int i=1; i<n; i++)
    {
        temp=temp->next;

    }
    struct node *temp1=h;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;

}

void twomergelist::bruteforce(struct node *h1,struct node *h2){
for(struct node *i=h1;i!=NULL;i=i->next){
for(struct node *j=h2;j!=NULL;j=j->next){
if(i==j){
    printf("the value thru brute force is \n%d\n",i->data);
    goto label;

}

}

}
label:
printf("nothing");


}
//using stacks
void twomergelist::usingstack(struct node *h1,struct node *h2)
{
    stack<struct node *> s1,s2;
    while(h1->next!=NULL)
    {
        s1.push(h1);
        h1=h1->next;


    }
    while(h2->next!=NULL)
    {

        s2.push(h2);
        h2=h2->next;

    }

//printf(" the top  is %p%p\n",s1.top(),s2.top());
//pop function doesn't return any value...........it just removes it.......u have to use top() to read the value
    struct node * temp1=NULL,*temp2=NULL;
    while(temp1==temp2)
    {
        temp1=s1.top();
        s1.pop();
        temp2=s2.top();
        s2.pop();
    }
    printf(" the value is");
    printf("%d",temp1->next->data);
}

//the most effiecient way
void twomergelist::usingptrs(struct node *h1,struct node * h2)
{
    int cnt1=0,cnt2=0;
    struct node *temp1=h1,*temp2=h2;
    while(temp1->next!=NULL)
    {
        cnt1++;
        temp1=temp1->next;

    }
    while(temp2->next!=NULL)
    {
        cnt2++;
        temp2=temp2->next;

    }
    int diff=0;
    if(cnt1>cnt2)
    {
        diff=cnt1-cnt2;
        temp1=h1;
        temp2=h2;
    }
    else
    {
        diff=cnt2-cnt1;
        temp1=h2;
        temp2=h1;
    }
    printf("th diff is \n%d\n",diff);
    for(int i=0; i<diff; i++)
    {

        temp1=temp1->next;

    }

    while(temp1!=temp2)
    {
       // printf("the first while\n");
        temp1=temp1->next;
        temp2=temp2->next;
    }
    printf("the  value for the pointers \n%d\n",temp1->data);

}



void twomergelist::usinghash(struct node * h1,struct node *h2)
{
    unordered_map<int,struct node * >m;
    int i=0;
    while(h1->next!=NULL)
    {
        m.insert(pair<int,struct node *>(++i,h1));
        h1=h1->next;

    }
    while(h2->next!=NULL) {

    for(unordered_map<int,struct node * >::iterator it=m.begin(); it!=m.end(); ++it)
    {
        if(it->second==h2)
        {
            goto label;
        }
    }
    h2=h2->next;
}
label:
printf(" the answer thru hash is \n%d\n",h2->data);


}

int main()
{
    twomergelist obj,obj1;
    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(6);
    obj.add(8);
    obj.add(9);
    obj.add(11);
    obj.add(12);
    obj.add(13);
    printf("the first list\n");
    obj.disp();
    printf("\n\n");

    //obj1.add(15);
    //obj1.add(16);
    obj1.add(17);
    printf("the sec list\n");
    obj1.disp();
    printf("\n\n");

    obj.createmergelist(4,obj1.head);


    printf("the first list after creation\n");
    obj.disp();
    printf("\n\n");
    printf("the sec list after creation\n");
    obj1.disp();
    obj.usingstack(obj.head,obj1.head);
    obj.usingptrs(obj.head,obj1.head);
    obj.usinghash(obj.head,obj1.head);
    obj.bruteforce(obj.head,obj1.head);
    return 0;
}

