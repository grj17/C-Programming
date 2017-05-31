#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int gcf2(int x, int y)
{
        if((x == 1) || (y == 1))
            return 1;
        if(x == y)
                return x;
        else if (x > y)
                return gcf2(x - y, y);
        else
                return gcf2(x, y - x);
}

int gcf(int *a, int len)
{
        if ((len < 1) || (a == NULL)) {
                return -1;
        }

        if(len == 1) {
            return a[0];
        }

    
        int ans = gcf2(a[0], a[1]);
        if (len > 2) {
                for (int i = 2; i < len; i++) {
                        ans = gcf2(ans, a[i]);
                }
        }
        return ans;
}

int lcm(int *a, int len, int min)
{
        if ((len < 1) || (a == NULL)) {
                return -1;
        }
    
        if(len == 1) {
            if (a[0] > min) return -1;
            return a[0];
        }

        unsigned long ans = (a[0] * a[1]) / gcf2(a[0], a[1]);
        if (ans > min) return -1;
        if (len > 2) {
                for (int i = 2; i < len; i++) {
                        ans = (ans * a[i]) / gcf2(ans, a[i]);
                        if (ans > (unsigned long)min) return -1;
                }
        }
        return (int)ans;
}

int count_factor(int a, int b)
{
        int count = 0;
        unsigned long new_a = a;
    
        if (new_a > b) return count;
        else if (b % new_a) return -1;
        else if (b == a) return 1;
        else {
                while(new_a <= b) {
                if((b % new_a) == 0) count++;
                new_a += a;
            }    
        }
        return count;
        
 }

int main(){
    int n; 
    int m; 
    scanf("%d %d",&n,&m);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(int b_i = 0; b_i < m; b_i++){
       scanf("%d",&b[b_i]);
    }
    
    int min_b = b[0];
    for(int b_i = 1; b_i < m; b_i++){
       if(b[b_i] < min_b) min_b = b[b_i];
    }
    int a_lcm = lcm(a, n, min_b);
    if (a_lcm == -1)
        printf("%d\n", 0);    
    else {
        int b_gcf = gcf(b, m);
        if (b_gcf < a_lcm) printf("%d\n", 0);
        if (b_gcf % a_lcm) printf("%d\n", 0);
        else printf("%d\n", count_factor(a_lcm, b_gcf));
    }
    return 0;
}

