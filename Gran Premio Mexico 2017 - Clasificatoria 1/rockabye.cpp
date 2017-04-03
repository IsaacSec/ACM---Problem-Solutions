#include <stdio.h>
#include <stdlib.h>

int main(){

    char name [100];
    int cases = 0;
    scanf("%d",&cases);

    for(int i=0; i<cases; i++){
        int numMed, totalMeds;
        scanf("%d %d",&numMed,&totalMeds);
        char **medicine = (char**)malloc(sizeof(char*)*numMed);
        int freqAr [numMed];
        for(int j = 0 ; j< numMed; j++){
            medicine[j] = (char*)malloc(sizeof(char)*50);
        }
        for(int j = 0 ; j< numMed;j++){
            scanf("%s %d",medicine[j],&freqAr[j]);
            //printf("TEST: %s %d\n",medicine[j], freqAr[j]);
        }
        int medCounter=0;
        for(int j = 1 ; j>-1; j++){

            for(int x=0; x< numMed; x++){
                if( (j%freqAr[x]) == 0){
                    printf("%d %s\n",j,medicine[x]);
                    medCounter++;
                }
            }

            if(medCounter==totalMeds){
                break;
            }
        }


    }

}
