#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int tamanhoArquivo( ifstream &arq ){

    arq.seekg (0, arq.end);
    int length = arq.tellg();
    arq.seekg (0, arq.beg);

    return length;
}

fstream unirArquivos( ifstream &arq1, ifstream &arq2, string arq_out ){

    fstream out(arq_out);

    if( !out ){ cout << "Erro ao ler arq_out:" << arq_out << endl; return out; }

    int length_arq1 = tamanhoArquivo( arq1 );
    int length_arq2 = tamanhoArquivo( arq2 );
    //char *buffer_arq1 = new char [ tamanhoArquivo( arq1 ) ];
    //char *buffer_arq2 = new char [ tamanhoArquivo( arq2 ) ];

    for( int i = 0; i < max( length_arq1, length_arq2 ); i++ ){
        char char_arq;
        if( arq1 >> char_arq ) out << char_arq;
        if( arq2 >> char_arq ) out << char_arq;
    
    }
    out.close();

    return out;
}

int main(){
    ifstream if1("./tmp/text1.txt", ifstream::binary);
    ifstream if2("./tmp/text2.txt", ifstream::binary);

 
    if( !if1 ){ cout << "Erro ao ler if1" << endl; return 0; }
    if( !if2 ){ cout << "Erro ao ler if2" << endl; return 0; }

    unirArquivos( if1, if2, "./tmp/res.dat");

    // get length of file:


    //int length = tamanhoArquivo(if1);
    //char *buffer = new char [length];

    // read data as a block:
    //if1.read (buffer,length);

    // ...buffer contains the entire file...

    //for(int i=0; i<length; i++){
    //    cout <<  bitset<8>(buffer[i]);
    //}


    //delete[] buffer;
    

    return 0;
}