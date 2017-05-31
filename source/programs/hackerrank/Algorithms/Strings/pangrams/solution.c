#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLEN  (1000)
#define PANGRAM   (0x3FFFFFF)
#define INDEX(c) \
    ({ \
        int _i = -1; \
        if (((c) >= 'a') && ((c) <= 'z')) \
            _i = ((c) - 'a'); \
        else if (((c) >= 'A') && ((c) <= 'Z')) \
            _i = ((c) - 'A'); \
        _i; \
    })

#define IS_PANGRAM(p)  ((p) == PANGRAM)

int main() {
    unsigned int pang = 0;
    int i = 0;
    int c_ind = -1;
    char input[MAXLEN];
    int inputlen = 0 ;
    

    scanf("%[a-z,A-Z, ]",input);
    inputlen = strlen(input);
        
    for( ; i < inputlen; i++) {
        c_ind = INDEX(input[i]);
        if (c_ind >= 0)
            pang |= (1 << c_ind);
        
        if (IS_PANGRAM(pang)) {
            printf("pangram\n");
            return 0;
        }
    }

    printf("not pangram\n");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
