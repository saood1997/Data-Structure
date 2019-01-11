#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};
class CBT{
	private:
		bool flag;
	public:
		int swap;
		node *root,*temp,*ptr,*height_check;
		int number,count;
	    int	 h,ph;
		CBT(){
			root = ptr = temp = NULL;
			h = ph = 0;
			flag = false;
		}
		void CBT_insertion(node *temp){
			flag = false;
			if(root == NULL){
				temp = new node;
				temp->info = number;
				temp->left = NULL;
				temp->right = NULL;
				root = temp;
				count++;
				return;
			}
			else if(count == pow(h)){
				while(temp->left!=NULL){
					temp = temp->left;
				}
				temp->left = new node;
				temp->left->info = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				count++;
				h++;
				return;
			}
			else if(count != pow(h)){
				set(temp);
				if(ptr->left!=NULL && ptr->right == NULL){
					cout << "right: " << endl;  
					temp = new node;
					temp->info = number;
					ptr->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
				if(ptr->left ==NULL && ptr->right == NULL){
					cout << "left: " << endl;  
					temp = new node;
					temp->info = number;
					ptr->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
			}
		}
		void set(node *temp){
			if(temp->left != NULL && ph<h){
				ph++;
				set(temp->left);
				ph--;
			}
			if(temp->right!=NULL && ph<h){
				ph++;
				set(temp->right);
				ph--;
			}
			if(temp->left == NULL && ph == h-1 || temp->right == NULL && ph == h-1){
				if(flag == false){
					ptr = temp;
					flag = true;
					return;
				}
			}
		}
		int pow(int h){
			int result = 2;
			int y = h+1;
			for(int i = 1;i<y;i++){
				result = result*2;
			}
			return result-1;
		}
		
		void deletion(node *temp){
			set_deletion(temp);
			if(root->left == NULL){
				cout<<"root deleted :"<<root->info<<endl;
				delete root;
				root = NULL;
				return;
			}
			while(temp->left != NULL){
				temp = temp->left;
			}
			height_check = temp;
			if(ptr->right != NULL && ptr->left != NULL){
				temp = ptr->right;
				cout << temp->info << " is deleted" << endl;
				ptr->right = NULL;
				delete temp;
				temp = NULL;
				return;
			}
			
			temp = ptr->left;
			if(ptr->right == NULL && ptr->left != NULL){
				if(height_check == temp){
					h--;
				}
				cout<<"deleted info :"<<temp->info<<endl;
				ptr->left = NULL;
				delete temp;
				temp = NULL;
				return;		
			}
			
			
		}
		void set_deletion(node *temp){
			if(temp->left!=NULL){
				ph++;
				set_deletion(temp->left);
				ph--;
			}
			if(ph == h-1 && temp->left!=NULL){
				ptr = temp;
			}
			if(temp->right != NULL){
				ph++;
				set_deletion(temp->right);
				ph--;
			}
		}
		void in_order(node *temp){
  			if(temp->left!=NULL ){
    			in_order(temp->left);
    		}
    		cout<<temp->info<<" ";
  			if(temp->right!=NULL ){
				in_order(temp->right);
		 	}
		}
};
int main(){
	CBT b;
	for(int i=0;i<11;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.CBT_insertion(b.root);
	}
	cout<<" : tree :"<<endl;
	b.in_order(b.root);
	cout<<endl;
	for(int i=0;i<11;i++){
		b.deletion(b.root);
		b.in_order(b.root);
		cout << endl;
	}
	
}

