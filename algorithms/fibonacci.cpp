#include <cstdio>
#include <iostream>
#include <map>

 std::map<int, int> cache; 

int fib(int n) {

    if (n ==0 || n ==1) {
            return 1;
    }

    return fib(n-1) + fib(n-2);
}

int fib_optimised(int n) {

    if(cache.find(n) == cache.end()) { // value does not exist 
            if (n ==0 || n ==1) {
            return 1;
            }   
            int fn_1 = fib(n-1);
            int fn_2 = fib(n-2);

            cache[n-1] = fn_1; // store values
            cache[n-2] =  fn_2;        

    }

    return cache[n-1] + cache[n-2]; // now return the fib value
    
}

int main() {

 
    int i =0;
    
    // approach 1 (not optimised): using for loop
    // while (i < 25) {
    //     std::cout << fib(i) << std::endl;
    //     i++;
    // }

    // approach 2 (optimised): use a hashmap to store already calculated fib values
    while (i < 50) {
        std::cout << fib_optimised(i) << std::endl;
        i++;
    }

    // returned fib value is -1, due to integer overflow.


}