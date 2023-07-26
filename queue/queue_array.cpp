#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

template <class  T>
class Queue{

private:
    int start;
    int size;
    int end;
    T* data;

public:

    Queue(int size){
        if(size < 0) {
            throw std::exception();
        }
        data = new T[size];
        this->size  = size;
        start = -1;
        end = -1;
    }

    ~Queue() { // destructor
        delete data;
    }

    void insert(T value){
        // cout << "insert value " << value << "start " << start << " end" << end << endl;

        if(end == size -1) {
            cout << "Queue is full";
            return ;
        }
        if(start == -1 && end == -1) {
            start++;
            end++;
        }
        // else if( start ==  end && end == size -1 ) { // deleted all elements, should reset start and end
        //     start = 0;
        //     end = 0;
        //     cout << "eecs" << endl;

        // }
        else{
           end++;

        }
                   data[end] = value;


    }

    void remove(){
       // delete data[start];
       if(start == -1 && end == -1) {
        cout << "Queue is empty";
       }
       else if(start == end) { // only one value
            start = end = -1; //
       }
       else{ // values exist 
            start++;
       }
        

    }

    int getStart(){ // get the value of the start index
        return data[start]; 

    }

    void print(){
        cout << "start : " << start << "end: " << end << endl;
        if(start == -1 && end == -1) {
            cout << " emmty Queue" << endl;
            return; 
        }
        for(int i = start; i <= end; i++){
            cout << data[i] << endl;
        }
    }

};

int main(){

    Queue<int> q(5);
    q.insert(10);
    q.insert(20);
     q.insert(30);
      q.insert(40);
    q.insert(300);
    //   q.insert(400);

    // q.print();

    q.remove();
    q.remove();
    q.remove();
    q.remove();
    q.remove();   

    q.print();

    q.insert(10);
    // q.insert(20);

    q.print();

}

