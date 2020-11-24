#include <stdio.h>

int getdegree(float a) {
    if (a < 0)
        a = -a;
    int b = a;
    return b;
}

int getminute(float a) {
    if (a < 0)
        a = -a;
    int b = getdegree(a);
    float c = (a - b) * 60;
    int d = c;
    return d;
}

float getsecond(float a) {
    if (a < 0)
        a = -a;
    int b = getdegree(a);
    float c = (a - b) * 60;
    int d = getminute(a);
    float e = (c - d) * 60;
    return e;
}

char getNS(float a) {
    char b;
    if (a > 0)
        b = 'N';
    else if (a < 0)
        b = 'S';
    return b;
}

char getEW(float a) {
    char b;
    if (a > 0)
        b = 'E';
    else if (a < 0)
        b = 'W';
    else
        b = ' ';
    return b;
}

int main() {
    float laf, lof, las, los;
    int lad, lod, lam, lom;
    char la, lo;
    printf("Enter coordinates in decimal form:\n");
    printf("Latitude:");
    scanf("%f", &laf);
    printf("Longitude:");
    scanf("%f", &lof);
    lad = getdegree(laf);
    lod = getdegree(lof);
    lam = getminute(laf);
    lom = getminute(lof);
    las = getsecond(laf);
    los = getsecond(lof);
    la = getNS(laf);
    lo = getEW(lof);
    printf("Latitude: %d degrees, %d minutes, %.6f seconds %c \n", lad, lam, las, la);
    printf("Longitude: %d degrees, %d minutes, %.6f seconds %c \n", lod, lom, los, lo);
    return 0;
}