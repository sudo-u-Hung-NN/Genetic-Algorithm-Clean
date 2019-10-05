// Điều kiện để GA dừng lại là sau khoảng 3-4 thế hệ mà Sum(fitness) không đổi.
// Ta đặt một counter đếm nếu Sumfitness sau  = Sumfitness trước thì +1.
// Nếu không thì reset counter về 0.

void termination_criteria(int Now_fit, int Pre_fit, int *Counter) {
  if(Now_fit > Pre_fit) *Counter = 0;
}

int Sumfitness(individual*citizen){
  int Sumfitness = 0;
  int i;
  for ( i = 0; i < _POP_; i++) {
    Sumfitness += citizen[i].fitness;
  }
  return Sumfitness;
}

void conclusion(individual best) {
  printf("The best fitness/value found: %d\n", best.fitness);
  printf("Weigh: %d\n",best.weigh);
  printf("Put in: \n");
  int i;
  for ( i = 0; i < _GENE_LENGTH_; i++) {
    if (best.genes[i] != 0) {
      printf("Item %d\n",i);
    }
  }
}
