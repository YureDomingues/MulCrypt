#include <iostream>
#include <fstream>
#include <bitset>
#include <sstream>

using namespace std;

int tamanhoArquivo( ifstream &arq ){

    arq.seekg (0, arq.end);
    int length = arq.tellg();
    arq.seekg (0, arq.beg);

    return length;
}

ofstream unirArquivos( ifstream &arq1, ifstream &arq2, string arq_out ){

    ofstream out(arq_out);

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

void desunirArquivos(string arq_unido, int ordem_arq){
    if(ordem_arq < 0 || ordem_arq > 1) { cout << "Houve um erro na ordem do arquivo específicado." << endl;}

    ifstream in(arq_unido, ios::in);
    ofstream out("./tmp/saida.dat", ios::out);

    if(!in){cout << "Erro ao ler o arquivo de entrada." << endl;}
    if(!out) {cout << "Erro ao gerar o arquivo de saída." << endl;}

    int length_arq_unido = tamanhoArquivo( in );

    for( int i = 0; i < length_arq_unido/2; i++ ){
        char char_arq;

        if(ordem_arq == 0){
            in >> char_arq;
            out << char_arq;
            in >> char_arq;
        }
        if(ordem_arq == 1){
            in >> char_arq;
            in >> char_arq;
            out << char_arq;
        }

    }

    in.close();
    out.close();
}

int main(){
    ifstream if1("./tmp/text1.txt", ifstream::binary);
    ifstream if2("./tmp/text2.txt", ifstream::binary);

 
    if( !if1 ){ cout << "Erro ao ler if1" << endl; return 0; }
    if( !if2 ){ cout << "Erro ao ler if2" << endl; return 0; }

    unirArquivos( if1, if2, "./tmp/res.dat");

    desunirArquivos("./tmp/res.dat", 1);

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