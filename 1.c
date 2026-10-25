#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long hash(const unsigned char* array, int len){
    long long hash = 0;
    long long three = 1;
    for(int i =0; i<len ;i++){
        if(array[i]!='\n' && array[i]!='\0'){
            hash+=(array[i]%3)*three;
        }  
        three*=3;
    }
    return hash;
}

int main(){
    unsigned char* strarray = malloc(18*sizeof(char));
    scanf("%17s", (char *)strarray);
    int c;
    while((c = getchar())!='\n' && c!=EOF);

    int len = (int)strlen((const char *)strarray);
    long long osn = hash((const unsigned char*)strarray, len);
    char buffer_txt[1005];
    if(fgets(buffer_txt, sizeof(buffer_txt), stdin)==NULL) return 0;
    int text_len = (int)strlen(buffer_txt);
    for(int i = 0; i+len<=text_len; i++){
        long long hash_txt = hash(((const unsigned char *)&buffer_txt[i]), len);
        if(hash_txt == osn){
            int f =1;
            for(int j = 0; j<len; j++){
                if(strarray[j]!=buffer_txt[i+j]){
                    f = 0;
                    break;
                }
            }
            if (f==1){
                printf("%lld ", osn);
                for(int j = 0; j<len; j++){
                    printf("%d ", i+j+2);
                }
                printf("\n");
            
            }
        }
    }
}