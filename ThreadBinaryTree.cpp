#include <iostream>
using namespace std;

struct node{
	int info;
	node *right, *left;
	bool LTH, RTH;
};

class threadBinaryTree{
	private:
		node *ptr, *dummy,*start, *ptr1;
		bool thread, child;
		int swap;
	public:
		node *root;
		int value;
		threadBinaryTree(){
			ptr = root = dummy = start = NULL;
			thread = true;
			child = false; 
			dummy = new node;
			dummy->left = dummy;
			dummy->right = dummy;
		}
		~threadBinaryTree(){
			delete ptr, root,dummy,start;	
		}
		void InsertthreadBinaryTree(node *temp){
			if(root == NULL){
				temp = new node;
				temp->info = value;
				temp->LTH = true;
				temp->RTH = true;
				temp->left = dummy;
				temp->right = dummy;
				root = temp;
				start = root;
				return;
			}
			ptr = root;
			while(ptr != NULL){
				if(ptr->info == value){
					cout << "It is duplicate value" << endl;
					return;
				}
				if(ptr->info < value){
					if(ptr->RTH == false){
						ptr = ptr->right;
					}
					else{
						break;
					}
				}
				
				if(ptr->info > value){
					if(ptr->LTH == false){
						ptr = ptr->left;
					}
					else{
						break;
					}
				}
			}
			
			if(ptr->info < value){
				temp = new node;
				temp->info = value;
				temp->right = ptr->right;
				ptr->right = temp;
				ptr->RTH = false;
				temp->left = ptr;
				temp->LTH = true;
				temp->RTH = true;
				return;
			}
			if(ptr->info > value){
				temp = new node;
				temp->info = value;
				temp->left = ptr->left;
				ptr->left = temp;
				ptr->LTH = false;
				temp->right = ptr;
				temp->LTH = true;
				temp->RTH = true;
				if(temp->left == dummy){
					start = temp;
				}
				return;
			}
		}
		
		void deleteThreadBinaryTree(){
			node *temp;
			ptr = start;
			

			while(ptr != dummy){
				if(ptr->info == value){
					// Case 1:-----------------------------------------
					if(ptr->LTH == true && ptr->RTH == true){
						cout << "// Case 1:-----------------------------------------" << endl;
						if(ptr == root){
							delete root;
							root = NULL;
							dummy->left = dummy;
							return;
						}
						temp = ptr->left;
						if(ptr->right == dummy || temp->info < ptr->info){
							temp->right = ptr->right;
							delete ptr;
							ptr = NULL;
							temp->RTH = true;
							return;
						}
						temp = ptr->right;
						if(ptr->left == dummy || temp->info > ptr->info){
							temp->left = ptr->left;
							if(ptr == start){
								start = temp;
							}
							delete ptr;
							ptr = NULL;
							temp->LTH = true;
							return;
						}
					}
					//--------------------------------------------------------
					//Case 2:-------------------------------------------------
					if(ptr->LTH == false && ptr->RTH == true){
						cout << "// Case 21:-----------------------------------------" << endl;
						if(ptr == root){
							root = ptr->left;
						}
						temp->right = ptr->right;
						temp->right->left = ptr->left;
						delete ptr;
						ptr = NULL;
						return;
					}
					if(ptr->LTH == true && ptr->RTH == false){
						cout << "// Case 22:-----------------------------------------" << endl;
						temp = (nextInorder(ptr));
						temp->left = ptr->left;
						if(ptr == start){
							start = temp;
						}
						if(ptr == root){
							root = ptr->right;
							start = root;
							temp->left->left = ptr->right;
						}
						else{
							temp->left->right = ptr->right;
						}
						delete ptr;
						ptr = NULL;
						return;
					}
					//---------------------------------------------------------
					//Case 3:-------------------------------------------------
					if(ptr->LTH == false && ptr->RTH == false){
						cout << "// Case 3:-----------------------------------------" << endl;
						temp = ptr->left;
						while(temp->RTH != true){
							temp = temp->right;
						}
						swap = ptr->info;
						ptr->info = temp->info;
						temp->info = swap;
						cout << temp->LTH << " " << temp->info << " " << temp->RTH  <<endl;
						cout << ptr->LTH << " " << ptr->info << " " << ptr->RTH  <<endl;
						if(temp->LTH == false){
							ptr1 = temp;
							while(ptr1->LTH != true){
								cout << "a" << endl;
								ptr1 = ptr1->left;
							}
							temp->left->right = temp->right; 
							ptr1->left->right = temp->left;  
							delete temp;
							temp = NULL;
							return;
						}
						if(temp == start){
							start = temp->right;
						}
						temp->left->RTH = true;
						temp->left->right = temp->right;
						delete temp;
						temp = NULL;
						return;
					}
				}
				//------------------------------------------------------------------
				temp = ptr;
				ptr = nextInorder(ptr);
			}
			cout << "Value is not in Tree" << endl;
		}
			
		
		node* nextInorder(node *temp){
			
  			if(temp->RTH == thread){
				return temp->right;
			}
  			else{
  				temp = temp->right;
    			while(temp->LTH == child) {
      				temp = temp->left;	
				}
				return temp; 
  			} 
		}
		
		void printFastInorder(){
			if(root == NULL){
				cout << "Tree is empty" << endl;
				return;
			}
			ptr = start;
			cout << ptr->info << endl;
			while((ptr = nextInorder(ptr)) != dummy){
				cout << ptr->LTH << " "<< ptr->info << " " << ptr->RTH << endl;
			}	
		}		 	 
}; 

int main(){
	
	threadBinaryTree TBT;
	int array[11] = {70,60,50,40,51,61,69,68,67,65,66};
	for(int i = 0; i  < 11; i++){
		cout << "Enter the value: " << endl;
		TBT.value = array[i];
		TBT.InsertthreadBinaryTree(TBT.root);
	}
	TBT.printFastInorder();
	for(int i = 0; i < 11; i++){
		cout << "root: " << TBT.root->info << endl;
		cout << "Enter the Delete Number: ";
		cin >> TBT.value;
		TBT.deleteThreadBinaryTree();
		cout << TBT.value << " is deleted" << endl;
		TBT.printFastInorder();
	}
}
