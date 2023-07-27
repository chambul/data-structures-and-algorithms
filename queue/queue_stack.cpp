#include <iostream>
#include <cstdio>
#include <stack>

using std::cout;
using std::stack;
using std::endl;

template<class T>
class Queue{

private:
    stack<T> s1;
    stack<T> s2;

public:

    Queue() {


    }

    ~Queue(){
        
    }

    stack<T> getS1() {
        return s1;
    }
        stack<T> getS2() {
        return s2;
    }

    void enqueue(T value){

        s1.push(value);

    }

   void dequeue(){
        
        if(s1.empty() && s2.empty()) {
            cout << "Queue is empty!";
            return ;
        }
        if(s2.empty()) {
            while(!s1.empty()) {
             s2.push(s1.top());
             s1.pop();
          
            }

        }
        
        T v = s2.top();
        s2.pop(); //delete element
       // return v;
    
    }


};

int main() {

    Queue<int> q;
    q.enqueue(1);
   q.enqueue(2);
    q.enqueue(3);
   q.enqueue(4);

    q.dequeue();
    q.dequeue();

   cout <<  q.getS1().size() << endl;
      cout <<  q.getS2().size() << endl;


}
