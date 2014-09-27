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

static void delelement(struct treenode *root,int elem)
{
    queue<struct treenode *> q1;


    int root_val;
    q1.push(root);
    struct treenode *target;
    struct treenode *temp;

    while(!q1.empty())
    {
        temp=q1.front();

        root_val=temp->data;

        q1.pop();
        if(root_val==elem){
        target=temp;
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
    int var=temp->data;
    temp->data=target->data;
    target->data=var;
    temp=NULL;
    delete temp;
// we have to take care to close it by puting lft and right with NULL
}

static void printree(struct treenode * root){
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
    root->left->left=add(80);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
    printree(root);
    delelement(root,80);
    printf("sfteer deleting \n");
    printree(root);
    return 0;
}
