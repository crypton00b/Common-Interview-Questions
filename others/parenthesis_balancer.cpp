#include<iostream>
#include<stdio.h>
using namespace std;




void parenthesis_maker(int pos,int n,int open,int close)
{
    static char str[100];
    if(close==n)
    {
        cout<<"\n"<<str;
        return;
    }
    else
    {
        if(open>close)
        {
            str[pos]='}';
            parenthesis_maker(pos+1,n,open,close+1);

        }
         if(open<n)
        {
            str[pos]='{';
            parenthesis_maker(pos+1,n,open+1,close);


        }
    }

}

int main()
{
    parenthesis_maker(0,6,0,0);

}
