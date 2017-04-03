/*
 Author: Isaac Secundino
 Problem:
   ID: 6555
   Name: Play Fair Encryption
   Regional:
   Year:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef char* String;

typedef struct coord{
  int row;
  int col;
}Coord;

const String alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
int gridTrack[26][2];

String getTextFormated(){
  String text = (String) malloc(1000000);
  text[0]='\0';
  char *input = (char*) malloc(2);

  while(1){
    scanf("%c",input);
    if (input[0]=='\n')break;
    input[1] = '\0';

    if(isalpha(*input)){
      *input = toupper(*input);
      strcat(text,input);
    }
  }

  String newtext = (String) malloc(strlen(text)+1);
  strcpy(newtext,text);
  return newtext;
}

String removeDuplications(String key){
  int keylen = strlen(key);
  String cpyKey = (String) malloc(keylen+1);
  strcpy(cpyKey,key);

  for (int i=0; i<keylen; i++) {
    char ch = key[i];
    if(isalpha(ch)){
      char *dup = strchr(cpyKey,ch);
      if(dup == NULL) continue;
      if(*(dup+1) == '\0')break;

      while (dup != NULL) {
        if(*(++dup) == '\0')break;
        dup = strchr(dup,ch);
        if(dup != NULL) *dup = '-';
      }
    }
  }

  //printf("DEL:[%s]\n",cpyKey);

  int count = 0;
  String cleanKey = (String)malloc(strlen(cpyKey)+1);
  for (int i=0; i<keylen; i++) {
    if(cpyKey[i] != '-'){
      cleanKey[count] = cpyKey[i];
      count++;
    }
  }
  cleanKey[count]='\0';

  //printf("CLS:[%s]\n",cleanKey);
  return cleanKey;
}

String complementPlaiText(String plainText){
  int textLen = strlen(plainText);
  String newtext = (String) malloc(textLen*3+1);
  newtext[0] = '\0';
  int alp_i = 0;

  for (int i=0; i<textLen; i=i+2) {
    char *a = &plainText[i];
    char *b = &plainText[i+1];
    String temp = (String)malloc(3);

    if(*a == *b){
      i--;
      char replace = alphabet[(alp_i++)%25];
      if(replace == *a) replace = alphabet[(alp_i++)%25];
      temp[0] = *a;
      temp[1] = replace;
      temp[3] = '\0';
    }else{
      temp[0] = *a;
      if(*b=='\0'){
        temp[1] = alphabet[(alp_i++)%25];
        if(temp[1] == temp[0])temp[1] = alphabet[(alp_i++)%25];
      }else{
        temp[1] = *b;
      }
      temp[2] = '\0';
    }
    strcat(newtext,temp);
  }

  //printf("COMP:[%s]\n",newtext);

  return newtext;
}

char **getGrid(String key){
  String cpyAlpha = (String) malloc(strlen(alphabet)+1);
  strcpy(cpyAlpha,alphabet);
  int keyLen = strlen(key);

  char **grid = (char**)malloc(5 * sizeof(char*));
  for (int i=0; i<5; i++) {
    grid[i] = (char*) malloc(5 * sizeof(char));
  }

  //Populate with key
  //printf("GRID:");
  int index;
  for (index=0; index<keyLen; index++) {
    int row = index/5;
    int col = index-row*5;
    char *del = strchr(cpyAlpha,key[index]);
    *del = '-';
    grid[row][col] = key[index];
    gridTrack[key[index]-65][0] = row;
    gridTrack[key[index]-65][1] = col;
    //printf("%c",grid[row][col]);
  }

  //Populate with alphabet
  //printf("[%s]",cpyAlpha);
  for (int i=0; i<25; i++) {
    int row = index/5;
    int col = index-row*5;
    if(cpyAlpha[i] != '-'){
      grid[row][col] = cpyAlpha[i];
      gridTrack[cpyAlpha[i]-65][0] = row;
      gridTrack[cpyAlpha[i]-65][1] = col;
      //printf("%c",grid[row][col]);
      index++;
    }
  }
  //printf("\n");

  /*
  printf("GRID:");
  for (int i = 0; i < 5; i++) {
    if(i>0)printf("     ");
    for (int j = 0; j < 5; j++) {
      printf("%c",grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  */

  return grid;
}

Coord *getCoord(char **grid, char ch){
  Coord *coord = (Coord*) malloc(sizeof(Coord));
  int track = ch-65;
  coord->row = gridTrack[track][0];
  coord->col = gridTrack[track][1];

  /*
  for (int i=0; i<25; i++) {
    int row = i/5;
    int col = i-row*5;
    //printf("[%c %c]\n",grid[row][col],ch);
    if(grid[row][col] == ch){
      coord->row = row;
      coord->col = col;
      return coord;
    }
  }
  */
  //printf("ERROR\n");
  //coord->row = 0;
  //coord->col = 0;
  return coord;
}

String getEncryption(String plainText, char **grid){
  int textLen = strlen(plainText);
  String cipherText = (String) malloc(textLen*3);
  cipherText[0] = '\0';

  for (int i=0; i<textLen; i+=2) {
    char *a = &plainText[i];
    char *b = &plainText[i+1];
    String temp = (String)malloc(3);
    Coord *coordA = getCoord(grid,*a);
    Coord *coordB = getCoord(grid,*b);
    //printf("[%c %c]\n",*a,*b);
    if(coordA->row != coordB->row && coordA->col != coordB->col){
      temp[0] = grid[coordA->row][coordB->col];
      temp[1] = grid[coordB->row][coordA->col];
    }else if(coordA->row == coordB->row){
      temp[0] = grid[coordA->row][(coordA->col+1)%5];
      temp[1] = grid[coordB->row][(coordB->col+1)%5];
    }else{
      temp[0] = grid[(coordA->row+1)%5][coordA->col];
      temp[1] = grid[(coordB->row+1)%5][coordB->col];
    }
    temp[2] = '\0';
    strcat(cipherText,temp);
  }

  return cipherText;
}

int main() {

  int n;
  scanf("%d\n",&n);

  for (int i = 1; i <= n; i++) {
    String key = getTextFormated();
    String plainText = getTextFormated();
    String cipherText;
    key = removeDuplications(key);
    plainText = complementPlaiText(plainText);
    char **grid = getGrid(key);
    cipherText = getEncryption(plainText,grid);
    printf("Case %d: %s\n",i,cipherText);
  }

  return (0);
}
