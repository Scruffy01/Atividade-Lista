#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void removerultimosN (int quant){
    if (quant >= n){
        while (n>0) {
            removerInicio();}
    }else {
    int rem = 0;
    while (rem < quant){
        removerFinal();
        rem++;
    }   }  }


    void removeSEGelemento(){
    if (n <= 1) return;

    No* aux = inicio->prox;
        inicio->prox = aux->prox;
        delete aux;
        if (n == 2) {
            fim = inicio;
        }
        n--;

    }

    void inserirNOfinalTAMANHO(){
     No* novo = new No(n);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }


     void inserirateN(int valorN) {
        int valor = 1;
        while (valor <= valorN) {
            inserirFinal(valor);
            valor++;
        }
    }

    void inserirPENULT(int valor) {
        if (n <= 1) return;

        No* novo = new No(valor);
        if (n == 2) {
            novo->prox = fim;
            inicio->prox = novo;
        } else {
            No* aux = inicio;
            while (aux->prox != fim) {
                aux = aux->prox;
            }
            novo->prox = fim;
            aux->prox = novo;
        }
        n++;
    }

    void imprimir() {
        printf ("LISTA: \n");
       if (n == 0){
        printf("vazio \n\n");
       return;}

        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

int main() {

    Lista l;
    int opcao, valor, quant, valorN;

    do {
            printf("Menu:\n");
        printf("1. InserirInicio\n");
        printf("2. InserirFinal\n");
        printf("3. RemoverInicio\n");
        printf("4. RemoverFinal\n");
        printf("5. Imprimir\n");
        printf("6. Remover N no fim\n");
        printf("7. Remover segundo elemento\n");
        printf("8. Inserir no final o tamanho da lista\n");
        printf("9. Inserir todos os numeros de 1 ate N\n");
        printf("10. Inserir na penultima posicao da lista\n");
        printf("11. Sair\n");

        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d%*c", &valor);
                l.inserirInicio(valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d%*c", &valor);
                l.inserirFinal(valor);
                break;

            case 3:
                l.removerInicio();
                break;

            case 4:
                l.removerFinal();
                break;

            case 5:
          l.imprimir();
                break;

                case 6:
          printf("Digite o N de elementos a remover: ");
                scanf("%d%*c", &quant);
                l.removerultimosN(quant);
                break;

                case 7:
                l.removeSEGelemento();
                break;

                case 8:
                l.inserirNOfinalTAMANHO();
                break;

                case 9:
                printf("Digite o N de elementos que deseja inserir na lista: ");
                scanf("%d%*c", &valorN);
                l.inserirateN(valorN);
                break;

                case 10:
                printf("Digite um valor: ");
                scanf("%d%*c", &valor);
                l.inserirPENULT(valor);
                break;

        };

    } while (opcao != 11);

    return 0;
}
