// CROSSOVER PART
/*
     Chéo hóa gene với xác suất cao probability_crossover (pc) ta sẽ làm như sau:
     1. Chọn một pc là một số  trong khoảng 95 - 100 (constance in constance.h)
     2. Random một số  X trong khoảng tử 0-100, nếu X <= pc thì ta sẽ thực hiện chéo hóa
     3. Trả về  off_springs nếu chéo hóa, nếu không chéo hóa trả về lại 2 parents.
     Chú ý: 2 parents này là bản sao của 2 cá thể trong quần thể nên ta có thể biến hai parents này
     thành 2 off-spings luôn mà quần thể vẫn không đổi.
*/

#include "time.h"

void crossover_one_point(individual* citizen,int *Counter,individual *parent1, individual *parent2) {
  srand(time(NULL));
  int random_num = rand()%100;
  int i;
  if (random_num <= _PROBABILITY_CROSSOEVR_) {
    printf("Crossover...\n");
    random_num =  1 + rand()%(_GENE_LENGTH_ - 3);
    for ( i = 0; i <= random_num; i++) {
      int tmp = parent1->genes[i];
      parent1->genes[i] = parent2->genes[i];
      parent2->genes[i] = tmp;
    }
    printf("Finished Crossover Process...\n");
  }
  //Age Increasement
  for ( i = 0; i < _POP_; i++) {
    citizen[i].age += 1;
  }
  (*Counter) += 1;
}
//.....................................................................
//.....................................................................
//.....................................................................
// MUTATION PART
/*
      Dị hóa (Mutation) với xác suất thấp probability_mutation (pm) ta sẽ làm như sau:
      1. Chọn một pm là một số  trong khoảng 95 - 100 (constance in constance.h)
      2. Random một số  X trong khoảng tử 0-100, nếu X <= pm thì ta sẽ thực hiện dị hóa
      3. Trả lại off-spings sau khi dị hóa.

*/
void flipbit(int *allel) {
  if(*allel == 1) *allel = 0;
  else *allel = 1;
}

 void mutation_bit_flip(individual *parent1, individual *parent2) {
   srand(time(NULL));
   int random_num = rand()%100;
   if (random_num <= _PROBABILITY_MUTATION_) {
     printf("Mutating offspring 1...\n");
     int gene_mutate = rand()%_GENE_LENGTH_;
     flipbit(&(parent1->genes[gene_mutate]));
     printf("Done\n" );
   }
   random_num = rand()%100;
   if (random_num <= _PROBABILITY_MUTATION_) {
     printf("Mutating offspring 2...\n");
     int gene_mutate = rand()%_GENE_LENGTH_;
     flipbit(&(parent2->genes[gene_mutate]));
     printf("Done\n" );
   }
 }
