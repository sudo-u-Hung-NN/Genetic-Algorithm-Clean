/*
  Fitness Proportionate select_Roulette_wheelion
*/
#include "time.h"
int population_overall_point(individual *citizen){
    int S = 0;
    for (int i = 0; i < _POP_; ++i) {
        S += citizen[i].fitness;
    }
    return S;
}
//Roulette_wheel_locate
int Roulette_wheel_locate(individual* citizen, int random_ini, int Sum_all_fitnesses){
  int rank_fitness[_POP_];
  int i;
  for ( i = 0; i < _POP_; i++) {
    rank_fitness[i] = citizen[i].fitness;
  }
  for ( i = 0; i < _POP_; i++) {
    if(random_ini <= citizen[i].fitness) return i;
    else{
      random_ini = random_ini - citizen[i].fitness;
    }
  }
}

//***************************************
// print information of any individual, single individual only.
void print_any_individual(individual *citizen, individual a){
   // printf("Locaction: %ld\n",  &citizen[0] - &a);
    printf("Fitness: %d\n", a.fitness);
    printf("Weigh : %d\n",a.weigh);
    for (int i = 0; i < _GENE_LENGTH_; ++i) {
        printf("%d",a.genes[i]);
    }
    printf("\n");
}
//......................................

void PS_Roulette_wheel_selection_SUS(individual* citizen, individual* parent1, individual* parent2) {
  printf("Parent select_Roulette_wheeling...\n");
  int Sum_all_fitnesses = 0;
  int i = 0;
  for ( i = 0; i < _POP_; i++) {
    Sum_all_fitnesses += citizen[i].fitness;
  }
  srand(time(NULL));


  int parent1_location = rand()%Sum_all_fitnesses;

  printf("parent1_location = %d\n",parent1_location);
  printf("Number locate: %d\n",Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses));

  parent1->fitness = citizen[Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses)].fitness;
  parent1->age = citizen[Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses)].age;
  parent1->weigh = citizen[Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses)].weigh;
    for (int j = 0; j < _GENE_LENGTH_; ++j) {
        parent1->genes[j] = citizen[Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses)].genes[j];
    }


  int parent2_location = (Sum_all_fitnesses - parent1_location);
  int replace = Roulette_wheel_locate(citizen,parent2_location,Sum_all_fitnesses);
  // Kiểm tra nếu chỉ số vị trí của parent 1 và 2 trùng nhau thì ta lấy chỉ số của parent 2 += 1.
  if (Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses) == replace){
      replace = Roulette_wheel_locate(citizen,parent1_location,Sum_all_fitnesses) + 1;
  }

  printf("parent2_location = %d\n",parent2_location);
  printf("Number locate: %d\n",replace);

  parent2->fitness = citizen[replace].fitness;
  parent2->age = citizen[replace].age;
  parent2->weigh = citizen[replace].weigh;
    for (int k = 0; k < _GENE_LENGTH_; ++k) {
        parent2->genes[k] = citizen[replace].genes[k];
    }
  printf("Selection done...\n");
    printf(".....................................\n");
    printf("Parents' Information: \n");
    printf("Parent 1: \n");
  print_any_individual(citizen,*parent1);
  printf(("Parent 2: \n"));
  print_any_individual(citizen,*parent2);
  printf("....................................\n");
}
