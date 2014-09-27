#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
static void swap(stack<struct treenode*>,stack<struct treenode *>);


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
void zigzagtraversal(struct treenode *root)
{
    stack<struct treenode *>currentlevel,nextlevel;
    if(!root)
    {
        return;
    }
    struct treenode *temp;
    int leftoright=1;
    currentlevel.push(root);
    //printf("checkoing  \n%d\n",currentlevel.top()->data);
    while(!currentlevel.empty())
    {
        temp=currentlevel.top();
        currentlevel.pop();
        if(temp)
        {
            printf("\n%d",temp->data);
            if(leftoright==1)
            {



                if(temp->left)nextlevel.push(temp->left);
                if(temp->right)nextlevel.push(temp->right);

            }
            else
            {
                if(temp->right)nextlevel.push(temp->right);
                if(temp->left)nextlevel.push(temp->left);


            }

        }
        if(currentlevel.empty())
        {
            leftoright=1-leftoright;
            stack<struct treenode *> temp1=currentlevel;
            currentlevel=nextlevel;
            nextlevel=temp1;


        }
    }

}
//static void swap(stack<struct treenode*>s1,stack<struct treenode *>s2)
//{
//    stack<struct treenode *> temp1=s1;
//    s1=s2;
//    s2=temp1;
//
//
//}
int main()
{
    struct treenode *root=add(10);
    root->left=add(20);
    root->right=add(30);
    root->left->left=add(40);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
    zigzagtraversal(root);
    return 0;
}
