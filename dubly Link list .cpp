#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *pre;
};
class data{
	node *head,*temp,*current;
public:
	data(){
		head = NULL;
		temp = NULL;
		current = NULL;
	}
////////////////////////////code for to insert at first//////////////////////////////////////////
	void insert(){
		if(head == NULL){
			head = new node;
			cout<<"Enter info 1 :"<<endl;
			cin>>head->info;
			head->next = NULL;
		}
		else{
			temp = head;
			current = temp;
			current = new node;
			cout<<"Enter info 2 "<<endl;
			cin>>current->info;
			current->next = temp;
			temp->pre = current;
			current->pre = NULL;
			head = current;

		}
		
	}
////////////////////////////code for to insert in last//////////////////////////////////////////
	void insert_last(){
		if(head == NULL){
			head = new node;
			cout<<"Enter info to insert at last 1"<<endl;
			cin>>head->info;
			head->next= NULL;
			head->pre = NULL;
		}
		else{
			current = head;
			
			while(current->next!= NULL){
				current = current->next;
			}
			temp = current;
			current = new node;
			cout<<"Enter info  to insert at last 2"<<endl;
			cin>>current->info;
			current->next = NULL;
			temp->next = current;
			current->pre = temp;
		}

	}
////////////////////////////code for to insert at any mid postion//////////////////////////////////////////
	void insert_mid(){
		int key;
		cout<<"Enter key to be added :"<<endl;
		cin>>key;
		current = head;
		while(current!=NULL){
			if(current->info==key){
				temp = current;
				temp = new node;
				cout<<"Enter info for node:"<<endl;
				cin>>temp->info;
				temp->next = current->next;
				current->next->pre = temp;
				temp->next = current->next;
				current->next= temp;
				temp->pre = current;
			}
			current = current->next;
	}
	}
////////////////////////////code for delete a link list any mid value or first node //////////////////////////////////////////
	void delet(){
		if(head == NULL){
			cout<<"Can't be deleted because link has no value :"<<endl;
		}
		int value;
		cout<<"Enter value to be delet :"<<endl;
		cin>>value;
		temp = head;
		if(head->info == value){
			head = head->next;
			delete temp;
			temp = NULL;
		}
		while(temp!=NULL){
			if(temp->next->info==value){
				current = temp;
				current = temp->next;
				temp->next = current->next;
				current->next->pre = temp;
				delete current;
				current = NULL;
				break;
			}
			temp = temp->next;
		}


	}
	void print(){
		current = head;
		while(current!= NULL){
			cout<<current->info<<endl;
			current = current->next;
		}

	}




};
int main(){
	data d;
	for(int i = 0;i<5;i++){
		d.insert();
	}
	for(int i = 0;i<5;i++){
		d.insert_last();
	}
	d.insert_mid();
	d.print();
	d.delet();
	return 0;
}
