#include "time.h"
// Hàm tính khối lượng mỗi cá thể.
int weigh_calculate(individual person, struct Item* item){
    int Weigh = 0;
    for (int i = 0; i < _GENE_LENGTH_; ++i) {
        Weigh += person.genes[i]*item[i].weigh;
    }
    return Weigh;
}

/*
 * Hàm GA_fitness_calculation vừa tính fitness vừa có nhiểm vụ kiểm tra các cá
 * thể, cá thể nào có weigh > _CAPACITY_ thì sẽ được điều chỉnh gene.
 * Hiện tại hàm này đang có vấn đề về tính toán.
 */
void GA_fitness_calculation(individual*citizen,struct Item* item){

    // Fitness calculation
    for (int i = 0; i < _POP_; ++i) {
        citizen[i].weigh = 0;
        citizen[i].fitness = 0;
        for (int j = 0; j < _GENE_LENGTH_; ++j) {
            citizen[i].weigh += item[j].weigh*citizen[i].genes[j];
            citizen[i].fitness += item[j].value*citizen[i].genes[j];
        }
    }

}

void GA_genes_adjustment(individual*citizen,struct Item* item){
    // Gene Adjustment: If weigh > _CAPACITY_ then find theo genes[i] = 1 with lowest value and turn it into 0
    // Repeat until weigh < 30.
    for (int k = 0; k < _POP_; ++k) {
        int tmp = citizen[k].weigh;
        while(tmp > _CAPACITY_){ // Nếu nặng hơn cho phép
            // Tìm vị trí gene ứng với item có value bé nhất.
            // Tức là phối hợp tìm min với yêu cầu gene[i] == 1
            int min_locate = 0;
            int min = 1000;
            for (int i = 0; i < _GENE_LENGTH_; ++i) {
                if ( citizen[k].genes[i] == 1){
                    if(min > item[i].value){
                        min = item[i].value;
                        min_locate = i;
                    }
                }
            }
            // Thay đổi allele của vị trí này thành 0
            citizen[k].genes[min_locate] = 0;
            tmp = weigh_calculate(citizen[k],item);
        }
    }
}





void single_individual_fitness_calculate(individual *single_pup, struct Item* item) {
  int i;
  int value = 0;
  int weigh = 0;
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    if (weigh > _CAPACITY_) {
        break;
    }
    else {
      value += single_pup->genes[i]*item[i].value;
      weigh += item[i].weigh;
    }
  }
  single_pup->fitness = value;
}
