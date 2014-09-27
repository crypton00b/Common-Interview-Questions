#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
using namespace std;



struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;

};


static struct treenode *add(int dat)
{
    struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=dat;
    temp->left=NULL;
    temp->right=NULL;
    return temp;


}

static void insert(struct treenode *root,int val)
{
    struct treenode *newnode=(struct treenode *)malloc(sizeof(struct treenode));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(!root)
    {
        root=newnode;
        //   root->data=val;

    }
    //int root_val;
    struct treenode *temp;
    queue<struct treenode *>q1;
    q1.push(root);
    while(!q1.empty())
    {
        temp=q1.front();
        q1.pop();
        if(temp->left)
        {
            q1.push(temp->left);
        }
        else
        {
            temp->left=newnode;
            break;

        }
        if(temp->right)
        {
            q1.push(temp->right);
        }
        else
        {
            temp->right=newnode;
            break;

        }


    }

}
static void printx(struct treenode *root)
{
    if(root)
    {
        printf("%d\n",root->data);
        printx(root->left);
        printx(root->right);

    }


}

int main()
{
    struct treenode *root=add(10);
    root->left=add(20);
    root->right=add(30);
    root->left->left=add(80);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
    printx(root);
    insert(root,100);
    printx(root);
    return 0;
}
