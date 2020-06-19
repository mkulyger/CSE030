#include <iostream>
#include <vector>

#include <TimeSupport.h>
#include <RandomSupport.h>

using namespace std;

struct IntArray { // We have given our new data structure (struct) a name, which is IntArray
	// All we need to do now is to specify what kind of information it needs to store
	// and what actions it can perform

	int count;
	int capacity; // These variables are not initialized. The first thing we need to do
	              // is to initialize the variables so that the data structure can work correctly
	int* storage; // We need to create a special function called the "constructor" whose job it is
	              // to provide initial values to all the variables here

	// We now build a constructor
	// The constructor explains what should happen when the IntArray variable is created
	IntArray(){
		// Give appropriate initial values to the variables
		count = 0;
		capacity = 1;
		storage = new int[capacity];
	}

	void append(int x){
		if (count == capacity){
			int oldCapacity = capacity; // Remember how big the array used to be
			capacity = capacity * 2; // Recalculate the capacity

			int* temp = new int[capacity]; // the array temp is twice as large as arr

			// Copy all the values from arr to temp
			for (int i = 0; i < oldCapacity; i++){
				temp[i] = storage[i];
			}

			// Now release the memory occupied by arr
			delete[] storage;

			// Now make arr point to the same location as temp

			storage = temp;

		}
		storage[count] = x;
		count++;
	}
	
	int valueAt(int pos){
		if (pos >= count){
			throw std::out_of_range ("Array index out of bounds");
		}
		else{
			return storage[pos];
		}
	}

	int operator[](int position){
		return valueAt(position);
	}


};


ostream& operator<<(ostream& os, IntArray& arr){
	for (int i = 0; i < arr.count; i++){
		os << arr.valueAt(i) << " ";
	}
    return os;
}

// Linked List

struct Node{
	int data;
	Node* next;
};


void append(Node* head, int x){
	Node* temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	// temp is pointing to the last element in the list

	temp->next = new Node();
	temp->next->data = x;
	temp->next->next = NULL;
}


void print(Node* head){
	Node* temp = head;
	while (temp!= NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
}


int main(){


	int N = 1000000;


	// =================== Resizable Array =========================

	IntArray myResizableArray;

	timestamp start = current_time();

	for (long i = 0; i < N; i++){
		myResizableArray.append(i);
	}

	timestamp end = current_time();

	long duration = time_diff(start, end);

	cout << "It took " << duration << " ms." << endl;


	// =================== Fixed Array =========================


int* other = new int[N];

	timestamp fixedStart = current_time();

	for (long i = 0; i < N; i++){
		other[i] = i;
	}

	timestamp fixedEnd = current_time();

	long fixedDuration = time_diff(fixedStart, fixedEnd);

	cout << "It took " << fixedDuration << " ms." << endl;

	delete[] other;


	// =================== Linked List =========================

	Node* head = new Node;

	head->data = 5;
	    					 // In C++ if we have a pointer to a struct (and not a variable of that type), then its 
	head->next = NULL;		// properties can be accessed with the -> operator, not the . operator
	
	append(head, 7);

	print(head);


	// =================== Random Number Generation =========================
	
	RandomGenerator<int> myGen(1, 10);

	int r = myGen.next();

	cout << "Random value: " << r << endl;

	return 0;
}
