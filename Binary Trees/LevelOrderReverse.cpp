#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<stack>
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

void levelreverse(struct treenode *root)
{
    queue<struct treenode *> q1;
    stack<struct treenode *>s1;



    q1.push(root);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();

        s1.push(temp);

        q1.pop();


        if(temp->right)
        {
            q1.push(temp->right);
        }

        if(temp->left)
        {

            q1.push(temp->left);
        }



    }
    printf("size=\n%d",s1.size());
    int n=s1.size();
    for(int i=0; i<n; i++)
    {
        printf("\n%d",s1.top()->data);
        s1.pop();
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
    levelreverse(root);
    return 0;
}
