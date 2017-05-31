#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char time[20] = {0};
    int hh, mm, ss;
    char ap;
    scanf("%s",time);
    sscanf(time,"%02d:%02d:%02d%cM",&hh, &mm, &ss, &ap);
    if(ap == 'A') {
        if(hh == 12) hh = 0;
    } else {
        if(hh != 12) hh += 12;
    }
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}

