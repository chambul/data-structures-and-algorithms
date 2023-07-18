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

int main() {

    string str = "(){}"; 
    bool unbalanced = false;
    Stack<char> s(str.length());

    
    for(int i=0; i < str.length(); i++) {
        char b1 = str[i];

        //if opening bracket push
        if(b1 == '{' || b1 == '[' || b1 == '(') {
            if(s.empty() && i == str.length() -1 ) {
                cout << " brackets are imbalanced " << endl;
                unbalanced =  true;
                break;
            }
            s.push(b1);
            s.print();
        } 
        else if (b1 == '}' || b1 == ']' || b1 == ')') {
            if(s.empty()) {
                cout << " brackets are imbalanced " << endl;
                unbalanced =  true;
                break;
            }
            char b2 = s.head();
            if ((b2 == '{' &&  b1 == '}') || (b2 == '[' &&  b1 == ']') || (b2 == '(' &&  b1 == ')')) {
                // matches
                s.pop();
            }
            else{
                // not matching
                cout << " brackets are imbalanced " << endl;
                unbalanced =  true;
                break;
            }
            
        }
    }

    if(s.empty() == 0 && !unbalanced) {
        cout << " brackets are balanced " << endl;
    } 

    return EXIT_SUCCESS;
}
