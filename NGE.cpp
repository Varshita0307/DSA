#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4] = {1,3,2,4};
    stack<int> st;
    int n = sizeof(arr)/sizeof(arr[0]);
    int arr1[n];
    int i;
    for(i=n-1;i>=0;i--) //Start iterating from the end
    {   
        int a = arr[i];
        while(!st.empty() && st.top()<=a) //keep popping elements until the top is greater than the array element
            st.pop(); 
        if(st.size()==0)
          arr1[i] = -1; //if the stack is empty, it is the greatest element so -1
        else
          arr1[i] = st.top(); //The top elements is NGE
          
        st.push(a);
        
    }
    for (int i = 0; i < n; i++) 
        cout << arr1[i] << " "; 
    cout<<endl;
    
}
