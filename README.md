# MulCrypt

### Objetivo:
esse projeto tem como objetivo criar um sistema capaz de encriptar dois arquivos em um so. 
Esse arquivo unico tera 2 senhas de acesso, uma das senha retorna o primeiro arquivo e a outra senha retorna o segundo arquivo.

### Como esta sendo feito:

atualmente temos uma funcao que junta os dois arquivos sequancialmente ou seja:
```
arq1 = [1111111111]
arq1 = [00000000]

arq_resultante = [10101010101010101 1 ]


```


### Futuro 

adicionar tabela com referencial aos caracteres da senha:
```
x  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
 +----------------------------------------------
0| 0  5  8  1  A  E  C  F  6  3  9  D  7  B  4  2  
1| D  4  E  C  F  A  8  7  5  3  1  6  0  B  2  9  
2| A  2  E  4  C  9  3  5  7  8  1  D  F  B  6  0  
3| A  F  6  7  C  0  D  E  5  8  3  B  9  1  4  2  
4| B  1  8  5  3  C  9  D  E  A  2  0  6  4  7  F  
5| 5  8  4  F  C  3  0  E  2  1  9  7  D  A  B  6  
6| F  E  3  C  6  8  A  1  0  D  7  2  4  5  9  B  
7| C  9  4  E  0  6  F  3  D  8  1  5  A  B  7  2  
8| E  A  C  1  4  D  2  8  5  F  3  0  7  9  B  6  
9| 5  4  E  B  D  6  F  1  A  9  3  C  8  7  0  2  
A| 9  B  F  D  6  0  8  C  3  5  2  4  E  7  A  1  
B| 0  4  3  2  D  C  A  F  B  6  1  8  7  E  9  5  
C| 7  E  B  F  0  3  6  2  8  5  A  4  9  1  D  C  
D| B  4  5  0  F  8  E  D  A  6  2  1  3  7  C  9  
E| B  2  C  1  9  3  F  7  5  8  E  D  6  0  A  4  
F| 7  0  3  9  B  F  8  6  E  2  A  5  C  4  1  D  

```

cada senha tera uma tabela assim codificada no header, com isso ao encriptar podemos usa as coordenadas e x = "4 bits do arquivo" e y = "char da senha", com isso podemos passar por todos os bits e substitulos de 4 em 4 pelo valor da tabela (x,y);

No futuro do projeto pretendemos adaptar a incriptacao AES(Advanced Encrypt Standard) para que a separacao dos arquivos dependa da senha