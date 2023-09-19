#include <stdio.h>


typedef unsigned long long Macaron;

Macaron factorielle(Macaron entree){
    Macaron facts = 1;
    for (int c = 1; c <= entree; c++){
        facts *= c;
    }
    return facts;
}


int main(){
    int N;
    printf("DONNE UN N AZILAAAAA :\n");
    scanf("%d", &N);
    printf("N: %d\n", N);
    
    for(int i=1; i<=N; i++){
        printf("tu est un %llu harry !\n",factorielle(i));
    }
    return 42;
}
