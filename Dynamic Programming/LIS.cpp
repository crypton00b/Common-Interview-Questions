#include<iostream>
#include<vector>
#include<stddef.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
void printpath(vector<int>aux,vector<int>arr,int max,int len);
vector<int>print;

int lis(vector<int>arr,int len)
{
    vector<int>aux;

    for(int i=0; i<len; i++)
    {
        aux.push_back(1);

    }
    for(int i=1; i<len; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr.at(i)>arr.at(j)&&aux.at(i)<aux.at(j)+1)
            {
                aux.at(i)=aux.at(j)+1;

            }


        }


    }
    int sum=0;
    for(int i=0; i<len; i++)
    {
        if(sum<aux.at(i))
        {
            sum=aux.at(i);
        }
    }
    printpath(aux,arr,sum,len);
    return sum;
}
void printpath(vector<int>aux,vector<int>arr,int max,int len)
{
    int tmp=max;
    vector<int>lis;
    for(int i=len-1; i>=0; i--)
    {
        if(aux.at(i)==tmp)
        {
            lis.push_back(i);
            --tmp;
        }
    }
    reverse(lis.begin(),lis.end());
    for(int i=0;i<max;i++){

    cout<<"\t"<<arr.at(lis.at(i));
    }
    return;

}

int main()
{
    vector<int>arr;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }


    cout<<lis(arr,n);



    return 0;
}
