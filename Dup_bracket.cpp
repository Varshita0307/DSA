#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 stack<char> st;
 string str = "(((a+(b))+(c+d)))";
 for(int i=0;i<str.length();i++)
 {
     char ch = str[i];
     if(ch==')')  //2. When a closing bracket is encountered
     {
         if (st.top() == '(' )  //5. If opening bracket is on top, that means brackets did not enclose any unique exp.
         {
             cout<<"Duplicate";
             continue;
         }
         else
         {
             while(st.top() != '(') //3. Pop elements until a opening bracket is reached
             {
                 st.pop();
             }
             st.pop(); //4. Pop corresponding Opening bracket
         }
     }
     else
     {
        st.push(ch); //1. Push all elements except closing brackets
     }

 }
 cout<<"No duplicate";
}
