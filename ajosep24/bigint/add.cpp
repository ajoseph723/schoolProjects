



#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"
#include <cassert>

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
    bigint sum = 0;
    bigint one, two;
    char addnum[2][capacity];
    char digit;
    int place = 0;
    int index = 0;
    in.get(digit);
    while(!in.eof()){
        if(index > 1){
        one = addnum[0];
        two = addnum[1];
        sum = one + two;
        std::cout << one << '\n' <<  '\n' << two << '\n';
            std::cout << sum << "\n";
            sum = 0;
            index = 0;
        }else if(digit == ';'){
            addnum[index][place] = '\0';
            addnum[index][place] = '\0';
            ++index;
            place = 0;
        }else if(digit != ' ' && digit != '\n'){
            addnum[index][place] = digit;
            assert(addnum[index][place] == digit);
            ++place;
        }
        in.get(digit);
    }



    in.close();
    return 0;
}