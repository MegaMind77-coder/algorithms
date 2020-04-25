#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10000

long long createhash(char string[],int n){
    long long result=0;
    for(int i=0;i<n;i++)
    {
        result += (long long)((int)string[i]*pow(10,i));
    }
    return result;
}

long long rollinghash(char string[],int i,long long oldhash,int n){
    long long newhash = (long long)((int)oldhash - (int)string[i]);
    newhash = (long long)newhash/10;
    newhash += (long long)((int)string[i+n]*pow(10,n-1));
    return newhash;
}

int main() {
    char text[]="ababababababababab";
    char pattern[]="a";
    long long text_hash=createhash(text,strlen(pattern));
    long long pattern_hash=createhash(pattern,strlen(pattern));
    //printf("%lld\n\n",pattern_hash);
    //printf("%lld\n\n",text_hash);

    for(int i=0;i<strlen(text)-strlen(pattern)+1;i++){
        if (text_hash == pattern_hash){
            int j=i;
            for(j;j<strlen(pattern)+i;j++){
                if(text[j]!=pattern[j-i])
                    break;
            }

            if(j == strlen(pattern)+i){
             printf("pattern matches at %ld\n",j-strlen(pattern)+1);
            }

        }
            long long new_hash = rollinghash(text,i,text_hash,strlen(pattern));
            text_hash = new_hash;
        //    printf("%lld\n\n",text_hash);
    }

    return 0;
}