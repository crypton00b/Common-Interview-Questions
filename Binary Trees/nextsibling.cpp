#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;


static void printree(struct treenode *);

struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
    struct treenode *nextsibling;

};


static struct treenode *add(int dat)
{
    struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=dat;
    temp->left=NULL;
    temp->right=NULL;
    return temp;


}
static void nextsiblingwithlevelorder(struct treenode *root)
{
    queue<struct treenode *>q1;
    struct treenode *temp;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {

        temp=q1.front();
        q1.pop();
        if(temp==NULL)
        {

            if(!q1.empty())
            {
                q1.push(NULL);
            }

        }
        else
        {

            temp->nextsibling=q1.front();
            if(temp->left)
            {
                q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }


        }

    }

}

static void nextsiblinganotherway(struct treenode *root)
{
    if(!root)return;
    if(root->left)
    {
        root->left->nextsibling=root->right;

    }
    if(root->right)
    {
        root->right->nextsibling=(root->nextsibling)?root->nextsibling->left:NULL;

    }
    nextsiblinganotherway(root->left);
    nextsiblinganotherway(root->right);



}
static void printree(struct treenode *root)
{
    if(root)
    {
        printf("testing");

        printree(root->left);
        printf("%d",root->nextsibling->data);
        printree(root->right);
    }

}


int main()
{
    struct treenode *root=add(10);
    root->left=add(20);
    root->right=add(30);
    root->left->left=add(40);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
   nextsiblingwithlevelorder(root);
    printree(root);
    nextsiblinganotherway(root);
    printree(root);


    return 0;
}
