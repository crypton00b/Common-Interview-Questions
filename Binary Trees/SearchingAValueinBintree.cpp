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
static int searchnoderecurse(struct treenode *root,int value)
{
    int root_val,temp;
    if(!root)
    {
        return 0;

    }
    else
    {
        root_val=root->data;
        if(root_val==value)
        {
            return 1;
        }
        else
        {
            temp=searchnoderecurse(root->left,value);
            if(temp!=0)
            {
                return temp;
            }
            else
            {
                return (searchnoderecurse(root->right,value));
            }
        }

    }


}
//static void  recursivesearchmeth2(struct treenode *root,int value)
//{
//    if(root)
//    {
//        if(root->data==value)
//        {
//            printf("there is a node in the tree");
//        }
//        else
//        {
//            recursivesearchmeth2(root->left,value);
//            recursivesearchmeth2(root->right,value);
//        }
//    }
//    else
//    {
//
//        printf("there is no node in the tree");
//    }
//
//
//}
static void levelordersearch(struct treenode *root,int value)
{
    queue<struct treenode *> q1;


    int root_val,flag=0;
    q1.push(root);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();

        root_val=temp->data;
        if(root_val==value)
        {
            flag=1;

        }

        q1.pop();


        if(temp->left)
        {

            q1.push(temp->left);
        }
        if(temp->right)
        {
            q1.push(temp->right);
        }

    }
    if(flag)
    {
        printf(" the node is there in the tree\n");
    }
    else
    {
        printf("the node is not there in the tree\n");
    }
}
int main()
{
    int flag;
    struct treenode *root=add(10);
    root->left=add(20);
    root->right=add(30);
    root->left->left=add(80);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
    flag=searchnoderecurse(root,5100);
    if(flag)
    {
        printf(" the node is there in the tree\n");
    }
    else
    {
        printf("the node is not there in the tree\n");
    }

    levelordersearch(root,100);

    //recursivesearchmeth2(root,100);
    return 0;
}
