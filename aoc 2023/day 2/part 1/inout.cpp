#include <iostream>
#include <chrono>
#include <fstream>
#include <unordered_map> // Add missing include for unordered_map
#include <string> // Add missing include for string header
using namespace std;
// Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes.
unordered_map<string, int> m = {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};
bool ispos (string & s){
    for(auto [color, val]:m){
        int in = 9 ;
        int no=0;
        while(in != string::npos) {
            in = s.find(color, in); 
            if(in == string::npos) break;
            no = in -2;
            in++;
            while(s[no] != ' ') no--;
            no++;
            // if ( stoi(s.substr(no, in-2-no) ) > m["green"] ) return false;
            cout<<s.substr(no, in-1-2-no)<<"\t";
            if (to_string(val).compare(s.substr(no, in-1-2-no) ) < 0) return false;
        }
    }
    return true;
}
int main() {
    chrono::time_point<chrono::high_resolution_clock> start, end; // Declare start and end timepoint
    start = chrono::high_resolution_clock::now(); // Start timing
    ifstream fname("demo.txt");
    if (!fname) {
        std::cout << "Failed to open file\n";
        return 1;
    }
    cout<<"ok\n";

    string line;
    int ans = 0;
    // while(fname >> line) {
    while(std::getline(fname, line)) {
        // cout<<line;
        bool flag = ispos(line) ;
        // cout<<flag;
        if(flag) {
            ans+=(int)(line[5]-'0');
            // cout<<ans<<"\t";
            cout<<line[5]<<"\t";
            }
        // if(ispos(line)) ans+=(int)(line[5]-'0');
    }
    fname.close();
    cout<< "\n"<<ans;

    end = std::chrono::high_resolution_clock::now(); // End timing
    std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time
    std::cout << "\nTime elapsed: " << elapsed.count() << "s\n"; // Output elapsed time
    return 0;
}
//  example above, games 1, 2, and 5 would have been possible

// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
// Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
// Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
// Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
// Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

    // int in = 9 ;
    // int no=0;
    // while((in != string::npos)) {
    //     in = s.find("green", in); 
    //     no = in -2;
    //     while(s[no] != ' ') no--;
    //     no++;
    //     // if ( stoi(s.substr(no, in-2-no) ) > m["green"] ) return false;
    //     if (to_string(m["green"]).compare(s.substr(no, in-2-no) ) < 0) return false;
    // }

    // in = 9 ;
    // while((in != string::npos)) {
    //     in = s.find("red", in); 
    //     no = in -2;
    //     while(s[no] != ' ') no--;
    //     no++;
    //     // if ( stoi(s.substr(no, in-2-no) ) > m["red"] ) return false;
    //     if (to_string(m["red"]).compare(s.substr(no, in-2-no) ) < 0) return false;
    // }

    // in = 9 ;
    // while((in != string::npos)) {
    //     in = s.find("blue", in); 
    //     no = in -2;
    //     while(s[no] != ' ') no--;
    //     no++;
    //     // if ( stoi(s.substr(no, in-2-no) ) > m["blue"] ) return false;
    //     if (to_string(m["blue"]).compare(s.substr(no, in-2-no) ) < 0) return false;
    // }