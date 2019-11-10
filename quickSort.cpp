#include <iostream>
#include <vector>
#include <ctime>
#define maxsize 100
using namespace std;
int a[maxsize]={0};
void quickSort(int low,int high)
{
    //递归结束点
    if(low>=high)
      return ;
     int temp=a[low];
     int i=low,j=high;
     while(i<j)
     {
         while(i<j&&a[j]>=temp) j--;
           if(i<j)
           {
               a[i]=a[j];
           }
        while(i<j&&a[i]<=temp) i++;
        if(i<j)
        {
            a[j]=a[i];
        }   
     }
     a[i]=temp;
    quickSort(low,i-1);
    quickSort(i+1,high);              
}
int main()
{
    int n;
    cin>>n;
    srand(unsigned(time(0)));
    for(int i=0;i<n;++i)
    {
        a[i]=rand()%100;
    }
    quickSort(0,n-1);
    //output
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
    

   


}