#include <iostream>
using namespace std;


class Queue{
	private:
		int *front, *rear, *array, *temp;
		int size, count;
	public:
		Queue(){
			cout << "Enter the size: ";
			cin >> size;
			count = 0;
			array = new int[size];
			front = NULL;
			rear = NULL;
			temp = NULL;
		}
		~Queue(){
			delete []array;
		}
		void EnQueue(){
			if(count >= size){
				cout << "It is overflow" << endl;
				return;
			}
			if(rear == NULL){
				rear = array;
				cin >> *rear;
				front = rear;
				count++;
				return;
			}
			if(rear == array+(size-1) && count < size){
				cout << "(rear == array+(size) && count < size)" << endl;
				rear = array;
				cin >> *rear;
				count++;
				return;
			}
			rear++;
			cin >> *rear;
			count++;
		}
		void DeQueue(){
			if(front == NULL){
				cout << "It is underFlow" << endl;
				return;
			}
			if(front == array+(size-1)){
				temp = front;
				front = array;
				*temp = 0;
				count--;
				return;
			}
			temp = front;
			front++;
			count--;
			*temp = 0;
		}
		void print(){ // greatest sins for Queue 
			temp = front;
			while(temp != rear){
				if(temp == array+(size-1) && count < size){
					temp = array;
				}
				cout << *temp << " <- ";
				temp++;
			}
			cout << *temp << endl;
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
	q.EnQueue();
}

