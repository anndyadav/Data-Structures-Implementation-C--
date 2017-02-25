#include<iostream>
#include<bits/stdc++.h>

/*
    *
    * Anand Yadav
    *
*/

using namespace std;

struct dlinklist{
	int data;
	struct dlinklist *left;
	struct dlinklist *right;
};

typedef struct dlinklist node;
int countNode();

node *start = NULL;

node *getnode(){
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	printf("Enter Data:");
	scanf("%d",&newnode->data);
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void createList(int n){
	int i;
	node* newnode;
	node* temp;
	for(i=0;i<n;i++){
		newnode = getnode();
		if(start==NULL){
			start = newnode;
		}
		else{
			temp = start;
			while(temp->right){
				temp = temp->right;
			}
			temp->right = newnode;
			newnode->left = temp;
		}
	}
}
void printListLtoR(){
	node* temp;
	temp = start;
	if(temp==NULL){
		printf("Empty List.");
	}
	else{
		printf("LtoR ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->right;
		}
		printf("\n");
	}	
}

void printListRtoL(){
	node* temp;
	temp = start;
	if(temp==NULL){
		printf("Empty List.");
	}
	else{
		while(temp->right!=NULL){
			temp = temp->right;
		}
	}
	printf("RtoL ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->left;
	}
	printf("\n");
}

void insertBeginining(){
	node* temp;
	temp = getnode();
	if(start==NULL){
		start = temp;
	}
	else{
		temp->right = start;
		start->left = temp;
		start = temp;
	}	
}

void insertEnd(){
	node* newnode;
	node* temp;
	newnode = getnode();
	if(start==NULL){
		start = newnode;
	}
	else{
		temp = start;
		while(temp->right!=NULL){
			temp = temp->right;
		}
		temp->right = newnode;
		newnode->left = temp;
	}
}

void insertMid(){
	int pos, length=0;
	length = countNode();
	node* newnode = getnode();
	node* temp;
	pos = length%2;
	while(pos){
		temp = temp->right;
		pos--;
	}
	newnode->right = temp->right;
	newnode->left = temp;
}

void deleteBeginining(){
	node* temp;
	if(start==NULL){
		printf("UnderFlow.");
		return;
	}
	else{
		temp = start;
		start = start->right;
		start->left = NULL;
		free(temp);
	}
}

void deleteEnd(){
	node* temp;
	if(start==NULL){
		printf("Underflow.");
		return;
	}
	else{
		temp = start;
		while(temp->right){
			temp = temp->right;
		}
		temp->left->right = NULL;
		free(temp);
		temp = NULL;
	}
}

void deleteMid(){
	int pos;
	int length = countNode();
	node* temp;
	pos = length%2;
	while(pos){
		temp = temp->right;
		pos--;
	}
	temp->left->right = temp->right;
	temp->right->left = temp->left;
	free(temp);
	temp = NULL;
}


int countNode(){
	node* temp;
	temp = start;
	int count = 0;
	while(temp!=NULL){
		count++;
		temp = temp->right;
	}
	return count;
}
int main(){
	createList(8);
	printListLtoR();
	printListRtoL();
	insertBeginining();
	printListLtoR();
	insertEnd();
	printListLtoR();
	deleteEnd();
	printListLtoR();
return 0;

}

