#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>

int main(){
    printf("ola mundo!\n");
    EM_ASM( // esta mnacro permite executar código js no arquivo c
        InitWrappers(); // invoca função definida lá no js
    );
    printf("Inicialização completa!\n");
}

void test(){
    printf("buttom test");
}

void int_test(int num){
    printf("int test=%d\n",num);
}

void float_test(float num){
    printf("float test=%f\n",num);
}

void string_test(char* str){
    printf("string test=%s\n",str);
}