#include <stdio.h>
int a,b; 
void penjumlahan(int p1[],int p2[]);

main(){ 
    int P1[11]={15,0,0,1,0,5,0,8,6,0,0}; 
    int P2[11]={10,0,2,2,3,0,0,4,0,3,0}; 
    int P3[11]={5,0,1,0,0,0,0,0,0,0,0}; 
    int bil[12]={0,0,0,0,0,0,0,0,0,0,0,0}; 

    printf("Diketahui :\n");
    printf("P1 = 6x8 + 8x7 + 5x5 + x3 + 15\n");
    printf("P2 = 3x9 + 4x7 + 3x4 + 2x3 + 10\n");
    printf("P3 = X2 + 5\n");

    penjumlahan(P1,P2);

}

void penjumlahan(int p1[], int p2[]){
    int bil[12]={0,0,0,0,0,0,0,0,0,0,0,0}; 

    for(int a=0;a < 10; a++){
    //    bil[a] = p1[a] + p2[a];
        bil[a] = *(p1+a) + *(p2+a);
    }

    printf("Penjumlahan : \n");

    for(int a=11; a>=0;a--){
        if(bil[a]==0){
            printf("");
        }else{
            if(a>1)
                printf("%dx%d + ",bil[a],a);
            else if(a==1)
                printf("%dx + ",bil[a]);
            else if(a>=0)
                printf("%d",bil[a]);

        }
    }



}