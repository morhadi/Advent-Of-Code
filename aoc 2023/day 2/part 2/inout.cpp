//  On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number. 
// some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".
//  you now need to find the real first and last digit on each line. For example:

// two1nine
// eightwothree
// abcone2threexyz
// xtwone3four
// 4nineeightseven2
// zoneight234
// 7pqrstsixteen
// In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

#include <iostream>
#include <chrono>
#include <fstream>
#include <string> // Add missing include for string header

using namespace std;

string b[9] = {"one","two","three","four","five","six","seven","eight","nine"};

int ope(string & line){
    char l , r;
    bool f =1;
    for (int i=0; i<line.size(); i++){
        if  (line[i] >= '0' && line[i] <= '9') {
            r=line[i];
            if (f) {
                l=line[i];
                f=0;
            }
        }
        else {
            for (int j=0; j<9; j++){
                if ( line.substr( i , b[j].size() ) == b[j] ) {
                    r = j+1+'0';
                    if (f) {
                        l = j+1+'0';
                        f=0;
                    }
                    // i+=b[j].size()-1; // this is wrong, wasted 2 hours
                }
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
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nTime elapsed: " << elapsed.count() << "s\n";

    return 0;
}