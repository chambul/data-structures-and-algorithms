#include <iostream>
#include <stdio.h>

using namespace std; 

template<class T>
class Node{

public: 

    T data; 
    Node<T>* next;



    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(T data, Node<T>* next) {
        this->data = data;
        this->next = next;
    }

};

template<class T> 
class LinkedList{

public:
  Node<T>*  start; // these are accessed as static variables, so public
  Node<T>* end; 
  int count;



  LinkedList() {
    start = nullptr;
    end= nullptr;
    count =0;
  }
  void insert(T value) { 

        Node<T>* n = new Node<T>(value,nullptr);
        if(start == nullptr && end == nullptr) {
            start = n;
            end = n;
        }
        else{
        end->next = n;
        end = n;
        }
        count++;
  }

  void print() {
    Node<T>* iterator = start; 
    while (iterator != nullptr)
    {
        cout << iterator->data << " -->";
        iterator = iterator->next;
    } 
    cout << endl;
  }

  void remove() {
    Node<T>* prev =  start;
    Node<T>* temp =  start->next;
    while(temp != end){
        prev = prev->next;
        temp = temp->next;

        cout << " prev" << prev->data << endl;
    }
    cout << "removing " << temp->data << endl;
    prev->next = nullptr ;//temp->next;
    //temp->next == nullptr;
    delete temp; // need to delete this otherwise there's a memory leak.
    end = prev;


  }

  bool search(T value) {
    bool result = false;
     Node<T>* ref =  start;
     while(ref != nullptr) {
        if(ref->data == value){
            result =  true;
            break;
        }
        else{
            ref = ref->next;
        }
     }
     return result;
  }

};

int main() {

LinkedList<int> list; // This variable is created in stack. Because anyways the actual data of the LL is stored in heap. Only start and end pointers are in stack.
//LinkedList<int> list =  new LinkedList<int>(); - now this is created in heap.
list.insert(10);
list.insert(20);
list.insert(30);
list.print();
list.remove();
list.print();

}

