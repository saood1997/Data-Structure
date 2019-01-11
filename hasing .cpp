#include<iostream>
#include<stdio.h>
using namespace std;

class hashing{
	private:
		int items;
		int * array;
		int * array2; 
		int counter;
		int value;
		int halfing;
		int items2;
	public:
		hashing(){
		cout << "Enter the total number of nodes:"<<endl;
		cin >> items;
		halfing = items;
		counter = 0;
		items2 = 0;
		value = 0 ;
		array = new int[items];	
		for(int i = 0; i < items; i++) 
		{ 
			array[i] = 1;
		}
	}
	int hashing_function(int * array){
		int indexstoring = 0;
		
		if(counter == (halfing / 2)){
			extended_array(array);
			counter = 0;
			return 0;
		}
		cout << "Enter the value:"<<endl;
		cin >> value;
		indexstoring = value % items;
		
		if(array[indexstoring] == 1){
			array[indexstoring] = value;
			cout << array[indexstoring] << endl;
			counter++;
			return 0;
		}
		if(array[indexstoring] != 1 ){
			while(array[indexstoring] != 1){
				cout << array[indexstoring] <<endl;
				indexstoring++;
				if(indexstoring >= (items-1))
				{
					indexstoring = 0;
				}
			}
			array[indexstoring] = value;
			cout << array[indexstoring] << endl;
			counter++;
			return 0;
			 
			
		}
	}
	
	int extended_array(int * array){
		items2  = items * 2;
		cout << "Items2:" << items2 << endl;
		while(1)
		{
			if(prime_function(items2) == 1){
				break;
			}
			else{
				items2++;
			}
		}
		array2 = new int[items2];
		for(int i = 0; i < items2; i++){
			array2[i] = 1;
 		}
 		halfing  = items2;
 		copying_array(array2,array);
 		
 		hashing_function(array2);
 		printing_function(array2);
 		
	}
	int copying_array(int * array2,int *array){
		for(int i = 0; i < (items / 2); i++){
			if(array[i] != 1 ){
				int indexstoring = array[i];
				array2[indexstoring] = array[i];
			}
		}
	}
	
	int prime_function(int value){
		int num = 2;
		int flag  = 1;
		while(value > num){
			if(value % num  == 0){
				flag = 0;
				}
				num++;
		}
		if(flag == 1){
			return 0;
			
		}
		else{
			return 1;
		}
		
		
	} 
	
	int Calling_function()
	{	
		for(int i = 0; i < items; i++)
		{
			hashing_function(array);
		}
	}
	
	
	int printing_function(int * array)
		{
		for (int i = 0; i < items2; ++i){
			
			cout << array[i] << "   "  ; 
		}
	}
			
};

int main(){
	hashing h;
	h.Calling_function();
	return 0;
}
