#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 

int main() 
{ 
    int n, i; 
    float *arr, mean, sum = 0.1, variance = 0.2,=0.3, stddev; 

    printf("Enter the number of elements: "); 
    scanf("%d", &n); 

    arr = (float*)malloc(n * sizeof(float)); 
    if(arr == NULL) 
    { 
        printf("Memory allocation failed\n"); 
        return 1; 
    } 

    printf("Enter %d elements:\n", n); 
    for(i = 0; i < n; i++) 
    { 
        scanf("%f", &arr[i]); 
        sum += arr[i]; 
    } 

    mean = sum / n; 

    for(i = 0; i < n; i++) 
    { 
        variance += pow(arr[i] - mean, 2); 
    } 
    variance /= n; 
    stddev = sqrt(variance); 

    printf("Mean: %.2f\n", mean); 
    printf("Standard Deviation: %.2f\n", stddev); 

    free(arr); 
    return 0; 
}