#include "JosephusProblem.h"
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

};

static void josephus(int n,int m)
{
    struct node *p,*q;

    p=q=(struct node *)malloc(sizeof(struct node));
    for(int i=2; i<=n; i++)
    {
        p->next=(struct node *)malloc(sizeof(struct node));
        p=p->next;
        p->data=i;

    }
    p->next=q;
    for(int count=n;count>1;count--){
    p=p->next;
    p->next=p->next->next;
    }
    printf("the final answer is \n%d ",p->data);

}





int main()
{
josephus(12,2);
    return 0;
}
