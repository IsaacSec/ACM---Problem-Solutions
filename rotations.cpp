#include <stdio.h>
#include <stdlib.h>

int powtwo[5] = {1,2,4,8,16};

int * bit_array(unsigned int *pows, unsigned int n){
    unsigned int acc = 0;
    int *bitarray = (int*)malloc(sizeof(int)*32);

    for(int i=0; i<32; i++){
        int bit = n/pows[31-i];
        n = n - bit * pows[31-i];
        bitarray[i]=bit;
    }

    return bitarray;
}

int unsigned *memopow(){
    unsigned int *pows = (unsigned int*)malloc(sizeof(int)*32);
    pows[0]=1;
    for(int i=1; i<32; i++){
        pows[i] = pows[i-1]*2;
    }
    return pows;
}

int n_from_range(int *bits, int low, int high){
    int number = 0;
    for(int i=low; i<high; i++){
        int index= i%32;
        int pow = bits[index]*powtwo[i-low];
        number += pow;
    }
    return number;
}

int check(int *patterns, int n){
    if(patterns[n]==0){
        patterns[n] = 1;
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int cases;
    unsigned int *pows = memopow();

    scanf("%d\n",&cases);
    for(int i=0;i<cases;i++){
        int n;
        int patterns[32] = {0};
        scanf("%d\n",&n);
        int *bits = bit_array(pows,n);

        for(int j=0; j<32; j++){
            int checker = n_from_range(bits,j,j+5);
            check(patterns,checker);
        }

        int acc = 0;
        for(int j=0; j<32; j++){
            //printf("%d",patterns[j]);
            if(patterns[j] == 1){
                acc++;

            }
        }

        if(acc == 32){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
