#include <iostream>
using namespace std;

class Stack{
	private:
		int size, count;
		int *top, *array, *last, *temp;
	public:
		Stack(){
			count = 0;
			cout << "Enter the size: ";
			cin >> size;
			top = last = NULL;
			temp = NULL;
			array = new int[size];
			last = array + (size-1);
			
		}
		~Stack(){
			delete top;
			delete temp;
			delete last;
			delete [] array;
			
		}
		
		void Push(){
			if(count >= size){
				cout << "It is overflow" << endl;
				return;
			}
			if(top == NULL){
				top = array;
				cin >> *top;
				count++;
				return;
			}
			top++;
			cin >> *top;
			count++;
			return;
		}
		
		void Pop(){
			if(top == NULL){
				cout << "It is  empty" << endl;
				return;
			}
			*top = NULL;
			count--;
			top--;
		}
		
		void Print(){ // greatest sins for stack
			cout << " " << endl;
			cout << "Stack" << endl;
			for(temp = top; temp >= array; temp--){
				cout <<"- " << *temp << " -" <<endl;
			}
		}
};



int main(){
	Stack s;
	for(int i = 0; i < 9; i++){
		s.Push();
	}
	s.Print();
	s.Pop();
	s.Print();

}



