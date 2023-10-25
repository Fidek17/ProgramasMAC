#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo{
    struct Nodo *izq;
    char info;
    struct Nodo *der;
};

void carga(struct Nodo **raiz);
void insercion(struct Nodo **elemento, int dato);
void buscar_elemento(struct Nodo **elemento, int dato);
void eliminar_elemento(struct Nodo **elemento, struct Nodo **raiz, int dato);
// struct Nodo *busqueda_nodo(struct Nodo **elemento, int dato);
struct Nodo *sucesor(struct Nodo **raiz, int dato);

int menu();

void preorden(struct Nodo **raiz);
void inorden(struct Nodo **raiz);
void posorden(struct Nodo **raiz); 
bool arbol_vacio(struct Nodo **raiz);
void mensaje_arbol_vacio();

int main(){
    struct Nodo *raiz;
    struct Nodo *aux;
    int respuesta, dato;
    raiz =(struct Nodo *) malloc(sizeof(struct Nodo));
    raiz = NULL;


    do{
        respuesta = menu();
        
        switch(respuesta){
            case 1:
                printf("\n\n Indique el dato a insertar en el ABB: ");
                scanf("%d", &dato);
                    if(raiz == NULL){
                        raiz = (struct Nodo *) malloc(sizeof(struct Nodo));
                        raiz->info = dato;
                        raiz->izq = NULL;
                        raiz->der = NULL;
                    }else{
                        insercion(&raiz, dato); 
                    }
            break;

            case 2:
                printf("\n\n Indique el dato a BUSCAR en el ABB: ");
                scanf("%d", &dato);
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : buscar_elemento(&raiz, dato);
            break;

            case 3:
                printf("\n\n Indique el dato a BORRAR en el ABB: ");
                scanf("%d", &dato);
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : eliminar_elemento(&raiz, &raiz, dato);

            break;

            case 4:
                printf("3. Impresión del árbol en distintos ordenes\n\n");
                if (arbol_vacio(&raiz)){
                    mensaje_arbol_vacio();
                }else{
                    printf("\n\n");
                    preorden(&raiz);
                    printf("\n\n\n");
                    inorden(&raiz);
                    
                    printf("\n\n Indique el dato a buscar en el ABB: ");
                    scanf("%d", &dato);
                    aux->info = dato;
                    aux = sucesor(&(aux), dato);
                    
                    printf("\n\n\n");
                    posorden(&raiz);
                    printf("\n\n");
                }
            break;

            case 0:
                printf("Saliendo del programa\n\n");
            break;
            default:
                printf("Digite una opcion valida\n\n"); 
            break; 
        }
        
    }while(respuesta!=0);

    return 0;
}

int menu(){
    int res;
    printf("\n\n");
    printf("ALGORITMO QUE CARGA UN ARBOL BINARIO DE BÚSQUEDA\n\n");
    printf("1. Inserción de elementos en el Árbol Binario de Búsqueda\n\n");
    printf("2. Búsqueda de un elemento en el ABB \n\n");
    printf("3. Eliminación de un elemento en el ABB\n\n");
    printf("4. Impresiones en PreOrden, InOrden y PosOrden\n\n");
    printf("0. Salida\n\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}


/*
void carga(struct Nodo **raiz){
    struct Nodo *aux;
    int info;
    
    printf("\n\n Indique el dato a insertar en el ABB: ");
    scanf("%d", &info);
    
    if(*raiz == NULL){
        *raiz = (struct Nodo *) malloc(sizeof(struct Nodo));
        (*raiz)->info = info;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        insercion(raiz, info); 
    }
}
*/

void insercion(struct Nodo **elemento, int info){
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));

    if (info <= (*elemento)->info){
        
        if ((*elemento)->izq == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->izq = aux;
        
        }else{
            insercion(&((*elemento)->izq), info);
        }
           
    }else{

        if ((*elemento)->der == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->der = aux;
        
        }else{
            insercion(&((*elemento)->der), info);
        }
    }
}

void buscar_elemento(struct Nodo **elemento, int dato){
    // int dato;
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            buscar_elemento(&((*elemento)->izq), dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                buscar_elemento(&((*elemento)->der), dato);
            }
        }else{
            printf("\n El nodo SE encuentra en el árbol\n");
        }    
    }
}

/*
struct Nodo *busqueda_nodo(struct Nodo **elemento, int dato){
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            buscar_elemento((*elemento)->izq, dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                buscar_elemento((*elemento)->der, dato);
            }
        }else{
            // printf("\n El nodo SE encuentra en el árbol\n");
            return *elemento;
        }    
    }
}
*/


void eliminar_elemento(struct Nodo **elemento, struct Nodo **raiz, int dato){
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));

/*
    int dato;
    aux = busqueda_nodo(*elemento, dato);

    printf("Ingresa el dato a eliminar del ABB");
    scanf("%d", &dato);

    if (aux == NULL){
        printf("\n%p __ %d __ %p\n", aux->der, aux->info,  aux->izq);
    }
*/
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            aux = *elemento;
            eliminar_elemento(&((*elemento)->izq), &(*raiz), dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                aux = *elemento;
                eliminar_elemento(&((*elemento)->der), &(*raiz), dato);
            }
        }else{ // ELEMENTO ENCONTRADO
            printf("\n El nodo SE encuentra en el árbol\n");
            if (((*elemento)->izq || (*elemento)->der) && !((*elemento)->izq && (*elemento)->der)){ // SI TIENE UN SOLO HIJO
                // *elemento = (*elemento)->der;
                aux->der = (*elemento)->der;
                elemento = NULL;

                if (aux->der != NULL){
                    printf("\n Se borro correctamente\n");
                }
                else{
                    printf("\n ERROR???\n");
                    preorden(&(*raiz));
                }
            }
            
            // aux = *elemento;
            // return *elemento;
        }    
    }
}


void preorden(struct Nodo **raiz){
    if(*raiz != NULL){
        printf("\n\n Valor: %d", (*raiz)->info);
        preorden(&(*raiz)->izq);
        preorden(&(*raiz)->der);
    }
}

void inorden(struct Nodo **raiz){
    if(*raiz != NULL){
        inorden(&(*raiz)->izq);
        printf("\n\n Valor: %d", (*raiz)->info);
        inorden(&(*raiz)->der);
    }
}

struct Nodo *sucesor(struct Nodo **raiz, int dato){
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));

    if(*raiz != NULL){
        sucesor(&(*raiz)->izq, dato);
        printf("\n\n Valor: %d", (*raiz)->info);
        sucesor(&(*raiz)->der, dato);
        if ((*raiz)->info == dato ){

            // sucesor(&(*raiz), dato);
            printf("\n Sucesor de %d -- es %d", (*raiz)->info, (*raiz)->der->info);
            return aux;
        }
        else{

        }
    }
}

void posorden(struct Nodo **raiz){
    if(*raiz != NULL){
        posorden(&(*raiz)->izq);
        posorden(&(*raiz)->der);
        printf("\n\n Valor: %d", (*raiz)->info);
    }
}

bool arbol_vacio(struct Nodo **raiz){
    if (*raiz != NULL){
        return false;
    }
    return true;
}
void mensaje_arbol_vacio(){
    printf("\n-----------------------------------\n");
    printf("\nEl árbol no tiene elementos\n\nInserte al ABB con la opción 1\n");
    printf("\n-----------------------------------\n");
}