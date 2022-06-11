#include <stdio.h>
int main()
{
    int hh,mm;
    scanf("%d %d",&hh,&mm);
    if(hh < 13&&hh >= 6){
        printf("%d\n",13-hh);
    }
    else{
        printf("0\n");
    }
    return 0;
}
