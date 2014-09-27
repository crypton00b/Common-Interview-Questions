#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
using namespace std;
static void printarray(int [],int);


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

static void rootleaf(struct treenode * root,int patharr[],int pathlen)
{

    if(root)
    {

        //int patharr[100];

        patharr[pathlen]=root->data;
        //printf("\n%d",patharr[pathlen]);
        pathlen++;

        if(root->left==NULL && root->right==NULL)
        {
            printarray(patharr,pathlen);
            }
        else
        {
            rootleaf(root->left,patharr,pathlen);
            rootleaf(root->right,patharr,pathlen);

        }
    }


}
static void printarray(int arr[],int sz)
{
    // to calculate the array size
    //int sz=sizeof arr/sizeof (int);
    for(int i=0; i<sz; i++)
    {
        printf("\n%d",arr[i]);
    }
    printf("\n");


}
int main()
{
    int arr[100];
    struct treenode *root=add(100);
    root->left=add(200);
    root->right=add(300);
    root->left->left=add(400);
    root->left->right=add(500);
    root->right->left=add(600);
    root->right->right=add(700);
    rootleaf(root,arr,0);
    return 0;
}
