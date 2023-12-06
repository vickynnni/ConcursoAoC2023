#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 2048

int main(int argc, char* argv[]){
    FILE *f  = fopen(argv[1],"r");
    int d1, d2, i;
    int res = 0;
    char cad[2];
    int num = 0;
    char linea[MAX];
    

    while(fgets(linea, MAX, f)){
        d1 = -1;
        d2 = -1;
        for (int i = 0; linea[i] != '\0'; i++) {
            if (isdigit(linea[i])) {
                if (d1 == -1) d1 = linea[i] - '0';
                else {
                    d2 = linea[i] - '0';
                }
            }
        }
        if (d2 == -1) d2 = d1;
        sprintf(cad,"%d%d", d1, d2);
        num = atoi(cad);
        res = num + res;
    }
    printf("%d\n",res);

    fclose(f);
    return 0;
}