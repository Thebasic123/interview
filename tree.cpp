#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>

using namespace std;
typedef struct node{
	int data;
	node *left;
	node *right;
	node(int data,node *left,node *right):data(data),left(left),right(right){}
	//~node();
	//void insert(int data);
}Node;

// Node::~node(){
// 	delete left;
// 	delete right;
// }
void insert(Node **tree,int data){
	if(*tree == NULL){
		*tree = new Node(data,NULL,NULL);
		return;
	}
	if((*tree)->data >= data){
		if((*tree)->left == NULL){
			(*tree)->left = new Node(data,NULL,NULL);
		}else{
			insert(&(*tree)->left,data);
		}
	}else{
		if((*tree)->right == NULL){
			(*tree)->right = new Node(data,NULL,NULL);
		}else{
			insert(&(*tree)->right,data);
		}
	}
}

bool find(Node * tree,int data){
	if(tree->data == data){
		return true;
	}else if(tree->data >= data){
		if(tree->left == NULL){
			return false;
		}else{
			return find(tree->left,data);
		}
	}else{
		if(tree->right == NULL){
			return false;
		}else{
			return find(tree->right,data);
		}
	}
}
void printInOrder(Node *tree){
	if(tree->left !=NULL){
		printInOrder(tree->left);
	}
	cout<<tree->data<<endl;
	if(tree->right != NULL){
		printInOrder(tree->right);
	}
}

void printPreOrder(Node *tree){
	cout<<tree->data;
	if(tree->left != NULL){
		printPreOrder(tree->left);
	}
	if(tree->right != NULL){
		printPreOrder(tree->right);
	}
}
void printLevelOrder(Node *tree){
	//it's bfs
	queue<Node *> q;
	q.push(tree);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		cout<<temp->data<<endl;
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}
int getHeight(Node *tree){
	if(tree == NULL){
		return 0;
	}
	return 1+max(getHeight(tree->left),getHeight(tree->right));


}
bool checkBalance(Node *tree){
	if(tree == NULL){
		return true;
	}
	int lh = getHeight(tree->left);
	int rh = getHeight(tree->right);
	if(abs(lh-rh)<=1){
		if(checkBalance(tree->left) and checkBalance(tree->right)){
			return true;
		}
	}
	return false;
}


// //output a balanced tree
// Node* getBalancedTree(){


// }

Node* buildBST(int sorted[],int start,int end){
	int middle = (start+end)/2;
	Node *root = (sorted[middle],NULL,NULL);

	root->left = buildBST(sorted,start,middle-1);
	root->right = buildBST(sorted,middle,end);
	printLevelOrder(root);
	return root;
}


int main(){
	Node *root;
	insert(&root,7);
	insert(&root,11);
	insert(&root,5);
	insert(&root,6);
	insert(&root,4);
	insert(&root,10);
	insert(&root,13);
	//insert(&root,16);
	//insert(&root,17);
	printLevelOrder(root);
	cout<<getHeight(root)<<endl;
	cout<<checkBalance(root)<<endl;

	int input[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> testV;
	testV.push_back(1);
	testV.push_back(2);
	testV.push_back(3);
	Node *newTree = buildBST(input,0,9);
	printLevelOrder(newTree);
}