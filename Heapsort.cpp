#include <iostream>
#define maxsize 100
using namespace std;
int a[maxsize];
void input(int n)
{
    srand(unsigned(time(0)));
    for(int i=0;i<n;++i)
    {
       scanf("%d",&a[i]);   
    }
}
void output(int n)
{
   for(int i=0;i<n;++i)
    {
       cout<<a[i]<<endl;   
    }
}
//在无序区的某个位置调整
//左孩子2*i+1 右孩子2*i+2
void swift(int i,int limit)
{
   if(i>=limit)
    return ;
    if(2*i+1<=limit)
    {
      if(2*i+2<=limit)
      {
          if(a[2*i+2]>a[2*i+1]&&a[2*i+2]>a[i])
          {
                   swap(a[i],a[2*i+2]);
                   swift(2*i+2,limit);
          }
          else if(a[2*i+1]>a[2*i+2]&&a[2*i+1]>a[i])
          {
                  swap(a[i],a[2*i+1]);
                  swift(2*i+1,limit);
          }
          
      }
      else
      {
          if(a[2*i+1]>a[i])
          {
              swap(a[2*i+1],a[i]);
              swift(2*i+1,limit);
          }
      }
      
    }
    
     
}

void heapsort(int n)
{
    //建立初始大根堆
    for(int i=n/2;i>=0;--i)
    {
        swift(i,n);
    }
    // 0 1 2 3
    for(int i=n-1;i>=1;--i)
    {
        swap(a[0],a[i]);
        swift(0,i-1);
    }
}
int main()
{
  memset(a,0,sizeof(a));
  int n;
  cin>>n;
  input(n);
  heapsort(n);
  output(n);

//    output(n);

}