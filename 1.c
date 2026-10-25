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
    char line[18];
    char text_buffer[1000];
    char temp[1000+18];
    if(fgets(line, sizeof(line), stdin)==NULL){
        return 0;
    }
    int len = strlen(line);
    if(len>0 && line[len-1]=='\n'){
        line[--len]='\0';
    }
    if(len>0 && line[len-1]=='\r'){
        line[--len] = '\0';
    }
    int saved = 0;
    int total = 0;
    long long pattern_hash = hash(line, len);
    printf("%lld ", pattern_hash);
    while(fgets(text_buffer, sizeof(text_buffer), stdin)!=NULL){
        int len_t = strlen(text_buffer);
        memcpy(temp+saved, text_buffer, len_t);
        int current_len = len_t+saved;
        for(int i = 0; i+len<=current_len;i++){
            if(total+i+len<=total+saved)
                continue;
            long long txt_hash = hash((unsigned char*)&temp[i], len);
            if(pattern_hash==txt_hash){
                for(int j = 0; j<len; j++){
                    printf("%d ", total-saved+i+j+1);

                    if(line[j]!=temp[i+j]) break;
                }
            }
        }
    }
}