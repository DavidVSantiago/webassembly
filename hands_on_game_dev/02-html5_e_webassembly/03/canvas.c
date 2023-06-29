#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>
#include <time.h>

int shipX=0;
int shipY=0;
int shipWidth=100;
int shipHeight=59;
int shipVelX=2;
int shipVelY=2;
int LARGURA_TELA = 800;
int ALTURA_TELA = 600;

   // Initialization, should only be called once.   

void checkCollisions(){
    if(shipX+shipWidth>=LARGURA_TELA || shipX<0){
        shipVelX*=-1;
        srand(time(NULL));
        int newVel = ((rand()%3)+2); // -1 a -3
        printf("NewVel=%d\n",newVel);
        printf("ShipVelX=%d\n",shipVelX);
        if(shipVelX<0) newVel*=-1;
        shipVelX = newVel;
    }
    if(shipY+shipHeight>=ALTURA_TELA || shipY<0){
        shipVelY*=-1;
        srand(time(NULL));
        int newVel = ((rand()%3)+2); // -1 a -3
        printf("NewVel=%d\n",newVel);
        printf("ShipVelY=%d\n",shipVelY);
        if(shipVelY<0) newVel*=-1;
        shipVelY = newVel;
    }
}

void moveShip(){
    shipX+=shipVelX;
    shipY+=shipVelY;

    checkCollisions();

    EM_ASM(shipPosition($0, $1),shipX,shipY); // executa código js
}

int main(){
    printf("Iniciou Main()\n");
    emscripten_set_main_loop(moveShip,0,0);
    return 1;
}