package stack;

import java.util.ArrayList;

class Stack <T>{

    int top = -1;
    int capacity; 
    ArrayList<T>  stack  = null;

    public Stack(int capacity){
        this.capacity = capacity ; 
        this.stack = new ArrayList<>(capacity);

    }

    public void push(T value){

        if (top + 1 == this.capacity) {
            System.out.println("Stack is full!");
            return ;
        }
        this.top++;
        stack.add(top, value);
    }

    public T pop(){
        
        if(top == -1){
            System.out.println("Stack is empty!");
            return null;
        }

        top--;
        return stack.get(top+1);

    }

    public T peek(){

        return this.stack.get(top);
    }

    public void printStack(){
        for(int i = this.top; i >= 0; i--){
            System.out.print(this.stack.get(i) + "<-");

        }
        System.out.println();
    }

}

public class StackDemo{


    public static void main(String args[]) {
        Stack<Integer> stack1 = new Stack<>(5);
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);
        stack1.push(40);
        stack1.push(50);
        stack1.push(60);
        stack1.printStack();


        System.out.println("removing top element: " +stack1.pop()); ;
        System.out.println("now the top element is: " + stack1.peek());
        stack1.push(30);
        stack1.printStack();
    }


}