/* Os m´odulos de vinculação dinâmica em C para webassembly
    não podem possuir imports de bibliotecas e nem funções
    da biblioteca padrão, tais como: printf e scanf.*/

int increment(int val){
    return val+1;
}