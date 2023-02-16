#include <stdio.h>
#include <string.h>


#define ARRSIZE 50


void shift_elements(int* arr, int i) {
  for (int j = i; j > 0; j--) {
    *(arr+j) = *(arr+j-1);
  }
}



void insertion_sort(int* arr, int len) {
  for (int i = 1; i < len; i++) {
    int key = *(arr + i);
    int j = i - 1;
    if (*(arr + i) < *(arr + j)){
        while (j >0 && *(arr + i) < *(arr + j)) { 
            j--;
        }

        if (*(arr + i) < *(arr + j)){
            shift_elements(arr + j, i-j);
            *(arr + j) = key;
        }
        else{
                j= j+1;
                shift_elements(arr + j, i-j);
                *(arr + j) = key;
        }
        
    }
  
    
  }

}


int main(int argc, char const *argv[])
{
    int arr[ARRSIZE] = { 0 };

    for (int i = 0; i < ARRSIZE; i++)
    {
      scanf(" %d", (arr + i));
    }
   
    insertion_sort(arr, ARRSIZE);

    for (int i = 0; i < ARRSIZE; ++i){
        printf("%d%c", *(arr+i), ((i == (ARRSIZE - 1)) ? '\n':','));
    }


    return 0;
}
