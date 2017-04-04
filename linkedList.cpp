#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct node{
	node *next;
	int data;
	node(node *next,int data):next(next),data(data){}
}Node;

typedef struct list{
	Node *head;
	list():head(NULL){}
	void append(int data);
	void preappend(int data);
	void deleteValue(int data);
	void reverseList();
	//void reverseListr();//reverse list recursively 
}List;

void list::append(int data){
	if(head == NULL){
		head = new Node(NULL,data);
		return;
	}
	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	} 
	temp->next = new Node(NULL,data);
}
void List::preappend(int data){
	Node *newhead = new Node(head,data);
	head = newhead;
}


//must remember delete if we use new to allocate memory
void List::deleteValue(int data){
	if(head == NULL){
		return;
	}
	if(head->data == data){
		Node *temp = head->next;
		delete head;
		head = temp;
		deleteValue(data);
		return;
	}
	Node *curr = head;
	while(curr->next != NULL){
		if(curr->next->data == data){
			Node *temp = curr->next->next;
			delete curr->next;
			curr->next = temp;
		}else{
			curr = curr->next;
		}
	}
}

void List::reverseList(){
	Node *prev = NULL;
	Node *next = NULL;
	Node *curr = head;
	if(head == NULL || head->next == NULL){
		return;
	}
	next = curr->next;
	while(curr->next!=NULL){
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}
	curr->next = prev;
	head = curr;
}

void reverseListr(Node **head){
	if(*head == NULL){
		return;
	}
	if((*head)->next == NULL){
		return;
	}
	Node *first = *head;
	Node *rest = (*head)->next;
	reverseListr(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

void printList(List l){
	if(l.head == NULL){
		return;
	}
	Node *curr = l.head;
	while(curr->next != NULL){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<curr->data<<" "<<endl;
}

void printNode(Node *root){
	if(root == NULL){
		return;
	}
	Node *temp = root;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	List l = List();
	l.append(12);
	l.append(123);
	l.append(22);
	l.preappend(77);
	l.append(77);
	printList(l);
	l.deleteValue(77);
	printList(l);
	l.reverseList();
	printList(l);
	printNode(l.head);
	reverseListr(&l.head);
	printList(l);
	return 0;
}