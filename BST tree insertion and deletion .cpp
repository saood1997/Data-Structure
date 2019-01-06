#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};

class BST{
	private:
		node *temp,*current,*temp1,*temp3;
	public:
		int number,temp2,l_count,r_count;
		node *root;
		int num;
		BST(){
			temp = root = current = NULL;
			l_count = r_count = 0;
		}
		void binary(node *temp){
			if(root == NULL){
     			temp = new node;
     			temp->info = number;
    			temp->left = NULL;
     			temp->right = NULL;
     			root = temp;
     			return;
   			}
 			if(temp->info==number){
      			cout<<" Given number is already present in tree."<<endl;
      			return;
    		}
    		if(temp->info > number){
      			if(temp->left!=NULL){
					binary(temp->left);
		 			return;
      			}
      			else{
	 				temp->left=new node;
	 				temp->left->info = number;
	 				temp->left->left=NULL;
	 				temp->left->right=NULL;
	 				return;
       			}
   			}
   			if(temp->info < number){
      			if(temp->right!=NULL){
					binary(temp->right);
		 			return;
       			}
     			else{
	 			temp->right=new node;
	 			temp->right->info = number;
	 			temp->right->left=NULL;
	 			temp->right->right=NULL;
	 			return;
       			}
   			}
		}
		void delet(node *temp){
				if(root->info == num){   //To delete the root
					if(root->left!=NULL && root->right!=NULL){
						temp = root;
						current = temp;
						temp1 = current->right;    // move towords one unit right to find successor	
						if(temp1->left == NULL){ // if no left child.
							temp2 = temp1->info;
							temp1->info = current->info;
							current->info = temp2;
							if(temp1->right!=NULL){ // if successor having right childs.
								current->right = temp1->right;
								delete temp1;
								temp1 = NULL;
								return;
							}
							else{    // if successor having not right childs.
								current->right = NULL;
								delete temp1;
								temp1 = NULL;
								return;
							}
						}
		
						if(temp1->left != NULL){
							if(temp1->left->left == NULL){ //if only one left node
								temp2 = temp1->left->info;
								temp1->left->info = current->info;
								current->info = temp2;
								temp3 = temp1->left;
								if(temp3->right!=NULL){  //if successor having right childs.
									temp1->left = temp3->right;
									delete temp3;
									temp3 = NULL;
									return;
								}
								else{    //if successor having not right childs.
									temp1->left = NULL;
									delete temp3;
									temp3 = NULL;
									return;
								}	
							}
							if(temp1->left->left!=NULL){ // if more than one left nodes
								while(temp1->left->left!=NULL){ //finding the successor
									temp1 = temp1->left;
								}	
								temp2 = temp1->left->info;      //swaping
								temp1->left->info = current->info;
								current->info = temp2;
								temp3 = temp1->left;
								if(temp3->right!=NULL){        //if successor having right child.
									temp1->left = temp3->right;
									delete temp3;
									temp3 = NULL;
									return;
								}
								else{      //if successor having not right child.
									temp1->left = NULL;
									delete temp3;
									temp3 = NULL;
									return;
								}
							}	
						}
					}
				}
				
				if(temp->info<num){
					if(temp->right->info == num){  // for delete right leaf(case 1)
							if((temp->right->right == NULL)&&(temp->right->left == NULL)){
							delete temp->right;
							temp->right = NULL;
							return;
						}
						if((temp->right->left!=NULL)&&(temp->right->right==NULL)){ //for (case 2) one leaf present
							current = temp;
							current = current->right;
							temp->right = current->left;
							delete current;
							current = NULL;
							return;
						}
						if((temp->right->left==NULL)&&(temp->right->right != NULL)){ //for (case 2) one leaf present
							current = temp;
							current = current->right;
							temp->right = current->right;
							delete current;
							current = NULL;
							return;	
						}
						if((temp->right->left!=NULL) && (temp->right->right!=NULL)){ //case(3) both leaf are present in right sub tree
							current = temp;
							current = current->right;
							temp1 = current->right;    // move towords one unit right to find successor	
		
							if(temp1->left == NULL){ // if no left child.
								temp2 = temp1->info;
								temp1->info = current->info;
								current->info = temp2;
								if(temp1->right!=NULL){ // if successor having right childs.
									current->right = temp1->right;
									delete temp1;
									temp1 = NULL;
									return;
								}
								else{    // if successor having not right childs.
									current->right = NULL;
									delete temp1;
									temp1 = NULL;
									return;
								}
							}
		
							if(temp1->left != NULL){
								if(temp1->left->left == NULL){ //if only one left node
									temp2 = temp1->left->info;
									temp1->left->info = current->info;
									current->info = temp2;
									temp3 = temp1->left;
									if(temp3->right!=NULL){  //if successor having right childs.
										temp1->left = temp3->right;
										delete temp3;
										temp3 = NULL;
										return;
									}
									else{    //if successor having not right childs.
										temp1->left = NULL;
										delete temp3;
										temp3 = NULL;
										return;
									}	
								}
								if(temp1->left->left!=NULL){ // if more than one left nodes
									while(temp1->left->left!=NULL){ //finding the successor
										temp1 = temp1->left;
									}	
									temp2 = temp1->left->info;      //swaping
									temp1->left->info = current->info;
									current->info = temp2;
									temp3 = temp1->left;
									if(temp3->right!=NULL){        //if successor having right child.
										temp1->left = temp3->right;
										delete temp3;
										temp3 = NULL;
										return;
									}
									else{      //if successor having not right child.
										temp1->left = NULL;
										delete temp3;
										temp3 = NULL;
										return;
									}
								}	
							}
						}
					}
					else{
						delet(temp->right);
						//return;
					}
				}
				if(temp->info>num){
					if(temp->left->info == num){  // for delete left leaf(case 1)
						if((temp->left->left == NULL) && (temp->left->right == NULL)){
							delete temp->left;
							temp->left = NULL;
							return;
						}
						if((temp->left->left!=NULL)&&(temp->left->right==NULL)){ //for case 2  
							current = temp;
							current = current->left;
							temp->left = current->left;
							delete current;
							current = NULL;
							return;	
						}
						if((temp->left->left==NULL)&&(temp->left->right != NULL)){ // for case 2
							current = temp;
							current = current->left;
							temp->left = current->right;
							delete current;
							current = NULL;
							return;	
						}
						
						if((temp->left->left!=NULL) && (temp->left->right!=NULL)){ //case(3) both leaf are present in left sub tree
							current = temp;
							current = current->left;
							temp1 = current->left;    // move towords one unit left to find pre_successor
		                    
							if(temp1->right == NULL){ // if no right node
								temp2 = temp1->info;
								temp1->info = current->info;
								current->info = temp2;
								if(temp1->left!=NULL){ // if pre_successor having left childs.
									current->left = temp1->left;
									delete temp1;
									temp1 = NULL;
									return;
								}
								else{    // if pre_successor having not left childs.
									current->left = NULL;
									delete temp1;
									temp1 = NULL;
									return;
								}	
							}
		
							if(temp1->right != NULL){ 
								if(temp1->right->right == NULL){ //if only one right node
									temp2 = temp1->right->info;
									temp1->right->info = current->info;
									current->info = temp2;
									temp3 = temp1->right;
									if(temp3->left!=NULL){ //if pre_successor having left childs.
										temp1->right = temp3->left;
										delete temp3;
										temp3 = NULL;
										return;
									}
									else{            //if pre_successor having not left childs.
										temp1->right = NULL;
										delete temp3;
										temp3 = NULL;
										return;
									}	
								}
								if(temp1->right->right!=NULL){ // if more than one right nodes
								
									while(temp1->right->right!=NULL){ //finding the successor
										temp1 = temp1->right;
									}					
									temp2 = temp1->right->info;      //swaping
									temp1->right->info = current->info;
									current->info = temp2;
									temp3 = temp1->right;
									if(temp3->left!=NULL){ //if successor having left childs.
										temp1->right = temp3->left;
										delete temp3;
										temp3 = NULL;
										return;
									}
									else{                 //if successor having not left child.
										temp1->right = NULL;
										delete temp3;
										temp3 = NULL;
										return;
									}
								}	
							}
						}
					}
				
					else{
						delet(temp->left);
						//return;
					}
		}
}
void in_order(node *temp){
  			if( temp->left!=NULL ){
    			in_order(temp->left);
    		}
  			if( temp->right!=NULL ){
		 		in_order(temp->right);
  				return;
  			}
  			if(root==NULL){
				cout<<" Tree is empty.\n";
				return;
    		}
    		cout<<temp->info<<"  ";
    		if(temp->left->left!=NULL){
    			l_count++;
			}
			if(temp->right->right!=NULL){
				r_count++;
			}
			
    	}
};


int main(){
	BST b;
	for(int i = 0;i<5;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.binary(b.root);
	}
	b.in_order(b.root);
	cout<<endl;
	cout<<"fhj"<<endl;
	cout<<"right hight"<<b.r_count<<endl;
	cout<<"left height"<<b.l_count<<endl;
	cout<<"Enter info to delete :"<<endl;
	cin>>b.num;
	b.delet(b.root);
	b.in_order(b.root);
}
