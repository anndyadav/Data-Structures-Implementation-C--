#include<iostream>
#include<bits/stdc++.h>

 using namespace std;
 
 int top = -1;
 
 int isfull(int arr[],int size){
 	if(top==size-1){
 		return true;
	 }
	 else{
	 	return false;
	 }
 }
 
 int isempty(){
 	if(top==-1){
 		return true;
	 }
	 else{
	 	return false;
	 }
 }
 
 int push(int arr[],int size,int item){
 	if(isfull(arr,size)){
 		return -1;
	 }
	 top+=1;
	 arr[top] = item; 
	 printf("%d Pushed\n",item);	 
 }
 
 int pop(int arr[]){
 	if(isempty()){
 		return -1;
	 }
	 printf("%d Popped\n",arr[top]);
	 top-=1;
 }
 
 int peek(int arr[]){
 	return arr[top];
 }
 
 int main(){
 	int size = 10;
 	int arr[size];
 	push(arr,size,5);
 	push(arr,size,15);
	push(arr,size,25);
	push(arr,size,35);
	pop(arr);
	pop(arr);
	printf("Topmost element: %d",peek(arr));
 return 0;
 }

