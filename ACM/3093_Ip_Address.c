/*
 Author: Isaac Secundino
 Problem:
   ID: 3093
   Name: IP Address
   Regional: Latin America - Mexico and Central America
   Year: 2004
*/

#include <stdio.h>
#include <stdlib.h>

int pow2[]={1,2,4,8,16,32,64,128};

void printAddress(char *string){
  int i;
  for (i=0; i<4; i++) {
    int octet = 0;
    int j;
    for (j=0; j<8; j++) {
      int value = (int)(string[i*8+j])-48;
      value = value*pow2[7-j];
      octet += value;
    }
    if(i==3){
      printf("%d\n",octet);
    }else{
      printf("%d.",octet);
    }
  }
}

int main(){
  int n;
  scanf("%d\n",&n);
  int i;
  
  for (i=0; i<n; i++) {
    char *bitAdd = (char*)malloc(33);
    scanf("%s\n",bitAdd);
    printAddress(bitAdd);
  }
  
  return (0);
}
