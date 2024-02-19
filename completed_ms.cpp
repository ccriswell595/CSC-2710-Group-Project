void merge(int* arr, int start, int mid, int end){
    int leftPtr = start;
    int rightPtr = mid + 1;
    int mergedArrSize = end - start + 1;
    int mergedArray[mergedArrSize];

    int i = 0;
    while(leftPtr <= mid && rightPtr <= end){
        if(arr[leftPtr] <= arr[rightPtr]){
            mergedArray[i] = arr[leftPtr];
            leftPtr++;
        }
        else{
            mergedArray[i] = arr[rightPtr];
            rightPtr++;
        }
        i++;
    }

    while(leftPtr <= mid){
        mergedArray[i] = arr[leftPtr];
        leftPtr += 1;
        i++;
    }

    while(rightPtr <= end){
        mergedArray[i] = arr[rightPtr];
        rightPtr += 1;
        i++;
    }

    for (int j = 0; j < mergedArrSize; j++){
        arr[start + j] = mergedArray[j];
    }

}
void mergesort(int arr, int start, int mid, int end){
    // implement me
}
int main(){

}
