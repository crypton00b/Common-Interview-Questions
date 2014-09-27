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

static void maxsumlevel(struct treenode *root)
{
    queue<struct treenode *> q1;


    int level=0,currentsum=0,maxsum=0,maxlevel=0;
    q1.push(root);
    q1.push(NULL);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();

        q1.pop();
        if(temp==NULL)
        {
            if(!q1.empty())
            {
                q1.push(NULL);
            }
            level++;
            if(currentsum>maxsum)
            {
                maxsum=currentsum;
                maxlevel=level;


            }
            currentsum=0;

        }
        else
        {
            currentsum+=temp->data;


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
    printf(" the max sum is %d\n and the max level is %d\n",maxsum,maxlevel);

}
int main()
{
    struct treenode *root=add(100);
    root->left=add(200);
    root->right=add(300);
    root->left->left=add(80);
    root->left->right=add(50);
    root->right->left=add(60);
    root->right->right=add(70);
    maxsumlevel(root);
    return 0;
}
