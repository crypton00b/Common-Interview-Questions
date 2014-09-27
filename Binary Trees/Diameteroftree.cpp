
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
static int heightrecurse(struct treenode *root)
{
    int left=0,right=0;//imp so that the final value will be  one less than thefinal
    if(!root)
    {
        return 0;
    }
    else
    {

        left=heightrecurse(root->left);
        right=heightrecurse(root->right);
        if(left>right)
        {
            return left+1;
        }
        else
        {
            return right+1;
        }
    }


}
static int heightrecurse1(struct treenode * root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return max(heightrecurse1(root->left),heightrecurse1(root->right))+1;
    }


}
int heightlevelorder(struct treenode *root)
{
    queue<struct treenode *> q1;
    int level=0;


    int count=0;
    q1.push(root);
    q1.push(NULL);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();
        q1.pop();
//printf("error1");
        if(temp==NULL)
        {
            if(!q1.empty())
            {
                //printf("error1");
                q1.push(NULL);
//printf("error1");

            }
            level++;
        }

        else
        {
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
    return level;
}

//this method checks for the height of the left tree and right tree and take the max of left subtree,right subtree and the longest path between the leaves that goes thru the root...it is o(n^2)as we are calculating the height and diameter for each case

int diameteroftree(struct treenode*root)
{
    if(root==NULL)return 0;
    int leftheight=heightrecurse1(root->left);
    int rightheight=heightrecurse1(root->right);

    int ldiam=diameteroftree(root->left);
    int rdiam=diameteroftree(root->right);

    return max(max(ldiam,rdiam),leftheight+rightheight+1);


}
//this is the most efficient way....it is o(n)...we are calculating the height and diameter together so that it is not calculated again..that is y we have another argument called ht
//*ht is used becaues it shouldnt change when it recurses back
int diameteroftreeefficient(struct treenode *root,int *ht)
{
    int ldiam=0,rdiam=0,lh=0,rh=0;
    if(root==NULL)
    {
        *ht=0;
        return 0;
    }

     /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
    ldiam=diameteroftreeefficient(root->left,&lh);
    rdiam=diameteroftreeefficient(root->right,&rh);

    *ht=max(lh,rh)+1;
    return max((lh+rh+1),max(ldiam,rdiam));



}

int main()
{
    struct treenode *root=add(10);
    root->left=add(20);
    root->right=add(30);
    root->left->left=add(80);
    root->left->right=add(50);
    root->left->right->left=add(60);
    root->left->right->right=add(70);
    //printf(" the ht by recursion is \n%d",heightrecurse(root));
    //printf(" the  ht by levelorder is \n%d",heightlevelorder(root));
    //printf(" the  ht by levelorder is \n%d",heightrecurse1(root));
    cout<<diameteroftree(root)<<"\n";
    int x=0;
    int *ht=&x;
    cout<<diameteroftreeefficient(root,ht);
    return 0;
}
