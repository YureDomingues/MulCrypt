#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main(){
    ifstream if1("text.txt", ifstream::binary);
    ifstream if2("text2.txt", ifstream::binary);
  
    if (if1) {
    // get length of file:
    if1.seekg (0, if1.end);
    int length = if1.tellg();
    if1.seekg (0, if1.beg);

    char *buffer = new char [length];

    // read data as a block:
    if1.read (buffer,length);

    // ...buffer contains the entire file...

    for(int i=0; i<length; i++){
     cout <<  bitset<8>(buffer[i]);
    }
    

    delete[] buffer;
  }
    return 0;
}