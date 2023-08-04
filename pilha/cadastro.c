typedef struct{
    int codigo;
    char nome;
    int quant;
    double valor;
}cadastroItem;

void adicionaItem(cadastroItem item, int valor, char nome, int quant){
    item.codigo++;
    item.nome = nome;
    item.quant = quant;
    item.valor = valor;
}


int main(){

    cadastroItem item[5];
    

    return 0;
}