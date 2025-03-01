# MulCrypt

### Objetivo:
esse projeto tem como objetivo criar um sistema capaz de encriptar dois arquivos em um so. 
Esse arquivo unico tera 2 senhas de acesso, uma das senha retorna o primeiro arquivo e a outra senha retorna o segundo arquivo.

### Como esta sendo feito:

atualmente temos uma funcao que junta os dois arquivos sequancialmente ou seja:
```
arq1 = [1234567890]
arq1 = [abcdefgh]

arq_resultante = [1a2b3c4d5e6f7g8h9 0 ]


```


### Futuro 

No futuro do projeto pretendemos adaptar a incriptacao AES(Advanced Encrypt Standard) para que a separacao dos arquivos dependa da senha