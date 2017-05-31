#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void catch_mouse(int A, int B, int C)
{
    int AC = abs((A-C));
    int BC = abs((B-C));
    
    if(AC > BC) printf("Cat B\n");
    else if(AC == BC) printf("Mouse C\n");
    else printf("Cat A\n");
}

int main(){
    int q; 
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int x; 
        int y; 
        int z; 
        scanf("%d %d %d",&x,&y,&z);
        
        catch_mouse(x, y, z);
    }
   
    return 0;
}

