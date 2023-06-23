#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>

int isPrime(int valor){
    if(valor==2) return 1; // exceção
    if(valor<=1 || valor%2==0) return 0; // menor que 1 ou valor par
    for(int i=3;(i*i)<=valor;i+=2){ // percorre todos os valores intermediários
        if(valor%i==0) return 0; // encontrou um valor divisível
    }
    return 1; // o valor é realmente primo
}

// função inicial do módulo webassembly
int main(int argc, char const *argv[]){
    int start=3;
    int end=100000;
    printf("Primos entre os valores %d e %d:\n",start,end);
    for(int i=start;i <=end;i+=2){
        if(isPrime(i)){
            printf("%d-",i);
        }
    }
    printf("\n");
    return 0;
}
