#include<stdio.h>

int main(){
    int N;
    printf("DONNE UN N AZILAAAAA :\n");
    scanf("%d", &N);
    printf("N: %d\n", N);

    for(int o=0; o<=N;o++){
        int sommeDiviseurs=0;
        for(int i=1; i<o; i++){
            if(o%i==0) {
                sommeDiviseurs+=i;
            }
        }
        if(sommeDiviseurs==o){
            printf("%d est parfait ou presque\n", o);
        }else{
            printf("%d n'est pas parfait !\n", o);
        }
    }
    return 42;
}
