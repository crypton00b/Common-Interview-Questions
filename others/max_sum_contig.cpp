#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string>
#include<vector>
using namespace std;
int kadanes(vector<int>arr,int len)
{
    int curr_max=arr.at(0);
    int max_sofar=0;
    for(int i=1; i<len; i++)
    {
        curr_max=max(arr.at(i),curr_max+arr.at(i));
        max_sofar=max(curr_max,max_sofar);


    }
    return max_sofar;

}
int main()
{

vector<int>arr={3,-2,4,-6,-1,8};
int siz=arr.size();
cout<<kadanes(arr,siz);



    return 0;
}
