#include "NotGAFunction/subfuction.h"
// Age based survival Selection
void Age_Based_SS(individual *citizen) {

}
// Fitness Based survival Selection
/*
      HÀm này dùng để tìm ra 2 cá thể có chỉ số fitness thấp nhất trong quần thể  và thay thế chúng
      bằng 2 off-spings đã có ở trên.
*/
void Fitness_Based_SS(individual *citizen, individual *parent1, individual *parent2) {
  int i, min1_locate = 0, min2_locate = 0;
  int min = citizen[0].fitness;
  for ( i = 1; i < _POP_; i++) {
    if (min > citizen[i].fitness) {
      min = citizen[i].fitness;
      min1_locate = i;
    }
  }
  int t;
  if(min1_locate == 0) {
    t = 1;
    min = citizen[1].fitness;
  }
  else {
    t = 0;
    min = citizen[0].fitness;
  }
  for (; t < _POP_; t++) {
    if (min > citizen[t].fitness && t != min1_locate) {
      min = citizen[t].fitness;
      min2_locate = t;
    }
  }

  individual_swap(&citizen[min1_locate],parent1);
  individual_swap(&citizen[min2_locate],parent2);
}
//...................................................
//...................................................
// Hàm tìm best trong quần thể
void find_best(individual* citizen, individual* best){
  int max = citizen[0].fitness;
  int max_locate = 0;
  int i;
  for ( i = 1; i < _POP_; i++) {
    if(max < citizen[i].fitness) {
        max_locate = i;
        max = citizen[i].fitness;
    }
  }

  printf("Best located : %d\n",max_locate);
  printf("Best value : %d\n",max);

  best->fitness = citizen[max_locate].fitness;
  best->age = citizen[max_locate].age;
  best->weigh = citizen[max_locate].weigh;
    for (int j = 0; j < _GENE_LENGTH_; ++j) {
        best->genes[j] = citizen[max_locate].genes[j];
    }
}
// In ra best
void print_best(individual best){
    printf("...................................\n");
    printf("This is the best individual found\n");
    for (int i = 0; i < _GENE_LENGTH_; ++i) {
        printf("%d",best.genes[i]);
    }
    printf("\nFITNESS: %d\n",best.fitness);
    printf("WEIGH: %d\n",best.weigh);
    printf("...................................\n");
}
