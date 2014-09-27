#include<iostream>
#include<vector>
#include<malloc.h>
#include<string.h>// for memset to work
#include<algorithm>//can be used for sorting an array also(not just vector>



using namespace std;
/* A Binary Search based function to find index of FIRST occurrence
  of x in arr[].  If x is not present, then it returns -1 */
int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high-low)/2;  /* (low + high)/2; */
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        return first(arr, low, (mid -1), x, n);
    }
    return -1;
}


void sort_relative_sort_method(int *a1,int *a2,int m,int n)
{
    int *temp=(int *)malloc(m*sizeof(int));//just initialzing an array
    bool visited[m];
    memset(visited,false,m);
    for(int i=0; i<m; i++)
    {
        temp[i]=a1[i];

    }
    sort(temp,temp+m);//sorting an array using the sort function
    int low,high;
    int ind=0;
    for(int i=0; i<n; i++)
    {
        if(binary_search(temp,temp+m,a2[i]))
        {
            //visited[i]=true;
            low=lower_bound(temp,temp+m,a2[i])-temp;
            high=upper_bound(temp,temp+m,a2[i])-temp;
            int diff=high-low;
            for(int j=0; j<diff; j++)
            {
                visited[low++]=true;
                a1[ind]=a2[i];
                ind++;
            }
        }


    }
    for(int i=0; i<m; i++)
    {
        if(visited[i]==false)
        {
            a1[ind++]=temp[i];
        }
    }

    for(int j=0; j<m; j++)
    {

        cout<<a1[j];
    }



}



int main()
{
    int a1[11]= {2,1,2,5,7,1,9,3,6,8,8};
    int a2[4]= {2,1,8,3};


    sort_relative_sort_method(a1,a2,11,4);
    return 0;
}
