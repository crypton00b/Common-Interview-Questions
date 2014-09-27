#include<iostream>
#include<vector>
#include<stddef.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

void printpath(string x,string y,int m,int n,vector< vector<int> >mat,int index);

int lcommonsubstring(string x,string y,int m,int n)
{
    //declares the vector and give all values as 0
    vector< vector<int> >mat(m+1,vector<int>(n+1,0));
    int result=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {

            if(x.at(i-1)==y.at(j-1))
            {
                mat.at(i).at(j)=mat.at(i-1).at(j-1)+1;
                result=max(result,mat.at(i).at(j));

            }
            else
            {
                mat.at(i).at(j)=0;
            }

        }

    }


    return result;


}
void printpath(string x,string y,int m,int n,vector< vector<int> >mat,int index)
{
    char lcs[index+1];
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(x.at(i-1)==y.at(j-1))
        {
            lcs[index-1]=x.at(i-1);
            i--;
            j--;
            index--;
        }
        else if(mat.at(i).at(j-1)>mat.at(i-1).at(j))
        {
            j--;
        }
        else
        {
            i--;
        }

    }
    cout<<lcs;

}

int main()
{

    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();

    cout<<lcommonsubstring(s1,s2,m,n);




    return 0;
}
