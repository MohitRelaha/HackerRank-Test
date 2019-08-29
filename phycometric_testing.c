// Physometric Testing

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*
 * Complete the function below.
 * Please store the size of the int array to be returned in result_size pointer. For example,
 * int a[3] = {1, 2, 3};
 * *result_size = 3;
 * return a;
 * 
 */
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b ;
}

int ubound(int* arr,int n,int val)
{
    int l = 0;
    int r = n-1;

    while(l < r)
    {
        int mid = (l+r)/2;

        if(arr[mid] <= val )
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    if(arr[l] <= val)
        return l+1;
    else
        return l;
}




int lbound(int* arr, int n,int val)
{
    int l = 0;
    int r = n-1;

    while(l<r)
    {
        int mid = (l+r)/2;

        if(arr[mid] >= val)
        {
            r = mid;
        }
        else
        {
            l = mid+1 ;
        }

    }

    if(arr[l] < val)
        return l+1;
    
    return l;

}


int* jobOffers(int scores_size, int* scores, int lowerLimits_size, int* lowerLimits, int upperLimits_size, int* upperLimits, int* result_size) {
    qsort(scores,scores_size,sizeof(int),cmp);

    int* arr = (int*)malloc(sizeof(int) * lowerLimits_size);

    int i;
    for(i = 0; i<lowerLimits_size; i++)
    {
        int a = lbound(scores,scores_size,lowerLimits[i]);
        int b = ubound(scores,scores_size,upperLimits[i]);

        int val = (b-a);

        *(arr + i) = val;

    }

    *result_size = lowerLimits_size;

    return arr;

}
int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int* res;
int res_size;
    int scores_size = 0;
    scanf("%d\n", &scores_size);

    int scores[scores_size];
    for(int i = 0; i < scores_size; i++) {
        int scores_item;
        scanf("%d", &scores_item);
        scores[i] = scores_item;
    }

    int lowerLimits_size = 0;
    scanf("%d\n", &lowerLimits_size);

    int lowerLimits[lowerLimits_size];
    for(int i = 0; i < lowerLimits_size; i++) {
        int lowerLimits_item;
        scanf("%d", &lowerLimits_item);
        lowerLimits[i] = lowerLimits_item;
    }

    int upperLimits_size = 0;
    scanf("%d\n", &upperLimits_size);

    int upperLimits[upperLimits_size];
    for(int i = 0; i < upperLimits_size; i++) {
        int upperLimits_item;
        scanf("%d", &upperLimits_item);
        upperLimits[i] = upperLimits_item;
    }

    res = jobOffers(scores_size, scores, lowerLimits_size, lowerLimits, upperLimits_size, upperLimits, &res_size);
    for (int res_i = 0; res_i < res_size; res_i++) {

        fprintf(f, "%d\n", res[res_i]);

    }


    fclose(f);
    return 0;
}

