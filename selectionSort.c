#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int a[100] , n , j , i , temp;
    clock_t start , end;
    double time_taken;
    
    printf("Enter size of array");
    scanf("%d",&n);
    
    for(i = 0; i<n; i++){
        a[i] = (rand() % 100) + 1;
        printf("%d ",a[i]);
    }
    
    start = clock();
    
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    end = clock();
    
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000 ;
    
    printf("\n Shorted array :");
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("time taken = %f",time_taken);
    return 0;
}