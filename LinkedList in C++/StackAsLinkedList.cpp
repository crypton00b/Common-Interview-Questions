#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
class LinkedList
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
public:
    LinkedList();
    //virtual ~LinkedList();
    struct node *top;
    void push(int );
    int pop();

};

LinkedList::LinkedList()
{

    top=NULL;

}

//LinkedList::~LinkedList()
//{

//}
void LinkedList::push(int dat)
{

    struct node *temp=(struct node *)malloc(sizeof(struct node));

    temp->data=dat;

    temp->next=top;

    top=temp;

}
int LinkedList::pop()
{
    struct node *temp;
    int x=0;
    if(!top)
    {
        printf("stack underflow");
        return 0;
    }
    //printf("the value is");
    //printf("%d",top->data);
    x=top->data;
    temp=top;
    top=top->next;
    delete temp;
    return x;

}

int main()
{
    LinkedList obj;
    obj.push(1);

    obj.push(2);
    printf("%d",obj.pop());
    printf("%d",obj.pop());
    printf("%d",obj.pop());
//printf("%d",top->data);
//struct node *val=(struct node*)malloc(sizeof(struct node));


    return 0;
}
