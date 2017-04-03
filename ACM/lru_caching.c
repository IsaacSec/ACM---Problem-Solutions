/*
ID: 6099
Name: LRU Caching
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cache Cache;

struct cache{
  int size;
  int timeElapsed;
  char *dataSet;
};

void printCache(Cache cache){
  int i;
  for (i = 0; i < cache.size; i++) {
    char data = cache.dataSet[i];
    if(data!=(char)0)printf("%c",data);
  }
  printf("\n");
}

void insertDataInCache(Cache *cache, char data){
  int i,j;
  int size = cache->size;
  int repetitionPos = -1;

  for (j = 0; j<size; j++) {
    char a = cache->dataSet[j];
    if(a==data){
      repetitionPos = j;
    }
  }

  if(repetitionPos > -1){
    i=repetitionPos;
  }else{
    i=0;
  }

  for (; i < size-1; i++) {
    char b = cache->dataSet[i+1];
    cache->dataSet[i] = b;
  }
  cache->dataSet[size-1] = data;
}

void evaluateDataSet(int cacheSize){
  Cache cache;
  cache.size = cacheSize;
  cache.dataSet = (char*)malloc(cacheSize);

  while (1) {
    char letter;
    scanf("%c",&letter);
    if(letter == '\n')break;

    if(letter == '!'){
      printCache(cache);
    }else{
      insertDataInCache(&cache, letter);
    }
  }
}

int main() {
  int simulationNumber = 1;

  while(1){
    int cacheSize;
    scanf("%d ",&cacheSize);
    if (cacheSize==0)break;

    printf("Simulation %d\n",simulationNumber);
    evaluateDataSet(cacheSize);
    simulationNumber++;
  }

  return (0);
}
