//find the maximim value in a tree

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
static int findmaxbypostorder(struct treenode *root)
{
    int root_val,max=INT_MIN,left,right;
    if(root)
    {
        root_val=root->data;
        left=findmaxbypostorder(root->left);
        right=findmaxbypostorder(root->right);

        if(left>right)max=left;
        else
            max=right;

        if(root_val>max)
        {
            max=root_val;
        }


    }
    return max;


}
int levelorder(struct treenode *root)
{
    queue<struct treenode *> q1;


    int root_val,max=INT_MIN;
    q1.push(root);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();

        root_val=temp->data;

        q1.pop();

        if(root_val>max)
        {
            max=root_val;
        }
        if(temp->left)
        {

            q1.push(temp->left);
        }
        if(temp->right)
        {
            q1.push(temp->right);
        }

    }
    return max;
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
    printf(" the max value is \n%d",findmaxbypostorder(root));
    printf(" the max value is \n%d",levelorder(root));
    return 0;
}
