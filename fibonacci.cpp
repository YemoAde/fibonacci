#include <iostream>
#include <unordered_map>
#include <chrono>
#include <vector>
using namespace std::chrono;

//This is much of an overkill
//overengineering :)
int fibbo_memo_map (int n, std::unordered_map<int, int> *accumulator) {
    if (n <= 1) return n;
    if(accumulator->find(n) != accumulator->end()) {
        return accumulator->at(n);
    }
    (*accumulator)[n] = fibbo_memo_map(n-1, accumulator) + fibbo_memo_map(n-2, accumulator);
    return accumulator->at(n);
}

//slowest
int fibbo_normal (int n) {
    if (n <= 1) return n;
    return fibbo_normal(n-1) + fibbo_normal(n-1);
}

int fibbo_tail (int n, int a = 0, int b = 1) {
    if (n == 0) 
        return a; 
    if (n == 1) 
        return b; 
    return fibbo_tail(n - 1, b, a + b);
}

int fibbo_memo_vector (int n) {
    std::vector<int> acc(n+2);
    acc[0] = 0;
    acc[1] = 1;
    for(int i = 2; i <= n; i++) 
    {
       acc[i] = acc[i - 1] + acc[i - 2]; 
    } 
    return acc[n];
}

int fibbo_loop (int n) {
    int a = 0, b = 1, c, i; 
    if( n == 0) return a; 
    for(i = 2; i <= n; i++) 
    { 
       c = a + b; 
       a = b; 
       b = c; 
    } 
    return b;
}


int main () {
    int number;
    std::unordered_map<int, int> memo;
    memo[0] = 0;
    memo[1] = 1;
    std::cout << "Enter Value" << std::endl;
    std::cin >> number;
    auto start = high_resolution_clock::now();
    // fibbo_memo(number, &memo);
    // fibbo_tail(number);
    // fibbo_normal(number);
    //** fastest for 1000000
    // fibbo_loop(number); 
    //** fastest
    // fibbo_memo_vector(number);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    std::cout << duration.count() << std::endl; 

}