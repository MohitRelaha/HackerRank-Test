/*A panagram is a word or sentence that contains every letter of the alphabet.
eg: the quick brown fox jumps over the lazy dog
*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


char* isPangram(char** arr,int n){
    
    char* res = (char*)malloc(sizeof(char)*(n+1));

    for(int i=0;i<n;i++){
        
        int alp[26]={0};

        int count=0;

        for(int j=0;j<strlen(arr[i]);j++){
            if(arr[i][j] != ' ' && alp[arr[i][j]-97] == 0)
            {
                alp[arr[i][j]-97] = 1;
                count++;
            }
        }

        if(count==26)
            res[i] = '1';
        else
            res[i] = '0';
    }

    res[n]='\0';

    return res;
}




int main() {
    

    int n;
    scanf("%d",&n);
    getchar(); // Otherwise enter considered as first input for gets
    char** arr = (char**)malloc(sizeof(char*)*n);
    
    for(int i=0;i<n;i++){
        
        char* str = (char*)malloc(sizeof(char)*100001);
        //char str[100001]; Wrong(Memory not allocated)
        gets(str);
        arr[i] = str;

    }
    //char* res = isPangram(arr,n);
    printf("%s",isPangram(arr,n));
    return 0;
}
