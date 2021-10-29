void mergeSort(int* arr, int p, int r){
  if(p < r){
      int q = (p+r)/2;
      mergeSort(arr, p, q);
      mergeSort(arr, q+1, r);
      merge(arr, p, q, r);
  }
}

void merge(int* arr, int p, int q, int r){
    int n1 = (q-p)+1; //length of left subarray
    int n2 = (r-q); //length of right subarray
    int L[n1];
    int R[n2];
    
    for(int i = 0; i < n1; i++){
        L[i] = arr[p+i];
    }
    
    for(int j = 0; j < n2; j++){
        R[j] = arr[q+j+1];
    }
    
    int i = 0;
    int j = 0;
    int k = p;
    
     while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}



int main()
{
    int N = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

  	mergeSort(arr, 0, N-1);
  
    for (int i = 0; i < N; i++) {
        printf("%d", *(arr + i));

        if (i != N - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
