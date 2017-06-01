#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define LEAP "12.09.%d"
#define NLEAP "13.09.%d"
#define Y1918 "26.09.1918"

#define ISJULIAN(x) (((x) >= 1700) && ((x) < 1918))
#define ISGREG(x)   ((x) > 1918) && ((x) < 2701)
#define IS1918(x)   ((x) == 1918)

#define ISJLEAP(x)  (!((x)%4))
#define ISGLEAP(x)  ((!((x)%4) && (x)%100) || !((x) % 400))


void solve(int year){
    
    if(ISJULIAN(year)) {
        if(ISJLEAP(year)) printf(LEAP, year);
        else printf(NLEAP, year);
    } else if(ISGREG(year)) {
        if(ISGLEAP(year)) printf(LEAP, year);
        else printf(NLEAP, year);
    } else if(IS1918(year))
        printf(Y1918);
}

int main() {
    int year; 
    scanf("%d", &year);
    solve(year);
    return 0;
}

