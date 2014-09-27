#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include <stdlib.h>
#include<queue>
#include<string>
#include<stddef.h>
#include<malloc.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#include<unordered_map>

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(I) ((int)I + (int)'a')
using namespace std;


struct object
{
    int value;
    int trieval;
};

struct trienode
{
    int val;
    struct trienode *children[26];

};

struct trietree
{
    struct trienode *root;
    int count;
};

struct trienode* getnode();
void initialize(struct trietree *);
void insertwords(struct trietree *,string );
//  void display(struct trietree *)

struct trienode* getnode()
{
    struct trienode* temp=NULL;
    temp=(struct trienode *)malloc(sizeof(struct trienode));
    if(temp)
    {
        temp->val=0;
        for(int i=0; i<26; i++)
        {
            temp->children[i]=NULL;


        }
    }

    return temp;
}

void initialize(struct trietree *tr1)
{
    tr1->root=getnode();
    tr1->count=0;

}

void insertwords(struct trietree *tr1,string word)
{
    int len=word.size();
    struct trienode *temp=tr1->root;
    tr1->count++;

    for(int i=0; i<len; i++)
    {
        int index=CHAR_TO_INDEX(word.at(i));
        if(!temp->children[index])
        {

            temp->children[index]=getnode();
        }
        temp=temp->children[index];
    }
    temp->val=tr1->count;

}
int searchfn(struct trietree *tr1,string key)
{
    int len=key.size();
    struct trienode *temp=tr1->root;

    for(int i=0; i<len; i++)
    {
        int index=CHAR_TO_INDEX(key.at(i));
        if(!temp->children[index])
        {
            return 0;
        }
        temp=temp->children[index];
    }
    return (0!=temp&&temp->val);
}

int leafnode(struct trienode *tn1){
    return tn1->val!=0;
}

int checkfreenode(struct trienode *tn1){
    for(int i=0; i<26; i++)
    {
        if(tn1->children[i]!=NULL)
        {
            return 0;
        }

    }
    return 1;
}

object numberofchildnodes(struct trienode *tn1)
{
    struct object ob1;
    int result=0;
    int val1=0;
    for(int i=0; i<26; i++)
    {
        if(tn1->children[i]!=NULL)
        {
            result++;
            val1=i;
        }

    }
    ob1.value=result;
    ob1.trieval=val1;
    return ob1;
}
string longestcommonprefix(struct trietree *tr1)
{
    string str="";
    struct trienode *temp=tr1->root;
    while(numberofchildnodes(temp).value==1)
    {
        int ind=numberofchildnodes(temp).trieval;
        temp=temp->children[ind];
        char c=INDEX_TO_CHAR(ind);
        str+=c;
    }
return str;
}

bool deleteHelper(struct trienode *pNode, string key, int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->val )
            {
                // Unmark leaf node
                pNode->val = 0;

                // If empty, node to be deleted
                if( checkfreenode(pNode) )
                {
                    return true;
                }

                return false;
            }
        }
        else // Recursive case
        {
            int index = CHAR_TO_INDEX(key.at(level));

            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                free(pNode->children[index]);
                pNode->children[index]=NULL;

                // recursively climb up, and delete eligible nodes
                return ( !leafnode(pNode) && checkfreenode(pNode) );
            }
        }
    }

    return false;
}

void deleteKey(struct trietree *pTrie, string key)
{
    int len = key.size();

    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}


int main(){

// dont use pointer for obj....
//and while calling the function just give the address with it
    struct trietree obj;
    initialize(&obj);
    insertwords(&obj,"mathew");
    insertwords(&obj,"manasi");
    insertwords(&obj,"mather");
    if(searchfn(&obj,"fucker"))
    {

        cout<<"present";
    }
    else
    {
        cout<<"not present";
    }
    cout<<longestcommonprefix(&obj);
    deleteKey(&obj,"mather");

    return 0;

}

