#include <bits/stdc++.h>
using namespace std;

struct LLnode{                             // Node of LL  
       int value;
       struct LLnode *next,*prev;
};
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* new_node(int data) 
{
    Node *newNode = 
        (Node*)malloc(sizeof(Node));   
    newNode->data = data; 
    newNode->left = newNode->right = NULL;     
    return newNode; 
} 
struct bstnode{                            // Node of BST
       int val;
       struct bstnode *parent,*left,*right;
       };
void freell(struct LLnode *head){          // Function to free linked list
     struct LLnode* temp=head;
     while(head){
          temp=head->next;
          free(head);
          head=temp;
          }                  
     }
void freebst(struct bstnode* k){          // Recursive Function to free BST
    if(k){
        freebst(k->left);
        freebst(k->right);
        free(k);
        }
    }
void insert2bst(struct bstnode **root,struct bstnode* rt,int h){  // Inserting new element to BST
       if(rt==NULL || (rt->val<h && !rt->right) || (rt->val>h && !rt->left)){
          struct bstnode *x=(struct bstnode *)malloc(sizeof(struct bstnode));
          x->left=NULL;
          x->right=NULL;                      
          x->val=h;
          if(rt==NULL){                       // ROOT of BST is null
               x->parent=NULL;                
               *root=x;
               }
          else if(rt->val>h && !rt->left){   // Node < key and has no right child
               x->parent=rt;
               rt->left=x;
               }
          else if(rt->val<h && !rt->right){  // Node > key and has no left child
               x->parent=rt;
               rt->right=x;
               }
       }
       else if(rt->val>h)                        // if node > key and has left child, insert to left subtree
       insert2bst(root,rt->left,h);
       else if(rt->val<h)
       insert2bst(root,rt->right,h);        // if node < key and has right child, insert to right subtree
       }
void insert_at_beginLL(struct LLnode **head,int val){ // Function to insert a node at the BEGINNING of LL
        struct LLnode *x=(struct LLnode*)malloc(sizeof(struct LLnode));
        x->value=val;
        x->next=*head;                      // Append existing linked list to x, and make x head
       *head=x;
}
void insert_at_endLL(struct LLnode **head,int val){
        struct LLnode *x=(struct LLnode*)malloc(sizeof(struct LLnode));
        x->value=val;
        x->next=NULL;                       // Next of last node is NULL
        if(*head==NULL){
            x->prev=x;
            *head=x;
            }
        else{
            ((*head)->prev)->next=x;        // head->prev is last node of LL
            x->prev=(*head)->prev;
            (*head)->prev=x;                // Storing tail in head->prev
            }
}


struct Node* constructBst(int *arr, int n)   //
{
    if(n==0)return NULL;
    Node* root= new_node(arr[0]);
    
    queue <Node*> q;
    queue <pair<int,int> > range; 
    q.push(root);
    range.push({INT_MIN,INT_MAX});
    
    int ind=1,minval,maxval;
    while(ind<n&&!q.empty()){
        Node* node = q.front();
        q.pop();
        minval=range.front().first;
        maxval=range.front().second;
        range.pop();
        
        if(arr[ind]<node->data&&arr[ind]>minval){
            node->left=new_node(arr[ind]);
            ind++;
            q.push(node->left);
            range.push({minval,node->data});
        }
        
        if(ind<n&&arr[ind]>node->data&&arr[ind]<maxval){
            node->right=new_node(arr[ind]);
            ind++;
            q.push(node->right);
            range.push({node->data,maxval});
        }
    }
    
	return root;
}

struct Node* lowest_common_ancestor(int n1, int n2,Node *root)
{   
   if(root==NULL) return NULL;
   if(root->data == n1 || root->data == n2) return root;
   Node* left = lowest_common_ancestor(n1, n2,root->left);
   Node* right = lowest_common_ancestor(n1, n2,root->right);
   if(left!=NULL && right!=NULL) return root;
   if(left==NULL && right==NULL) return NULL;
   if(left!=NULL && right==NULL) return left;
   if(left==NULL && right!=NULL) return right;
}







void print(struct LLnode *k){            // Printing Linked List from given node to end
     while(k){
          printf("%d",k->value);
          k=k->next;
          }
     printf(" ");
     }
void search(struct bstnode* root,int f){       // Function to search in BST and print
     struct bstnode* temp=root;
     while(temp){                              // Start searching from root  
        if(temp->val==f){                    
            struct LLnode*head=NULL;
            while(temp!=root){                 // Retrace path to parent if key found
                if(temp->parent->left==temp)              
                insert_at_beginLL(&head,0);           // if node is left child , add 0 to path
                else if(temp->parent->right==temp)    
                insert_at_beginLL(&head,1);           // if node is right child , add 1 to path
                temp=temp->parent;
                }
            print(head);                  // Printing path
            printf("\n");
            freell(head);
            return;
            }
        else if(temp->val>f)              // if value(node) > key , search in left subtree
        temp=temp->left;
        else
        temp=temp->right;                 // if value(node) < key , search in right subtree
        }
     printf("-1\n");                                        
     }

