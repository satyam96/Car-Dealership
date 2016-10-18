
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure for D

struct node{
	int key;	//key=Car prices
	int value;	//value=model
	int height;	//AVL constraint :p 
	struct node *left;
	struct node *right;
};

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int height(struct node *N){
	if(N==NULL)
		return 0;
	else
		return N->height;
}

struct node *newNode(int key,int value){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->key=key;
	node->value=value;
	node->left=NULL;
	node->right=NULL;
	node->height=1; //heght initialized as 1,newnode will be at height 1
	
return (node);
}

//subtree rooted with y
struct node *rightRotate(struct node *y)
{
	struct node *x=y->left;
	struct node *T2=x->right;
	
	//Do rotations
	//Just manipulation of pointers so O(1)
	x->right=y;
	y->left=T2;
	
	//Update heights
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}

//subtree rooted at x
struct node *leftRotate(struct node *x){

	struct node *y=x->right;
	struct node *T2=y->left;
	
	//Do left rotation
	y->left = x;
    	x->right = T2;
    	
    	x->height = max(height(x->left), height(x->right))+1;
    	y->height = max(height(y->left), height(y->right))+1;
 
return y; //y is new root

}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

//Insert Function for AVL Trees
struct node* insert (struct node* node,int key,int value){

	if(node==NULL)
	return(newNode(key,value));
	
	if(key < node->key)
	   node->left=insert(node->left,key,value);
	else
	   node->right=insert(node->right,key,value);
	   
	 //Update heights
	 node->height = max(height(node->left), height(node->right)) + 1;
 
 	int balance=getBalance(node);
 	
 	  // Left Left Case
        if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    	// Right Right Case
        if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
        // Left Right Case
       if (balance > 1 && key > node->left->key)
       {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
       }
 
       // Right Left Case
      if (balance < -1 && key < node->right->key)
      {
        node->right = rightRotate(node->right);
        return leftRotate(node);
     }
     
     return node;

}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the key of node */
     printf("%d %d", node->key,node->value);
     printf("\n***********\n");  

     /* now recur on right child */
     printInorder(node->right);
}
void Print(struct node *root,int k1,int k2)
{
	if(root==NULL)
	return;
	if(k1 < root->key)
	Print(root->left,k1,k2);
	if(k1<=root->key && k2>=root->key)
 printf("Price is %d and  model number is %d\n",root->key,root->value);
if(k2> root->key)
  Print(root->right,k1,k2);
}

int main()
{
 struct node *root=NULL;
 
  root = insert(root,10,1);
  root = insert(root,20,2);
  root = insert(root,30,3);
  root = insert(root,40,4);
  root = insert(root,50,5);
  root = insert(root,25,6);
  
  scanf("%d %d",&k1,&k2);
  printf("values in the range k1,k2 are\n");
  Print(root,k1,k2); int k1,k2;
  printf("Enter k1 & k2\n");
 

return 0;
}
