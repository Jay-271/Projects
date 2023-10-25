//Jason Avila-Soria quicksort array algorithm
package practice_9_29;

public class QuickSort {
    
    public static void quickSortRecursive(int arr[], int begin, int end) {
        if (begin < end) {
            int subArrPos = splitArr(arr, begin, end);

            quickSortRecursive(arr, begin, subArrPos-1);
            quickSortRecursive(arr, subArrPos+1, end);
        }
    }
    
    private static int splitArr(int arr[], int begin, int end) {
        int pivot = arr[end];
        int i = (begin-1);

        for (int j = begin; j < end; j++) {
        	//if array at pos is less than pivot then swap, otherwise continue.
            if (arr[j] <= pivot) {
                i++;

                int Temp = arr[i];
                arr[i] = arr[j];
                arr[j] = Temp;
            }
        }
        //swap final piece with pivot
        int Temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = Temp;
        //return correct index of items not already swapped
        return i+1;
    }
}
