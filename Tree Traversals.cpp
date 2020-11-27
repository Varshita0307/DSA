#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* getnew(int data)
{
    Node* NN = new Node();
    NN->data = data;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

Node* Insert(Node* root, int data)
{
    if (root==NULL)
       root = getnew(data);
    
    else if (data<=root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

void inorderre(Node* root)
{
    if (root == NULL)
       return;
    
    inorderre(root->left);
    cout<<root->data<<" ";
    inorderre(root->right);
}

void inorderit(Node* root)
{
    stack<Node*> st;
    Node* p = root;
    int t;
    while(!st.empty () || p!=NULL)
    {
        if (p!=NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
            cout<<p->data<<" ";
            p = p->right;
        }
    }
}

void preorderit(Node* root)
{
    stack<Node*> st;
    st.push(root);
    Node* p = root;
    while(!st.empty())
    {
        p = st.top();
        cout<<p->data<<" ";
        st.pop();
        if(p->right)
           st.push(p->right);
        if(p->left)
           st.push(p->left);
    }
}

void postorderit(Node* root)
{
    stack<Node*> st;
    stack<int> out;
    st.push(root);
    Node* p = root;
    while(!st.empty())
    {
        p = st.top();
        st.pop();
        out.push(p->data);
        if(p->left)
           st.push(p->left);
        if(p->right)
          st.push(p->right);
    }
    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
        
    }
    
    
}
int main() {
	Node* root = NULL;  
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	postorderit(root);
 

}


