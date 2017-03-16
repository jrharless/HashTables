#include "hash.hpp"
#include "objhash.hpp"
#include <cmath>
#include <vector>
#include <iostream>
#include <string>


void print(int vecarr[]){
	for (int i = 0; i< 10; i++){
	std::string k ="   ";
	if (vecarr[i] != -1)
	{k = std::to_string(vecarr[i]);}
	
	
	std :: cout<<i<<"  "<< k << "\n";}
	
	
	}

void insertlinear(int inputarr[]){
	std :: cout <<"Hash Table with Linear Probing \n";
	
	int linarr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	bool inserted;
	for(int t = 0; t<10;t++){
		if (inputarr[t] != 0){
		int key = inputarr[t] % 10;
		
		inserted = false;
		int tmp = key;
		int count =0;
		while ((count<10) &&(!inserted)) {
			if (linarr[key] == -1){
			linarr[key] = inputarr[t];
			inserted = true;	
		}
			count+=1;
			key+=1;
			if (key >= 10){
				key = key % 10;
			}	
		}
	
	if (!inserted){
	std :: cout << "Could not insert : " << inputarr[t] <<"\n";
	}
	}
	}
	
	print(linarr);
	
}
void insertquad(int inputarr[]){
	std :: cout <<"Hash Table with Quadratic Probing \n";
	int quadarr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	bool inserted;
	for(int t = 0; t<10;t++){
		if (inputarr[t] != 0){
		int key = inputarr[t] % 10;
		
		inserted = false;
		int tmp = key;
		int count =0;
		while ((count<10) &&(!inserted)) {
			if (quadarr[key] == -1){
			quadarr[key] = inputarr[t];
			inserted = true;	
		}
			count +=1;
			key = tmp;
			key += count*count;
			if (key >= 10){
				key = key % 10;
			}	
		}
	
	if (!inserted){
	std :: cout << "Could not insert : " << inputarr[t] <<"\n";
	}
	}
	}
	
	print(quadarr);
	
}

void doublehashing(int inputarr[]){
	std :: cout <<"Hash Table with Double Hashing \n";
	
	int quadarr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	bool inserted;
	
	for(int t = 0; t<10;t++){
	
		if (inputarr[t] != 0){
		int key = inputarr[t] % 10;
		
		inserted = false;
		int tmp = key;
		int count =0;
		
		while ((count<10) &&(!inserted)) {
			if (quadarr[key] == -1){
			quadarr[key] = inputarr[t];
			inserted = true;	
		}
			count +=1;
			
			key += (7 - inputarr[t] % 7);
			if (key >= 10){
				key = key % 10;
			}	
		}
	
	if (!inserted){
	std :: cout << "Could not insert : " << inputarr[t] <<"\n";
	}
	}
	}
	
	print(quadarr);
	
}


void sepchaining(int inputarr[]){
	std :: cout <<"Hash Table with Separate Chaining \n";
	
	
	
	
	OBJ_T * start1 = new OBJ_T;
	OBJ_T *start2 = new OBJ_T;
	OBJ_T *start3 = new OBJ_T;
	OBJ_T *start4 = new OBJ_T;
	OBJ_T *start5 = new OBJ_T;
	OBJ_T *start6 = new OBJ_T;
	OBJ_T *start7 = new OBJ_T;
	OBJ_T *start8 = new OBJ_T;
	OBJ_T *start9 = new OBJ_T;
	OBJ_T *start10 = new OBJ_T;
	
	
	start1->next = NULL;
	start2->next = NULL;
	start3->next = NULL;
	start4->next = NULL;
	start5->next = NULL;
	start6->next = NULL;
	start7->next = NULL;
	start8->next = NULL;
	start9->next = NULL;
	start10->next = NULL;
	
	
	
	OBJ_T* doublearr[10] = {start1,start2,start3,start4,start5,start6,start7,start8,start9,start10};
	
	
	for(int t = 0; t<10;t++){
	
		
		if (inputarr[t] != 0){
		
		int key = inputarr[t] % 10;
		
		OBJ_T * node = new OBJ_T;
		node->value = inputarr[t];
		
		if (doublearr[key]->next == NULL){
 			node->next = NULL;
 			doublearr[key]->next = node	;
			
						
		}
		else{
		node->next = doublearr[key]->next;
		doublearr[key]->next =node;
		}	 
			}	
		}
	for(int e = 0; e<10;e++){
		std :: cout << e << " ";
		if (doublearr[e]->next !=NULL){
		doublearr[e] = doublearr[e]->next;
		for (doublearr[e]; 
			doublearr[e] != NULL; 
			doublearr[e] = doublearr[e]->next){
				std :: cout << " ->" << doublearr[e]->value;
			}
		}	
		std :: cout << " ->_" << "\n";
	
	
}
}

int main(){

std :: cout << "Please enter up to 10 non-negative integers, followed by -1: ";
int n = 0;
int inputarr[10] = {0};
int count = 0; 
while ((n != -1) && count <10){
	std :: cin >> n;
	if (n !=-1){
	
	inputarr[count] = n;
	count = count +1;
	}
}
int linear[10];
insertlinear(inputarr);
insertquad(inputarr);
doublehashing(inputarr);
sepchaining(inputarr);

return 0;
}



