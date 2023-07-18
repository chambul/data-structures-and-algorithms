#include <cstdio>
#include <iostream>

using namespace std;

template <class T>
class Stack{
private:
    int _size;
    int _head;
    T* _data;
public:
    Stack(int size){
        _size = size;
        _head = -1;
        _data = new T[size];
    }
    void push(T data){
        if (_head == _size - 1)
        {  
            cout << "Stack full" << endl;
            return;
        }
        _data[++_head] = data;
    }
    T& head(){
        if (_head == -1)
            throw exception();
        return _data[_head];
    }
    T& pop(){
        if (_head == -1)
            throw exception();
        _head--;
        return _data[_head];
    }

    bool empty(){
        return _head == -1;
    }

    void print(){
        for (int i = 0; i <= _head; i++){
            cout << &_data[i] << " ";
        }
        cout << endl;
    }
};

int main() { // modified the main to include in 

Stack<double> s1(5); // local variable in stack, actual data in heap.
s1.push(10.0);
// s1.push(20);
// s1.push(30);
// s1.push(40);
// s1.push(50);
// s1.push(60);
s1.print(); 
s1.pop();
//  s1.pop(); s1.pop();
// s1.print(); 


}