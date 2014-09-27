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
static void deletetree(struct treenode *root)
{
    if(root){

    deletetree(root->left);
    deletetree(root->right);
    root=NULL;
    delete root;
}

}
static void printree(struct treenode *root){
if(root){
printf("\n%d",root->data);
printree(root->left);
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
    printree(root);
    deletetree(root);
    printree(root);
    return 0;
}
