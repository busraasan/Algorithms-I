void insertionSort(int N, int* arr){
    for(int i = 1; i < N; i++){
        int j = i;
        while((arr[j] < arr[j-1]) && (j-1 >= 0)){
            int key = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = key;
            j--;
        }
    }
}