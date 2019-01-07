#include <iostream>
using namespace std;


struct node{
	int info;
	node *right, *left;
};

class bst{
private:
	node *temp;
	bool changeRoot;
public:
	node *root;
	bst() {
		root = NULL;
		temp = NULL;
		changeRoot = false;
	}
	void insert(node *temp1, int val) {
		if (root == NULL) {
			temp = new node;
			temp->info = val;
			temp->right = NULL;
			temp->left = NULL;
			root = temp;
			temp1 = root;
			temp = NULL;
			cout << "Value entered" << endl;
		}
		else if (val > temp1->info) {
			if (temp1->right == NULL){
				temp = new node;
				temp->info = val;
				temp->right = NULL;
				temp->left = NULL;
				temp1->right = temp;
				temp = NULL;
				cout << "Value entered" << endl;
			}
			else {
				insert(temp1->right, val);
			}
		}
		else if (val < temp1->info) {
			if (temp1->left == NULL) {
				temp = new node;
				temp->info = val;
				temp->right = NULL;
				temp->left = NULL;
				temp1->left = temp;
				temp = NULL;
				cout << "Value entered" << endl;
			}
			else {
				insert(temp1->left, val);
			}
		}

///////////////////////////////////////////////////AVL
		if (temp1 == root) {
			if (balance(temp1) == 2) {
		 		if (balance(temp1->left) == 1){
		 			changeRoot = true;
		 			clockRotation(temp1);
					cout << "test out" << endl;
		 			return;
		 		}
		 		else if (balance(temp1->left) == -1) {
		 			temp = temp1->left;
		 			antiClockRotation(temp1);
		 			changeRoot = true;
		 			clockRotation(temp1);
		 			return;
		 		}
			}
			else if (balance(temp1) == -2) {
				if (balance(temp1->right) == -1) {
					changeRoot = true;
					antiClockRotation(temp1);
					return;
				}
				else if (balance(temp1->right) == 1) {
					temp = temp1->right;
					clockRotation(temp1);
					changeRoot = true;
					antiClockRotation(temp1);
					return;
				}
			}
		}


		if (balance(temp1->left) == 2){
			if (balance(temp1->left->left) == 1) {
				temp = temp1->left;
				clockRotation(temp1);
			}
			else if (balance(temp1->left->left) == -1) {
				temp = temp1->left->left;
				antiClockRotation(temp1->left);
				temp = temp1->left;
				clockRotation(temp1);
			}
		}
		else if (balance(temp1->left) == -2) {
			if (balance(temp1->left->right) == 1) {
				temp = temp1->left->right;
				clockRotation(temp1->left);
				temp = temp1->left;
				antiClockRotation(temp1);
			}
			else if (balance(temp1->left->right) == -1) {
				temp = temp1->left;
				antiClockRotation(temp1);
			}
		}


		if (balance(temp1->right) == 2) {
			if (balance(temp1->right->left) == 1) {
				temp = temp1->right;
				clockRotation(temp1);
			}
			if (balance(temp1->right->left) == -1) {
				temp = temp1->right->left;
				antiClockRotation(temp1->right);
				temp = temp1->right;
				clockRotation(temp1);
			}
		}
		else if (balance(temp1->right) == -2) {
			if (balance(temp1->right->right) == -1) {
				temp = temp1->right;
				antiClockRotation(temp1);
			}
			if (balance(temp1->right->right) == 1) {
				temp = temp1->right->right;
				clockRotation(temp1->right);
				temp = temp1->right;
				antiClockRotation(temp1);
			}
		}
	}


