#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int cases;
    scanf("%d\n",&cases);

    for(int i=0;i<cases;i++){
        double total = 0;
        int s;
        scanf("%d\n",&s);
        int j=0;

        while(total<s){
            j++;
            total+= 1/(sqrt((double)j)+sqrt((double)j+1));
        }
        printf("%d\n",j);
    }
}
