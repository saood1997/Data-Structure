#include<iostream>
using namespace std;


struct node{
	int info;
	node *next;
	node *pre;	
};	

class ring{
	node *head,*temp,*current;
public:
	ring(){
		head = temp = current = NULL;
	}
		void insert_first(){
			if(head == NULL){
				head = new node;
				cout<<"Enter info 1"<<endl;
				cin>>head->info;
				head -> next = head;
				head ->pre = head;
			}
			else if(head->next == head){
				current = new node;
				cout<<"Enter info 2"<<endl;
				cin>>current->info;
				current->next = head;
				head->next = current;
				current->pre=head;
				head->pre=current;
				
			}
			else {
				temp = new node;
				cout<<"Enter info 3"<<endl;
				cin>>temp->info;
				temp->next = current;
				current->pre = temp;
				temp->pre = head;
				head->next = temp;
				current = temp;
			}
			
		}
		void insert_last(){
			if(head == NULL){
				head = new node;
				cout<<"Enter info 1"<<endl;
				cin>>head->info;
				head -> next = head;
				head ->pre = head;
			}
			else if(head->next == head){
				current = new node;
				cout<<"Enter info 2"<<endl;
				cin>>current->info;
				current->next = head;
				current->pre = head;
				head->next = current;
				head->pre=current;
				
			}
			else {
				temp = new node;
				cout<<"Enter info 3"<<endl;
				cin>>temp->info;
				temp->next = head;
				temp->pre = current;
				current->next = temp;
				head->pre = temp;
				current = temp;
			}
			
		}
		void insert_mid(){
			int key;
			cout<<"Enter key to add in mid"<<endl;
			cin>>key;
			temp = head;
			if(temp->info==key){
				temp = new node;
				cout<<"Enter info to add node with first node"<<endl;
				cin>>temp->info;
				temp->next = head->next;
				head->next->pre = temp;
				temp->pre = head;
				head->next = temp;
			}
			while(temp->next != head){
				if(temp->info == key){
					current = new node;
					cout<<"Enter info to add node in mid "<<endl;
					cin>>current->info;
					current->next = temp->next;
					temp->next->pre = current;
					current->pre = temp;
					temp->next = current;
				}
				temp = temp->next;
			}
			if(temp->info == key){
				current = new node;
				cout<<"Enter info to add node with last node"<<endl;
				cin>>current->info;
				current->next = head;
				head->pre = current;
				current->pre = temp;
				temp->next = current;
			}
		}
		
			void delet(){
			int key;
			cout<<"Enter key to delete "<<endl;
			cin>>key;
			temp = head;
			if(temp->info==key){
				current = head;
				while(current->next!=head){
					current = current->next;
				}
				head = head->next;
				head->pre = current;
				current->next = head;
				delete temp;
				temp = NULL;
			}
			while(temp->next != head){
				if(temp->next->info == key){
					current = temp->next;
					temp->next = current->next;
					current->next->pre = temp;
					delete current;
					current = NULL;
				}
				temp = temp->next;
			}
			if(temp->next->info == key){
				current = temp->next;
				temp->next = current->next;
				head->pre = temp;
				delete current;
				current = NULL;
			}
		}
		void print(){
			current = head;
			cout<<"////////////////link list//////////////"<<endl;
			while(current->next != head){
				cout<<current->info<<endl;
				current =current->next;
			}
			cout<<current->info<<endl;
		}
		
		
				
};

int main(){
	ring r1;
	
	for(int i = 0;i<5;i++){
		r1.insert_first();
	}
	r1.print();
	for(int i = 0;i<5;i++){
		r1.insert_last();
	}
	r1.print();
	r1.insert_mid();
	r1.print();
	r1.delet();
	r1.print();
}
