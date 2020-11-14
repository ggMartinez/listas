#include<stdio.h>
#include<stdlib.h>

typedef struct nodoL {
	char caracter;
    nodoL *siguiente;
} Nodo;

typedef Nodo *Lista;

Lista lista;


void CrearLista(Lista &lis){
	lis = NULL;
}

bool ListaEstaVacia(Lista lis){
	if(lis == NULL)
		return true;
	else
		return false;
}
void BorrarPrimero(Lista &lis){
    Lista aux = lis;
    printf("Eliminando nodo %c\n",aux -> caracter);
    lis = lis -> siguiente;
    free(aux);

}



void InsertarAlFrente(Lista &lis, char c){
    Lista aux = (Nodo*) malloc(sizeof(Nodo));
    aux -> caracter = c;
    aux -> siguiente = lis;
    lis = aux;
}


void CargarLista(Lista &lis){
    char CaracterAInsertar;
    bool terminado = false;

    while(terminado == false){
        printf("Ingrese un caracter (o ingrese 0 para terminar): ");
        fflush(stdin);
        scanf("%c",&CaracterAInsertar);

        if(CaracterAInsertar != '0'){
            InsertarAlFrente(lista,CaracterAInsertar);
        }
        else{
            terminado = true;
        }
    }

}

void BorrarLista(Lista &lis){
    while(ListaEstaVacia(lis) == false){
        BorrarPrimero(lis);
    }

}

void ListarLista(Lista &lis){
    Lista temporal = lis;

    printf("La lista tiene: \n");

    while(temporal != NULL){
        printf("%c \n",temporal -> caracter);
        temporal = temporal -> siguiente;
    }

}


void ReemplazarCaracteres(Lista &lis){
	char CaracterAInsertar,CaracterAReemplazar;
    Lista temporal;

    printf("Ingrese el caracter a insertar: ");
    fflush(stdin);
    scanf("%c",&CaracterAInsertar);

    printf("Ingrese el caracter a reemplazar: ");
    fflush(stdin);
    scanf("%c",&CaracterAReemplazar);


    temporal = lis;

    while(temporal != NULL){
        if(temporal -> caracter == CaracterAReemplazar){
                temporal -> caracter = CaracterAInsertar;
        }
        temporal = temporal -> siguiente;
    }



}

int main(){

	CrearLista(lista);
    CargarLista(lista);

    ListarLista(lista);

    ReemplazarCaracteres(lista);
    ListarLista(lista);

    BorrarLista(lista);

}
