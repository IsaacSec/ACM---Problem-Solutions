/*
 Author: Isaac Secundino
 Problem:
   ID: 6949
   Name: Knockout Racing
   Regional: Europe - Northeastern
   Year: 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct car{
  int min;
  int max;
  int len;
}Car;

int getPos(Car car, int timep){
  int eval = timep/car.len;
  int diff = timep % car.len;
  int pos = 0;

  if(eval & 0x00000001){ // Odd
    pos = car.max-diff;
  }else{  // Even
    pos = car.min+diff;
  }

  return pos;
}

int main() {
  int n,m;
  while((scanf("%d %d\n",&n,&m)) == 2){
    Car *cars = (Car*)malloc(n * sizeof(Car));
    for (size_t i = 0; i < n; i++) {
      Car *car = cars+i;
      scanf("%d %d\n",&car->min,&car->max);
      car->len = car->max - car->min;
    }

    for (size_t i = 0; i < m; i++) {
      int x,y,t,result=0;
      scanf("%d %d %d\n",&x,&y,&t);
     
      for (size_t j = 0; j < n; j++) {
        if(cars[j].max<x || cars[j].min>y){
          continue;
        }
       
        int pos = getPos(cars[j],t);
        if(pos>=x && pos<=y){
          result++;
        }
      }
      printf("%d\n",result);
    }
  }
  return (0);
}
