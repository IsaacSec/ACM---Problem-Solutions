/*
 Author: Isaac Secundino
 Problem:
   ID: 6499
   Name: Sort Me
   Regional: North America - Mid-Central USA
   Year: 2013
*/

#include <stdio.h>
#include <stdlib.h>
#define ML 31

void populate(char **strings, int size){
  int i;
  for (i=0; i<size; i++) {
    strings[i] = (char*)malloc(ML);
    scanf("%s\n",strings[i]);
  }
}

void printStrings(char **strings, int size){
  int i;
  for (i=0; i<size; i++) {
    printf("%s\n",strings[i]);
  }
}

int alphaValue(char *alph, char ch){
  int value = 0;
  if(ch=='\0'){
    return -1;
  }
  int i;
  for (i=0; i<ML; i++) {
    if(alph[i]==ch) value = i;
  }
  return value;
}

void orderByAlphabet(char *a, char **strs, int n){
  int changes = 1;
  int cycles = 0;

  while (changes !=0 && n>0) {
    changes = 0;
    cycles++;
    int i;
    for (i=0; i<n-1; i++){
      int j;
      for (j=0; j<ML; j++) {
        char ca = strs[i][j];
        char cb = strs[i+1][j];
        if(ca=='\0' && cb=='\0')break;
        int va = alphaValue(a, ca);
        int vb = alphaValue(a, cb);
        if(va != vb){
          if(va > vb){
            char *tempa = strs[i];
            strs[i] = strs[i+1];
            strs[i+1] = tempa;
            changes++;
          }
          break;
        }
      }
    }
  }

}

int main() {
  int year = 1;
  
  while (1) {
    int n;
    char alphabet[ML];
    scanf("%d ",&n);
    if (n==0)break;
    
    scanf("%s\n",alphabet);
    char *strings[n];
    populate(strings, n);
    orderByAlphabet(alphabet, strings, n);
    printf("year %d\n",year);
    printStrings(strings, n);
    year++;
  }
  return(0);
}

