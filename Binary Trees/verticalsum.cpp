#include<iostream>
#include<stdio.h>
#include<stddef.h>
#include<malloc.h>
#include<limits.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
class tree{
public:
struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;


}head;

struct treenode*add(int);
void verticalsum(struct treenode*,int ,unordered_map<int,int>);

};

tree::treenode *tree::add(int dat)
{
    struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
    temp->data=dat;
    temp->left=NULL;
    temp->right=NULL;
    return temp;


}

void tree::verticalsum(struct treenode *root,int col,unordered_map<int,int>hash)
{

   if(!root)return;
   verticalsum(root->left,col-1,hash);
   int prevsum=(hash[col]==NULL)? 0: hash[col];
   hash.insert(pair<int,int>(col,prevsum+root->data));
   verticalsum(root->right,col+1,hash);


}


int main()
{
    tree obj;
    unordered_map<int,int>hash;
    struct treenode *root=obj.add(10);
    root->left=obj.add(20);
    root->right=obj.add(30);
    root->left->left=obj.add(40);
    root->left->right=obj.add(50);
    root->right->left=obj.add(60);
    root->right->right=obj.add(70);
   obj.verticalsum(root,0,hash);
       for(unordered_map::iterator it=hash.begin();it!=hash.end();it++){
    cout<<"column "<<it->first<<"\t"<<it->second;

       }


    return 0;

}
