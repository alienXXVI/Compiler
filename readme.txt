Compilação:

cd C:\Users\alian\Documents\AlianaArquivos\UNIOESTE\3ANO\Compiladores\Trabalho2\Trabalho\src>

yacc -d analise_sintatica.y
lex analise_lexica.l
gcc (Get-ChildItem -Recurse -Path "C:\Users\alian\Documents\AlianaArquivos\UNIOESTE\3ANO\Compiladores\Trabalho2\Trabalho" -Filter "*.c").FullName -o gçç
.\gçç ..\codigos_teste\teste_yacc.txt