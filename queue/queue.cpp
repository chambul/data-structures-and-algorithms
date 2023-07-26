#include <cstdio>
#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(){
        this->data = nullptr;
        this->next = nullptr;
    }

    Node(T data, Node* next){
        this->data = data;
        this->next = next;
    }

};

template <class T>
class Queue{

private:
 Node<T>* start;
 Node<T>* end; 
 int count;

public:

    Queue() {
        start = nullptr;
        end = nullptr;
        count =0;
    }

    void enqueue(T val) {
        Node<T>*  node = new Node<T>(val, nullptr);
        if(start == nullptr) {
                start = node;
                end = node;
        }
        else{
                start->next = node;
                end = node;
        }

        count++;
    }

    // delete the element
    void dequeue() {

        if(start == nullptr) {
            cout << " queue is aready empty!!";

        }
        Node<T>* tmp; 
        tmp = start; 
        start = start->next;
        // tmp->next = nullptr;  not needed, since we already delete the node 
        delete tmp;

    }

    T peek() { // get data of the start
        if(start == nullptr) {
            cout << " queue is aready empty!!";
            throw exception();

        }
        return start->data;

    }


     void print(){
        Node<T>* p = start;
        while(p != nullptr){
            cout << p->data << " -->";
            p = p->next;
        }

        cout << endl;
    }

};


int main() {

    Queue<int> q;
    q.enqueue(10); // 
    q.enqueue(20); // 

    q.print();

    q.dequeue();
    q.print(); 

    cout << q.peek();
}