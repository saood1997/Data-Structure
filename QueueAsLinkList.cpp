# include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class Queue{
	private:
		node *front, *rear, *temp;
		int size, count;
	public:
		Queue(){
			front = NULL;
			rear = NULL;
			temp = NULL;
			cout << "Enter the size: ";
			cin >> size;
			count = 0;
		}
		
		~Queue(){
			delete front, rear, temp;
		}
		
		void EnQueue(){
			if(count >= size){
				cout << "Queue is overflow" << endl;
				return;
			}
			if(rear == NULL){
				rear = new node;
				cin >> rear->info;
				rear->next = NULL;
				front = rear;
				count++;
				return;
			}
			temp = rear;
			rear = new node;
			cin >> rear->info;
			temp->next = rear;
			rear->next = NULL;
			count++;
		}
		
		void DeQueue(){
			if(front == NULL){
				cout << "It is underflow" << endl;
				return;
			}
			temp = front;
			front = front->next;
			delete temp;
			temp =NULL;
			count--;
		}
		
		void print(){ // greatest sins for Queue
			temp = front;
			while(temp != NULL){
				if(temp == rear){
					cout << temp->info << endl;
				}
				else{
					cout << temp->info << " <- ";
				}
				temp = temp->next;
			}
			cout << endl;
		}
		
};



int main(){
	Queue q;
	for(int i = 0; i < 10; i++){
		q.EnQueue();
	}
	q.print();
	q.DeQueue();
	q.print();
	q.DeQueue();
	q.print();
}
