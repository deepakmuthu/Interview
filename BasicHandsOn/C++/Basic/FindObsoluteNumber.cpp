#include <stdio.h>
#include <cmath>

void update(int *a,int *b) {
    // Complete this function    
    int i32Tempa = *a + *b;
    *b = std::abs (*a - *b);
    *a = i32Tempa;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}