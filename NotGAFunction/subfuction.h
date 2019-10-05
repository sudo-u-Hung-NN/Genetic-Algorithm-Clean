
void individual_swap(struct individual *a, struct individual *b) {
  struct individual c = *a;
  *a = *b;
  *b = c;
}

void Int_swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}


