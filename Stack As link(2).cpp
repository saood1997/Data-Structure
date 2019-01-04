#include <iostream>
using namespace std;



struct node{
	int info;
	node *next;
};

class Stack{
	private:
		int size, count;
		node *top, *temp;
	public:
		Stack(){
			count = 0;
			top = NULL;
			temp = NULL;
			cout << "Enter the size: ";
			cin >> size;
		}
		
		~Stack(){
			delete temp;
			delete top;
			size = 0;
		}
		
		
		void push(){
			if(count < size){
				if(top == NULL){
					top = new node;
					cin >> top->info;
					top->next = NULL;
					count++;
				}
				else{
					temp = new node;
					cin >> temp->info;
					temp->next = top;
					top = temp;
					count++;
				}
			}
			else{
				cout << "Stack is overflow" << endl;
				return;
			}
		}
		
		
		void pop(){
			cout << "Pop" << endl;
			temp = top;
			if(top == NULL){
				cout << "Stack is underflow" << endl;
			}
			else{
				top = top->next;
				delete temp;
				temp = NULL;
				count--;
				return;
			}	
		}
		
		void print(){ // greatest sins for stack
			cout << "Stack" << endl;
			temp = top;
			while(top != NULL){
				cout << "- " <<top->info << " -" << endl;
				top = top->next;
			}
			top = temp;
		}
		
};




int main(){
	Stack s;
	for(int i = 0; i < 7; i++){
		s.push();
	}
	
	for(int i = 0; i < 3; i++){
		s.print();
		s.pop();
	}
	s.print();
}
