#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<algorithm>
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
//the value will be one more than the actual height
static struct treenode * lca(struct treenode *root,struct treenode *a,struct treenode *b)
{
    struct treenode *left,*right;
    if(!root){
    return root;
    }
    if(root->left==a || root->right==b){
    return root;


    }
    left=lca(root->left,a,b);
    right=lca(root->right,a,b);
    if(left&&right){
    return root;
    }
    else{
    return (left?left:right);
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

     printf("\n%d",lca(root, root->left->left,root->left->right)->data);
    return 0;
}
