////////////////////////////////////////////singly link list ////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};
class data{
private:
	node *head,*current;

public:
	////////////////////////////////// code for insert node with first node ///////////////////////////////////////////////////////////////////////
	void insert_first(){
		if(head==NULL){
			head = new node;
			cout<<"enter info :"<<endl;
			cin>>head->info;
			head->next = NULL;
		}
		else
			current = head;
			current = new node;
			cout<<"enter info :"<<endl;
			cin>>current->info;
			current->next = head;
			head = current;
	}
	///////////////////////////code for insert node with last node/////////////////////////////////////////////////////////
	void insert_last(){
		if(head==NULL){
			head = new node;
			cout<<"enter info :"<<endl;
			cin>>head->info;
			head->next = NULL;
		}
        
		else{
			current = head;
			while(current->next!=NULL){
				current = current->next;
			}
			current->next = new node;
			cout<<"enter info:"<<endl;
			cin>>current->next->info;
			current->next->next = NULL;
		}

    
	}
///////////////////////////code for insert node at mid postion /////////////////////////////////////////////////////////
	void insert_in_mid(){
	    if(head==NULL){
            head = new node;
            cout<<"enter info :"<<endl;
            cin>>head->info;
            head->next = NULL;
        }
        else{
		int key;
		cout<<"Enter key"<<endl;
		cin>>key;
		current = head;
		while(current!=NULL){
			if(current->info == key){
				temp = current;
				temp = new node;
				cout<<"Enter info :"<<endl;
				cin>>temp->info;
				temp->next=current->next;
				current->next = temp;
			}
			current = current->next;
		}
	}
}
///////////////////////////code for delete all nodes in which info equal to key /////////////////////////////////////////////////////////
void del(){
		int key;
		cout<<"Enter info to delete from the list"<<endl;
		cin>>key;
		temp = head;
		if(head->info == key){
			head = head->next;
			delete temp;
		}
		while(temp!=NULL){
			if(temp->next->info==key){
				current = temp->next;
				temp->next= temp->next->next;
				delete current;
				current = temp;
				current = NULL;
			}
			temp = temp->next;
		}
	void search(){
		int key;
		cout<<"Enter key"<<endl;
		cin>>key;
		current = head;
		while(current->next!= NULL){
			if(current->info==key){
				cout<<"found value :"<<endl;
			}
			else{
				cout<<"not found"<<end;
			}
			current = current->next;
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
void main(){
	data d;
	d.insert_last();
	d.insert_last();
	d.print();
	d.search();
}
