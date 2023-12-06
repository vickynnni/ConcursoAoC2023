#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 2048

int numbers(char *cad) {
    if (strcmp(cad, "one") == 0) {
        return 1;
    } else if (strcmp(cad, "two") == 0) {
        return 2;
    } else if (strcmp(cad, "three") == 0) {
        return 3;
    } else if (strcmp(cad, "four") == 0) {
        return 4;
    } else if (strcmp(cad, "five") == 0) {
        return 5;
    } else if (strcmp(cad, "six") == 0) {
        return 6;
    } else if (strcmp(cad, "seven") == 0) {
        return 7;
    } else if (strcmp(cad, "eight") == 0) {
        return 8;
    } else if (strcmp(cad, "nine") == 0) {
        return 9;
    } 
    return -1;
}

void vacioArray (char *cad){
    for (int i = 0; i < 6; i++) {
        cad[i] = '\0';
    }
}
int main(int argc, char* argv[]){
    FILE *f  = fopen(argv[1],"r");
    int d1, d2, i, j,k;
    int res = 0;
    char cad[2];
    int num = 0;
    char linea[MAX];
    char posibleNum[6];
    char a;

    while(fgets(linea, MAX, f)){
        vacioArray(posibleNum);
        d1 = -1;
        d2 = -1;
        j = 0;

        for (int i = 0; linea[i] != '\0'; i++) {
            if (isdigit(linea[i])) {
                if (j == 0) {
                    if (d1 == -1) d1 = linea[i] - '0';
                    else {
                        d2 = linea[i] - '0';
                    }
                    vacioArray(posibleNum);
                    j = 0;
                } else {
                    i = i - j;
                    vacioArray(posibleNum);
                    j = 0;
                }
            } else {
                posibleNum[j++] = linea[i];
                if (numbers(posibleNum) != -1) {
                    if (d1 == -1) d1 = numbers(posibleNum);
                    else d2 = numbers(posibleNum);
                    vacioArray(posibleNum);
                    i = i - 1;
                    j = 0;
                } 
                 if (j == 5) {
                    i = i - 4;
                    vacioArray(posibleNum);
                    j = 0;
                }
            }
        }
        if (d2 == -1) d2 = d1;
        sprintf(cad,"%d%d", d1, d2);
        num = atoi(cad);
        res = num + res;
        printf("%d\n",num);
    }
    printf("%d\n",res);

    fclose(f);
    return 0;
}