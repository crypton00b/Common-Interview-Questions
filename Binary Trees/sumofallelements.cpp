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

static int getsumrecurse(struct treenode * root){
if(!root){

return 0;
}else{
return (root->data+getsumrecurse(root->left)+getsumrecurse(root->right));

}


}
static int getsumiterate(struct treenode *root)
{
    queue<struct treenode *> q1;


    int sum=0;
    q1.push(root);

    while(!q1.empty())
    {
        struct treenode *temp=q1.front();
        sum+=temp->data;
        q1.pop();


            if(temp->left)
            {

                q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }

        }

    return sum;

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
    printf("\n%d",getsumrecurse(root));
    printf("\n%d",getsumiterate(root));
    return 0;
}