void splice(struct bstnode *temp,struct bstnode *child){
        if(temp->parent->left==temp)
          temp->parent->left=child;
        else
          temp->parent->right=child;
        if(child)
          child->parent=temp->parent;
        free(temp);
}
void deletefrombst(struct bstnode**root,int f){
    struct bstnode*temp=*root;
    struct bstnode *succ=NULL;
    while(temp!=NULL){
      if(temp->val==f){                    // Value to be deleted found
        if(temp->right){                   // Case 1 :If right child present , find successor
              succ=temp->right;
              while(succ->left)
              succ=succ->left;
              temp->val=succ->val;         // Assign value of successsor to present node
              splice(succ,succ->right);    // SPLICING at the successor          
              }
        else{                              // Case 2 : Simply splice at the node if right child not present
             if(temp==*root){
                *root=temp->left;
                free(temp);
                }
             else
             splice(temp,temp->left);     // splice at node        
             }
             return;
        }
        else if(temp->val>f)              // Searching for value to be deleted in BST
        temp=temp->left;
        else
        temp=temp->right;
    }}

void findsucc(struct bstnode **root,int f){
        if(*root==NULL)
        printf("-1\n");
        struct bstnode *temp=*root,*succ;
        while(temp){                                        
         if(temp->val==f){                     // Case 1 : Value found in BST
           if(temp->right){                      
                succ=temp->right;              // Go right and proceed left till possible
                while(succ && succ->left)
                succ=succ->left;
                printf("%d\n",succ->val);
                }
           else if(temp->parent){              // If node is leaf node
                succ=temp->parent;
                if(succ->parent==NULL){
                    if(succ->left==temp)
                    printf("%d\n",succ->val);
                    else
                    printf("-1\n");
                }
                else{
                    while(succ->parent && succ->parent->right==succ)
                         succ=succ->parent;           // Go to parent till node is left child
                    if(succ->parent)
                      printf("%d\n",succ->parent->val);
                    else
                    printf("-1\n");              // Successor doesn't exist if such node not found
                }
               
                }
           return;  
           }
        else if(temp->val>f)              // if value(node) > key , search in left subtree
        temp=temp->left;
        else
        temp=temp->right;                 // if value(node) < key , search in right subtree
        }
        if(root!=NULL){                   // Case 2 : If query value not found in BST
        insert2bst(root,*root,f);         // Add node temporarily to BST with value to be searched
        findsucc(root,f);                 // Delete the newly added node so that BST remains unaffected
        deletefrombst(root,f);
        }
     }


void findpred(struct bstnode **root,int f){
        if(*root==NULL)
        printf("-1\n");
        struct bstnode* temp=*root,*pred;
        while(temp){                                        
         if(temp->val==f){                     // Case 1 : Value found in BST
           if(temp->left){                      
                pred=temp->left;              // Go left and proceed right till possible
                while(pred && pred->right)
                pred=pred->right;
                printf("%d\n",pred->val);
                }
           else if(temp->parent){              // If node is leaf node
                pred=temp->parent;
                if(pred->parent==NULL){
                    if(pred->right==temp)
                    printf("%d\n",pred->val);
                    else
                    printf("-1\n");
                }
                else{
                    while(pred->parent && pred->parent->left==pred)
                         pred=pred->parent;           // Go to parent till node is left child
                    if(pred->parent)
                       printf("%d\n",pred->parent->val);
                    else
                       printf("-1\n");              // predessor doesn't exist if such node not found
                }
               
                }
           return;  
           }
        else if(temp->val>f)              // if value(node) > key , search in left subtree
        temp=temp->left;
        else
        temp=temp->right;                 // if value(node) < key , search in right subtree
        }
        if(root!=NULL){                   // Case 2 : If query value not found in BST
        insert2bst(root,*root,f);         // Add node temporarily to BST with value to be searched
        findpred(root,f);                 // Delete the newly added node so that BST remains unaffected
        deletefrombst(root,f);
        }
     }
     
int main()
{
	int i=0;
	int no_nodes,digit,num;
	cin>>no_nodes;
	int arr[no_nodes];
	for(i=0;i<no_nodes;i++)
	{
		cin>>"Enter Elements of the level order traversal:">>arr[i];
     }
     constructBst(arr,no_nodes);
     char ch;
     while((digit=fgetc(stdin))!=EOF)
     {
		if(digit=='S'){
        scanf("%d",&num);
        findsucc(&root,num);
        }
        else if(digit=='P'){
        scanf("%d",&num);
        findpred(&root,num);
        }
  }
}
     

     
     



