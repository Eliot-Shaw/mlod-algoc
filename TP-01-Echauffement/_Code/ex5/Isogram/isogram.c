#include "isogram.h"
#include <string.h>
#include <ctype.h> 


bool is_isogram(const char* phrase){
    bool reponss = true;
    if(phrase==NULL) return false;

    for(int i=0; i<(int)strlen(phrase); i++){
        for(int j=0; j<(int)strlen(phrase); j++){
            if(i!=j && phrase[i]!=' '){
                if(toupper(phrase[i])==toupper(phrase[j])) {
                    reponss = false;
                }
                if(phrase[i]=='-'&&phrase[j]=='-') {
                    reponss = true;
                }
            }
        }   
    }
    return reponss;
}