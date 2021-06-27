#include <iostream>
using namespace std;
struct node{				//node structure
	int info;
	node* left;				//left pointer
	node* right;			//right pointer
	node* p;				//parent
	bool red;				//boolean to determine whether node is black(red=false) or red(red=true)
};

node* root=new node;		//root node
node* temp=new node;

node* newnode(int key){		//to create a new node with value/key
	node* p=new node;	p->info=key;	p->left=NULL;	p->right=NULL;	p->red=true;	p->p=NULL;
	return p;
}
void rotleft(node* x){		//left rotation of node x
	node* y=new node;
	y=x->right;
	if(y!=NULL && y->left)
	{
		x->right=y->left;
		if(y->left->p!=NULL)
			y->left->p=x;
	}
	else
		x->right=NULL;
	if(y!=NULL)
		y->p=x->p;
	if (x->p==NULL)
		root=y;
	else if(x->p->left && x==x->p->left)
		x->p->left=y;
	else if(x->p->right && x==x->p->right)
		x->p->right=y;
	y->left=x;
	x->p=y;
}
void rotright(node* y){		//right rotation of node x
	node* x=new node;
	x=y->left;
	if(x!=NULL){
		y->left=x->right;
		if(x->right)
			x->right->p=y;
		x->p=y->p;
	}
	if (y->p==NULL)
		root=x;
	else if (y->p!=NULL && y->p->left && y==y->p->left)
		y->p->left=x;
	else if (y->p!=NULL && y->p->right && y==y->p->right)
		y->p->right=x;
	x->right=y;
	y->p=x;
}
void colfix(node* x){		//to fix/balance rb tree after insertion of a node
	node* temp=new node;
	while(x->p!=NULL && x->p->red==true){
		if(x->p==(x->p->p->left)){
			temp=x->p->p->right;
			if(temp!=NULL && temp->red==true){
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL){
					x->p->p->red=true;
					x=x->p->p;
				}
			}
			else if(x==x->p->right){
				x=x->p;
				rotleft(x);
			}
			else if(x==x->p->left){
				x->p->red=false;
				x->p->p->red=true;
				rotright(x->p->p);
			}
		}
		else{
			temp=x->p->p->left;
			if( temp!=NULL && temp->red==true ){
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL){
					x->p->p->red=true;
					x=x->p->p;
				}
			}
			else if(x==x->p->left){
				x=x->p;
				rotright(x);
			}
			else if(x==x->p->right){
				x->p->red=false;
				x->p->p->red=true;
				rotleft(x->p->p);
			}
		}
	}
	root->red=false;
}
void add(node *t2,int x){	//to insert a node in rb tree
	if(root==NULL)
	{
		root=newnode(x);
		root->red=false;
		return;
	}
	else
	{
		if(t2->info>x)
		{
			if(t2->left!=NULL)
				add(t2->left,x);
			else{
				t2->left=newnode(x);
				t2->left->p=t2;
				if(t2->left->p->p!=NULL){
					colfix(t2->left);
				}
			}
		}
		else if(t2->info<x)
		{
			if(t2->right!=NULL)
				add(t2->right,x);
			else{
				t2->right=newnode(x);
				t2->right->p=t2;
				if(t2->right->p->p!=NULL){
					colfix(t2->right);
				}
			}
		}
	}
}
void inorder(node* temp){	//inorder traversal of rb tree
	if(root==NULL){
		cout<<"\n Create tree first";
		return;
	}
	else if(root->info==-1){
		cout<<"\n Create tree first";
		root=NULL;
		return;
	}
	if(temp==NULL)
		return;
	inorder(temp->left);
	if(temp==root)
		cout<<"\nroot: "<<temp->info;
	else if(temp->info==-1)
		return;
	else
		cout<<"\n"<<temp->info;
	if(temp->red )
		cout<<" color:red";
	else
		cout<<" color:black";
	inorder(temp->right);
}
int main()					// main driver function
{
	root=NULL;
	temp=NULL;
	char ch='y';
	int x=0;
	while(ch=='y'){
		cout<<"\nMenu For RB-tree Actions:\n1.Insertion\nEnter your Choice:";
		int choice=0;
		cin>>choice;		//input for action
		switch(choice)
		{
			case 1:{
				int n=0;
				cout<<"Enter no. of elements:";
				cin>>n;
				cout<<"\nEnter elements:";
				for (int i = 0; i < n; ++i)
				{
					cin>>x;
					add(root,x);
				}
				break;
			}
			default: cout<<"\nWrong input";
		}
		cout<<"\n	Status after action(s)	";
		inorder(root);
		cout<<"\nDo wish to continue? (y/n)";
		cin>>ch;
	}
}
