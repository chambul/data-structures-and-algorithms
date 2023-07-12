#include <iostream>

using namespace std; 

class DynamicArray {

private: 
    int size;
    int capacity;
    int init_capacity;
    int* d_arr;

    void copy(int* source, int* target,int size) {
        for(int i =0; i< size; i++) {
            target[i] = source[i];
        }
    }
public: 
    DynamicArray(int cap){
        capacity = cap;
        init_capacity = cap;
        size = 0;
        d_arr = new int[cap];
    }

    int insert(int value) {
        if(size == capacity) { 
            // grow the array - create a new array with double the size and copy elements
            capacity = capacity * 2;
            cout << " expanding array, new capacity is " << capacity << endl;
            int* new_arr = new int[capacity];
            copy(d_arr,new_arr,size);
            delete d_arr; // delete current array before assigning the new one, avoding memory leak
            d_arr = new_arr;
            
        }
        d_arr[size] = value;
        size++;
    }
    int remove() {
        d_arr[size] = NULL;
        size--;
        if (size * 2 == capacity && capacity != init_capacity) // if exp is cap/2 == size, then need to check remainder as well (since 9 (cap)/2 == 4 (size) true.)
        {
            capacity = capacity / 2;
            int* a = new int[capacity];
            copy(d_arr,a,size);
            delete d_arr;
            d_arr = a;
        }
        
    }

    int print() {
        cout << " size: " << size  << "capacity " << capacity << endl;
        for(int i=0; i < size; i++) {
            cout << "value: " << d_arr[i] << ", address: " << &d_arr[i] << endl;
        }
    }
};


 int main() {

    DynamicArray arr(4);
    arr.insert(2);
    arr.insert(3);
    arr.insert(4);
    arr.insert(5);
    arr.insert(6);
    arr.print();
    arr.remove();
    arr.print();
    
    return 0;
        
}