#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Student
{
    string name;
    string number;
    int grade;
}Student;
int cmp(Student a,Student b)
{
     return a.grade<b.grade;
}
int main()
{
   int n;
   cin>>n;
   Student s[101];
   for(int i=0;i<n;++i)
   {
       cin>>s[i].name>>s[i].number>>s[i].grade;
   }
   sort(s,s+n,cmp);
   cout<<s[n-1].name<<" "<<s[n-1].number<<endl<<s[0].name<<" "<<s[0].number;
}