	void del(node *temp1, int val) {
		node *temp2;

		if (temp1->info == val) {
			if (temp1->right == NULL && temp1->left == NULL) {
				delete temp1;
				root = NULL;
				temp1 = NULL;
				return;
			}
			else if (temp1->right == NULL && temp1->left != NULL) {
				root = temp1->left;
				delete temp1;
				temp1 = NULL;
				return;
			}
			else if (temp1->right != NULL && temp1->left == NULL) {
				root = temp1->right;
				delete temp1;
				temp1 = NULL;
				return;
			}
			else if (temp1->right != NULL && temp1->left != NULL) {
				temp2 = temp1->right;

				if (temp2->left != NULL) {
					while (temp2->left->left != NULL) {
						temp2 = temp2->left;
					}
					
					root = temp2->left;
					temp2->left = root->right;
					root->left = temp1->left;
					root->right = temp1->right;
					delete temp1;
					temp1 = NULL;
					return;
				}
				else{
					temp2->left = temp1->left;
					delete temp1;
					temp1 = NULL;
					root = temp2;
					return;
				}
			}
		}

		if(val > temp1->info){
			if (temp1->right->info == val) {
				if (temp1->right->left == NULL && temp1->right->right == NULL) {
					delete temp1->right;
					temp1->right == NULL;
					return;
				}
				if (temp1->right->left != NULL && temp1->right->right == NULL) {
					temp = temp1->right;
					temp1->right = temp1->right->left;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->right->left == NULL && temp1->right->right != NULL) {
					temp = temp1->right;
					temp1->right = temp1->right->right;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->right->left != NULL && temp1->right->right != NULL) {
					temp = temp1->right->right;

					if (temp->left != NULL) {
						while (temp->left->left != NULL) {
							temp = temp->left;
						}

						temp2 = temp1->right;
						temp1->right = temp->left;
						temp->left = temp1->right->right;
						temp1->right->left = temp2->left;
						temp1->right->right = temp2->right;
						delete temp2;
						temp2 = NULL;
						return;
					}
					else {
						temp = temp1->right;
						temp->right->left = temp->left;
						temp1->right = temp->right;
						delete temp;
						temp = NULL;
						return;
					}
				}
			}
			else {
				del(temp1->right, val);
				return;
			}
		}

		if(val < temp1->info) {
			if(temp1->left->info == val) {
				if (temp1->left->left == NULL && temp1->left->right == NULL) {
					// cout << "test" << endl;
					delete temp1->left;
					temp1->left = NULL;
					// cout << "test1" << endl;
					return;
				}
				if (temp1->left->left != NULL && temp1->left->right == NULL) {
					temp = temp1->left;
					temp1->left = temp1->left->left;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->left->left == NULL && temp1->left->right != NULL) {
					temp = temp1->left;
					temp1->left = temp1->left->right;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->left->left != NULL && temp1->left->right != NULL) {
					temp = temp1->left;

					if(temp->right != NULL) {
						while (temp->right->right != NULL) {
							temp = temp->right;
						}

						temp2 = temp1->left;
						temp1->left = temp->right;
						temp->right = temp1->left->left;
						temp1->right->left = temp2->left;
						temp1->left->left = temp2->right;
						delete temp2;
						temp2 = NULL;
						return;
					}
					else {
						temp = temp1->left;
						temp->left->right = temp->right;
						temp1->left = temp->left;
						delete temp;
						temp = NULL;
						return;
					}
				}
			}
			else {
				cout << "test" << endl;
				del(temp1->left, val);
				return;
			}
		}
	}

	void traversal(node *temp1) {
		if (root == NULL) {
			cout << "the tree is empty" << endl;
			return;
		}

		if(temp1->left != NULL) {
			traversal(temp1->left);
		}
		
		cout << "Value  : " << temp1->info << endl;
		cout << "Balance: " << balance(temp1) << endl;

		if(temp1->right != NULL) {
			traversal(temp1->right);
		}
	}

	int height(node *temp1) {
		int lh = 0;
		int rh = 0;
		int h = 0;

		if(temp1->left != NULL) {
			lh++;
			lh += height(temp1->left);
		}

		if(temp1->right != NULL) {
			rh++;
			rh += height(temp1->right);
		}

		if (lh > rh) {
			h = lh;
		}
		else if (rh > lh) {
			h = rh;
		}
		else {
			h = rh;
		}

		return h;
	}

	int balance(node *temp1) {
		int leftHeight = 0;
		int rightHeight = 0;

		if (temp1 == NULL) {
			return 0;
		}

		if (temp1->left != NULL)
			leftHeight = height(temp1->left) + 1;

		if (temp1->right != NULL)
			rightHeight = height(temp1->right) + 1;

		return leftHeight - rightHeight;
	}

	void antiClockRotation(node *temp1) {
		if ((temp1 == root) && (changeRoot == true)) {
			root = temp1->right;
			temp1->right = root->left;
			root->left = temp1;
			changeRoot = false;
			return;
		}

		
		if (temp == temp1->left) {
			temp1->left = temp->right;
			temp->right = temp1->left->left;
			temp1->left->left = temp;
		}
		else if (temp == temp1->right) {
			temp1->right = temp->right;
			temp->right = temp1->right->left;
			temp1->right->left = temp;
		}

		return;
	}

	void clockRotation(node *temp1) {
		if ((temp1 == root) && (changeRoot == true)) {
			root = temp1->left;
			temp1->left = root->right;
			root->right = temp1;
			changeRoot = false;
			return;
		}

		if (temp == temp1->left) {
			temp1->left = temp->left;
			temp->left = temp1->left->right;
			temp1->left->right = temp;
		}
		else if (temp == temp1->right) {
			temp1->right = temp->left;
			temp->left = temp1->right->right;
			temp1->right->right = temp;
		}
		return;
	}
};


int main() {
	bst tree;
	int val;
	for(int i=0;i<11;i++){
		cout << "Enter the new Value: " << endl;
		cin >> val;
		tree.insert(tree.root, val);
		tree.traversal(tree.root);
	}

	// cout << "Height: " << tree.height(tree.root) << endl;

	// cout << "Balance of Root->rigth: " << tree.height(tree.root->right->left)-tree.height(tree.root->right->right) << endl;

	// cout << "Enter the Value to delete: ";
	// cin >> val;

	// tree.del(tree.root, val);

	// tree.traversal(tree.root);

	// cout << "Enter the Value to delete: ";
	// cin >> val;


	// tree.del(tree.root, val);

	// tree.traversal(tree.root);
}

