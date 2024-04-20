#include <iostream>
#include<chrono>
#include <fstream>
#include <string> // Add missing include for string header

using namespace std;

int ope(string & line){
    char l , r;
    bool f =1;
    for(char& c:line){
        if(c >= '0' && c <= '9'){
            r=c;
            if (f) {
                l=c;
                f=0;
            }
        }            
    }
    return  ((l-'0')*10 + (r-'0') );
}

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // Start timing
    std::ifstream fname("input.txt");
    // ifstream fname("demo.txt");
    string line;
    int ans = 0;

    while(fname >> line) {
        ans +=  ope(line);
    }
    fname.close();
    cout<< ans;
    auto end = std::chrono::high_resolution_clock::now(); // End timing
    std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time
    std::cout << "\nTime elapsed: " << elapsed.count() << "s\n"; // Output elapsed time
    return 0;
}