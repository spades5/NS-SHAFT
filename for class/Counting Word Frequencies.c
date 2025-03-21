#include <stdio.h>
#include <string.h>

int indexOfList_icmp(char *str, char *list[], int size){
    for(int i=0;i<size;i++){
        if(stricmp(str,list[i])==0){
            return i;
        }
    }
    return -1;
}



int main()
{
    char document[]="National Taiwan Ocean University was originally established in 1953 as a junior college for the study of maritime science and technology.\nAfter eleven years, in 1964, we became a maritime college which offered bachelor's and master's degrees in various fields of maritime studies. During this period, funds for running the college came from the Taiwan Provincial Government of the Republic of China.\nIn 1979 the national government took over the funding and we became the National Maritime College. After another decade, in 1989, the college grew into a full-fledged university, National Taiwan Ocean University (NTOU).";
    char *wordlist[1000];
    int frequency[1000]={0};
    int wTotal=0;


    char *token=strtok(document," \t\r\n,.;!?()-");
    while(token != NULL){
        int found=indexOfList_icmp(token,wordlist,wTotal);

        if(found!=-1){
            frequency[found]++;
        }
        else{ // a new word is found
            wordlist[wTotal]=token;
            frequency[wTotal]=1;
            wTotal ++;
        }
        token=strtok(NULL," \t\r\n,.;!?()-");
    }

    for(int i=0;i<wTotal;i++){
        printf("%s     %d\n",wordlist[i],frequency[i]);
    }
    return 0;
}
