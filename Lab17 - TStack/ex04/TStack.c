#include "TStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct TStack{
    int qtd;
    int max;
    char *data;
};

TStack *stack_create(int size){
    TStack *st;
    st = (TStack *)malloc(sizeof(struct TStack));
    if(st!=NULL){
        st->qtd=0;
        st->data = malloc(size*sizeof(struct TStack));
        if(st->data != NULL){
            st->max = size;
            return st;
        }
    }
}

int stack_free(TStack *st){
    if(st == NULL){return INVALID_NULL_POINTER;}
    free(st);
    return SUCCESS;
}

int stack_push(TStack *st, char c){
    if(st == NULL){return INVALID_NULL_POINTER;}
    if(st->qtd == st->max){return OUT_OF_RANGE;}
    st->data[st->qtd] = c;
    st->qtd++;
    return SUCCESS;
}

int stack_pop(TStack *st){
    if(st == NULL){return INVALID_NULL_POINTER;}
    if(st->qtd <= 0){return OUT_OF_RANGE;}
    st->qtd--;
    return SUCCESS;
}

int stack_top(TStack *st, char *c){
    if(st == NULL){return INVALID_NULL_POINTER;}
    if(st->qtd <= 0){return OUT_OF_RANGE;}
    *c = st->data[st->qtd-1];
    return SUCCESS;
}

int stack_empty(TStack *st){
    if(st == NULL){return INVALID_NULL_POINTER;}
    return (st->qtd == 0);
}

int stack_full(TStack *st){
    if(st == NULL){return INVALID_NULL_POINTER;}
    return (st->qtd == st->max);
}

/*int stack_print(TStack *st){
    if(st == NULL){return INVALID_NULL_POINTER;}
    if(st->qtd <= 0){return OUT_OF_RANGE;}
    for (int i = 0; i < st->qtd; i++)
    {
        printf("\n----------------------");
        printf("\nchar: %c", st->data[i]);
        
    }
    return SUCCESS;
}*/

int bemFormada(char *str){
    if(strlen(str) <= 1){return OUT_OF_RANGE;}
    int tam = strlen(str);
    char c;

    TStack *st;

    st = stack_create(tam);
    if(st==NULL){return INVALID_NULL_POINTER;}
    for(int i = 0;i<tam; i++){
        if(str[i]=='(' || str[i]=='['|| str[i]=='{'){
            stack_push(st, str[i]);
        }
        if(str[i]==')'){
            stack_top(st,&c);
            if(c !='(' || stack_empty(st)==1){
                return 1;
            }else{
                stack_pop(st);
            }
        }
        if(str[i] ==']'){
            stack_top(st,&c);
            if(c !='[' || stack_empty(st)==1){
                return 1;
            }else{
                stack_pop(st);
            }
        }
        if(str[i] =='}'){
            stack_top(st,&c);
            if(c !='{' || stack_empty(st)==1){
                return 1;
            }else{
                stack_pop(st);
            }
        }
    }
    tam = stack_empty(st);
    if(tam==0){return 1;}
    else{return SUCCESS;}
}