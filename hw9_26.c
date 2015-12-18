#include<stdio.h>
#include<stdlib.h>
void fifo(int str[], int length);
void p(int a[], int l);
int main(){
  srand(time(NULL));
  int str[15];
  int length = (rand()%7)+1;
  int i;
  for(i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
    str[i] = (rand() % 9);
    printf("%d ", str[i]);
  }
  printf("\n");
  printf("frames number: %d\n", length);
  fifo(str, length);
}

void fifo(int str[], int length){
  srand(time(NULL));
  int i, j;
  int count = 0;
  int qu = 0;
  int same = 0;
  int frames[length];
  int pft = 0;
  for(i = 0; i < 15; i++) {
    if(count == 0) {
      frames[count] = str[i];
      count++;
      pft++;
    }
    else if(count < length) {
      same = 0;
      for(j = 0; j < count; j++) {
        if(frames[j] == str[i]) same++;
      }
      if(same == 0) {
        frames[count] = str[i];
        count++;
        pft++;
      }
    }
    else {
      same = 0;
      for(j = 0; j < length; j++) {
        if(frames[j] == str[i]) same++;
      }
      if(same == 0) {
        frames[qu] = str[i];
        qu = (qu + 1) % length;
        pft++;
      }
    }
  }
  printf("FIFO page fault time: %d\n", pft);
}

void p(int a[], int l) {
  int i;
  for(i=0; i<l; i++) {
    printf("%d ", a[i]);
  }
  puts("");
}