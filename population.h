#include "time.h"
#include "constance.h"

typedef struct individual individual;
struct individual {
    int genes[_GENE_LENGTH_];
    int age;
    int fitness;
    int weigh;
};

//...............................................................
//...............................................................
// Binary encoded Initialization
void GA_population_BinaryIni(individual* citizen, int population){
  srand(time(NULL));
  //genes creation.
  int i,j;
  for (i = 0; i < population; i++) {
    // age initialization.
    citizen[i].age = 0;
    for (j = 0; j < _GENE_LENGTH_; j++) {
        // binary representation
        citizen[i].genes[j] = rand() % 2;
    }
  }
}
//in kiểm quần thể khởi tạo ban đầu.
void print_Population (individual* citizen){
    for (int i = 0; i < _POP_; ++i) {
        printf("Citizen[%d]: ",i);
        for (int j = 0; j < _GENE_LENGTH_; ++j) {
            printf("%d",citizen[i].genes[j]);
        }
        printf("\n");
        printf("Fitness : %d\n",citizen[i].fitness);
        printf("Weigh : %d\n",citizen[i].weigh);
    }

}
