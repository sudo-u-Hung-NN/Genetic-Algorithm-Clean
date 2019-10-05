/*
Đây là giải thuật Genetic Algorithm áp dụng cho bài toán xếp ba lô như sau:
Có một ba lô với giới hạn là 30kg.
Có một danh sách các loại sau có thể đút vào ba lô mỗi loại chỉ 1 thứ:
Item:             1   2   3   4   5   6   7   8   9   10
Khối lượng:       5   3   1   4   7   6   9   2   3   8
Giá trị:          6   4   3   6   8   4   7   3   5   8
*/
// Ở đây khai báo các thư viện chuẩn
#include "stdio.h"
#include "stdlib.h"

// Ở đây khai báo các thư viện tự tạo, sau khi viết thư viện phải lập tức include vào cuối danh sách.
#include "population.h"
#include "problem.h"
#include "fitness.h"
#include "genetic_operator.h"
#include "selection.h"
#include "constance.h"
#include "survivalSelection.h"
#include "termination.h"
//.....................................................
//.....................................................

int main(int argc, char const *argv[]) {

    struct Item item[_GENE_LENGTH_];
    problem_in(item);

    int Counter = 0; // for termination criteria.
    int Pre_fit, Now_fit;

    individual citizen[_POP_];
    GA_population_BinaryIni(citizen,_POP_);
    individual parent1, parent2; // also off_spings.
    individual best;
    GA_fitness_calculation(citizen,item);
    GA_genes_adjustment(citizen,item);
    GA_fitness_calculation(citizen,item);
    print_Population(citizen);

    find_best(citizen,&best);
    print_best(best);


    int generation_count = 0;

    while (Counter < _TIME_TO_CHANGE_ ) {
        Pre_fit = Sumfitness(citizen);
        PS_Roulette_wheel_selection_SUS(citizen, &parent1, &parent2); // select 2 parents.
        crossover_one_point(citizen,&Counter,&parent1,&parent2);// produce off_springs
        mutation_bit_flip(&parent1,&parent2);
        single_individual_fitness_calculate(&parent1,item);
        single_individual_fitness_calculate(&parent2,item);
        Fitness_Based_SS(citizen,&parent1,&parent2);
        GA_genes_adjustment(citizen,item);
        GA_fitness_calculation(citizen,item);
        Now_fit = Sumfitness(citizen);
        find_best(citizen,&best);
        termination_criteria(Now_fit,Pre_fit,&Counter);
        print_Population(citizen);
        print_best(best);
        generation_count ++;
        printf("Generation : %d\n", generation_count);
        printf("Population overall points: %d\n",population_overall_point(citizen));
        printf(".................................................................\n");
        printf(".................................................................\n");
        printf(".................................................................\n");
    }
    conclusion(best);

    return 0;
}