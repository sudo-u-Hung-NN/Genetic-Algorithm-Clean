#include "time.h"

struct Item {
  //char name[20];
  int weigh;
  int value;
};

void print_problem(struct Item* item) {
  int i;
  printf("%-6s : ","Item");
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    printf("%4d",i);
  }
  printf("\n%-6s : ","Weigh");
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    printf("%4d", item[i].weigh);
  }
  printf("\n%-6s : ","Value");
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    printf("%4d", item[i].value);
  }
  printf("\n");
}
/*
Item:             1   2   3   4   5   6   7   8   9   10
Khối lượng:       5   3   1   4   7   6   9   2   3   8
Giá trị:          6   4   3   6   8   4   7   3   5   8
Để tiết kiệm thời gian ta sẽ randomize 
*/
void problem_in(struct Item* item) {
  int i;
  //printf("Weigh/Value intake...\n");
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    //printf("Item[%d]: ", i);
    //scanf("%d%d", &item[i].weigh, &item[i].value);
    item[i].weigh = 2 + rand()%6;
    item[i].value =  1 + rand()%8;
  }
  print_problem(item);
}
