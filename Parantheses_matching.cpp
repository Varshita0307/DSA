#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 stack<char> st;
 string str = "{()}[]}";
 int i;
 for (i=0;i<str.length();i++)
 {
     char ch = str[i];
     if (ch == '(' || ch=='{' || ch =='[')
     {
         st.push(ch); //1.Push Opening Brackets
     }
     else if (ch==')')
     {
         if(st.size()==0) //CB encountered, but no elements in stack
         {
             cout<<"Not Balanced";
             break;
         }

         else if (st.top() != '(') //CB encountered but it's pair not found
         {
             cout<<"Not Balanced";
             break;
         }
         else
         st.pop(); //CB encountered and pair found, so pop and check for others
     }

      else if (ch==']')
     {
         if(st.size()==0)
         {
             cout<<"Not Balanced";
             break;
         }

         else if (st.top() != '[')
         {
             cout<<"Not Balanced";
             break;
         }
         else
         st.pop();
     }
      else if (ch=='}')
     {
         if(st.size()==0)
         {
             cout<<"Not Balanced";
             break;
         }

         else if (st.top() != '{')
         {
             cout<<"Not Balanced";
             break;
         }
         else
         st.pop();
     }

}
if(st.size()==0)
cout<<"Balanced";
else
cout<<"Not Balanced";


}
