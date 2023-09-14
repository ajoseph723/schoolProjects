//Austin Joseph
//reading a text file
#include <iostream>
#include <fstream>

int main() {
    //reading the first .txt file
    std::ifstream wordfile("fileio-text.txt");
    //checking to make sure the file opened
    if(!wordfile.is_open()){
        std::cout << "Can't open file\n";
        return 1;
    }

    char ch;
    while(!wordfile.eof()){
        //checks if the character is a space or \n and either
        //outputs ch or \n
        if(ch != '\n' && ch != ' '){
            std::cout << ch;
        }else
            std::cout << '\n';
        wordfile.get(ch);
    }
    wordfile.close();
    std::cout << '\n';

    //reading the second .txt file
    std::ifstream numfile("fileio-data-1.txt");
    //checking to make sure the file opened
    if(!numfile.is_open()){
        std::cout << "Can't open file\n";
        return 1;
    }
    int sum = 0;
    int num[2] = {0, 0};
    int index = 0;
    char digit;
    numfile.get(digit);
    while(!numfile.eof()){
        if(index > 1){
            sum = num[0] + num[1];
            std::cout << sum << "\n";
            num[0] = 0;
            num[1] = 0;
            sum = 0;
            index = 0;
        }else if(digit == ';'){
            ++index;
        }else if(digit != ' ' ){
            int currentnum = digit - '0';
            num[index] = num[index] * 10 + currentnum;
        }
        numfile.get(digit);
    }


    return 0;
}