#include <stdlib.h>
#include<stdio.h>
struct no_arvore{
    char elemento;
    struct no_arvore* esquerda;
    struct no_arvore* direita;
};
struct minha_string{
    char elemento;
    struct minha_string* proximo;
};
struct arvore{
    struct no_arvore* raiz;
};

typedef struct no_arvore* pointer_no;
typedef struct minha_string* p_s;

p_s add_s(p_s string,char elemento){
    if(string == NULL){
        p_s no = malloc(sizeof(struct minha_string));
        no->elemento= elemento;
        no->proximo = NULL;
        return no;
    }
    else{
        string->proximo = add_s(string->proximo,elemento);
        return string;
    }
}
print_s(p_s string){
    p_s aux = string;
    while(aux!=NULL){
        printf("%c",aux->elemento);
        aux= aux->proximo;
    }
}
pointer_no add(p_s pre_ord,p_s em_ord){
    if(em_ord == NULL || pre_ord == NULL){
        return NULL;
    }
    else{
        pointer_no arvore  = malloc(sizeof(struct no_arvore));
        arvore->elemento = pre_ord->elemento;
        p_s aux = em_ord;
        p_s em_ord_esquerda = NULL;
        p_s em_ord_direita = NULL;
        p_s pre_ord_esquerda = NULL;
        p_s pre_ord_direita = NULL;
        while(aux != NULL){
            if(aux->elemento == pre_ord->elemento)
                break;
            em_ord_esquerda= add_s(em_ord_esquerda,aux->elemento);
            aux = aux->proximo;
        }
        aux = aux->proximo;
        while(aux!=NULL){
            em_ord_direita = add_s(em_ord_direita,aux->elemento);
            aux =aux->proximo;
        }
        aux = pre_ord;
        while(aux!=NULL){
            p_s aux2 = em_ord_esquerda;
            while(aux2!=NULL){
                if(aux2->elemento == aux->elemento)
                    pre_ord_esquerda = add_s(pre_ord_esquerda,aux2->elemento);
                aux2 = aux2->proximo;
            }
            aux = aux->proximo;
        }


        aux = pre_ord;
        while(aux!=NULL){
            p_s aux2 = em_ord_direita;
            while(aux2!=NULL){
                if(aux2->elemento == aux->elemento)
                    pre_ord_direita = add_s(pre_ord_direita,aux2->elemento);
                aux2 = aux2->proximo;
            }
            aux = aux->proximo;
        }

        arvore->esquerda = add(pre_ord_esquerda,em_ord_esquerda);
        arvore->direita = add(pre_ord_direita,em_ord_direita);
        return arvore;
    }
}

void post_ord(pointer_no tree){
    if(tree == NULL)
        return ;
    else{
        post_ord(tree->esquerda);
        post_ord(tree->direita);
        printf("%c",tree->elemento);
    }
}
int main(){
    int casos_teste ;
    scanf("%d",&casos_teste);
    int iterador=0;
    pointer_no arvores[casos_teste];


    for(iterador = 0;iterador<casos_teste;iterador++){
       // arvores[iterador]=NULL;
        p_s pre = NULL;
        p_s em = NULL;
        int tamanho;
        scanf("%d",&tamanho);
        int iterador2;
        for(iterador2 = 0;iterador2<2;iterador2++){
            char string[50];
            scanf("%s",string);
            int iterador3;
            for(iterador3=0;iterador3<tamanho;iterador3++){
                if(iterador2 == 0)
                    pre = add_s(pre,string[iterador3]);
                else
                    em = add_s(em,string[iterador3]);

        }

        }


        arvores[iterador]=add(pre,em);

    }



    for(iterador = 0;iterador<casos_teste;iterador++){

        post_ord(arvores[iterador]);
        printf("\n");

    }




return 0;

}
