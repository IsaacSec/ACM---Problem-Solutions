#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,T;
  while (scanf("%d %d\n",&n,&T)==2) {
    int i;
    int timeRecorded = 0;
    int tasksDone = 0;

    for (i=0; i<n; i++) {
      int task=0;
      scanf("%d",&task);

      timeRecorded = timeRecorded + task;
      if (timeRecorded>T) {
      }else{
        tasksDone++;
      }
    }
    printf("%d\n",tasksDone);
  }
  return 0;
}
