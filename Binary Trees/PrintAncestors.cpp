#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

static void printstack(stack<struct treenode *>);

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


static int printancestors(struct treenode * root,struct treenode *node)
{
    if(!root)
    {
        return 0;

    }
    if(root->left==node||root->right==node||printancestors(root->left,node)||printancestors(root->right,node))
    {
        printf("\n%d",root->data);
        return 1;

    }
    return 0;
}
static void dfsancestors(struct treenode *root,struct treenode * node)
{
    stack<struct treenode *> s1;
    s1.push(root);

    while(!s1.empty())
    {
        struct treenode *temp;
        temp=s1.top();
        s1.pop();
        //printf("\n%d",temp->data);
        if(temp->left==node || temp->right==node){
        printstack(s1);
        break;
        }
        if(temp->left)
        {
            s1.push(temp->left);

        }
        if(temp->right)
        {
            s1.push(temp->right);

        }
    }


}
static void printstack(stack<struct treenode *>s){
    while(!s.empty()){
    printf("\n%d",s.top()->data);
    s.pop();
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
    //printancestors(root,root->right->right);
    dfsancestors(root,root->right->right);
    return 0;
}
