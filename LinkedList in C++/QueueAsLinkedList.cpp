#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
class LinkedQueue
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
public:
    LinkedQueue();
    struct node *rear,*front;
    void addq(int);
    int delq();
};

LinkedQueue::LinkedQueue()
{
    rear=front=NULL;

}
void LinkedQueue::addq(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));

    if(rear==NULL)
    {
        rear=(struct node *)malloc(sizeof(struct node));
        rear->data=data;
        rear->next=NULL;
        front=rear;

    }
    else
    {
//rear->next==(struct node *)malloc(sizeof(struct node));


        temp->data=data;


        temp->next=rear->next;
        //rear->next=NULL;


        rear->next=temp;
        rear=temp;

    }


}
int LinkedQueue::delq()
{
    struct node *temp;
    int x=0;
    if(front==NULL)
    {
        printf("nothing in the queue");
        return 0;
    }
    else
    {
        temp=front;
        x=front->data;
        //printf("%d \n",front->data);
        front=front->next;
        delete temp;
        if(front==NULL)
        {
            rear=NULL;
        }
        return x;
    }

}
int main()
{
    LinkedQueue q;
    q.addq(3);
    q.addq(4);
    q.addq(5);
    printf("%d \n",q.delq());
    printf("%d \n",q.delq());
    printf("%d \n",q.delq());

    return 0;
}
