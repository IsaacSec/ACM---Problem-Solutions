#include <stdio.h>
#include <stdlib.h>

int main(){
    int cases;
    scanf("%d\n",&cases);

    for(int j=0;j<cases;j++){
        int acc = 0;
        int n;
        scanf("%d\n",&n);
        for(int i=1; i<n; i++){
            if(n%i==0){
                acc+=i;
            }
        }

        if(acc<n){
            printf("deficient\n");
        }else if(acc==n){
            printf("perfect\n");
        }else{
            printf("abundant\n");
        }
    }
    return 0;
}
