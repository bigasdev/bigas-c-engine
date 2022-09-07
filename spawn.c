#include "src/structs.h"
#include "src/spawn.h"
#include "src/draw.h"
#include <stdio.h>
#include <stdlib.h>

Entity *fila = NULL;
Entity baseEntity;
int increase = 32;

void addEntity(Entity **spawn){
    printf("Adding a new entity with a x: %i\n", increase);
    Entity *aux, *entity = malloc(sizeof(Entity));
    if(entity){
        entity->x = baseEntity.x + increase;
        entity->y = baseEntity.y;
        entity->moveSpeed = baseEntity.moveSpeed;
        entity->health = baseEntity.health;
        entity->texture = baseEntity.texture;
        entity->next = NULL;
        
        // Caso a fila esteja NULL a gente vai iniciar ela com a entity criada como objeto
        if(*spawn == NULL){
          *spawn = entity;  
        }else{
            // Caso contrario a gente vai utilizar como auxiliar o objeto que estava armazenado no next;
            aux = *spawn;
            while(aux->next){
                printf("\n Another test!");
                aux = aux->next;
                // A gente vai entao pegar o next do auxiliar e assignar com a entity que criamos
            }
            aux->next = entity;
        }
        
    
    }else{
        // Caso nao seja possivel criar o entity a gente printa um erro de alolcacao de memoria
        printf("Erro de alocacao de memoria");
    }
}

void readEntities(Entity **spawn){
    Entity *aux, *entity = NULL;
    if(*spawn){
        aux = *spawn;
        //printf("\n Entity na posicao X: %d e posicao Y: %d", aux->x, aux->y);
        blit(aux->texture, aux->x, aux->y, 0);
        entity = aux->next;
        readEntities(&entity);
    }
}

Entity* removeEntity(Entity **spawn){
    Entity *remover = NULL;
    if(*spawn){
        //Se nao estiver null a gente vai remover o next
        remover = *spawn;
        *spawn = remover->next;
    }else{
        printf("Fila vazia!");
    }
    return remover;
}

void add(){
    addEntity(&fila);
}

void initSpawn(){
    baseEntity.x = 400;
    baseEntity.y = 200;
    baseEntity.moveSpeed = 2;
    baseEntity.health = 10;
    baseEntity.texture = loadTexture("resources/sprites/items.png");
    for (size_t i = 0; i < 10; i++)
    {
        /* code */  
        add();
        increase += 16;
    }
    
}

void readSpawn(){
    readEntities(&fila);
}
