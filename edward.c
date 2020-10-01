#include<stdio.h>

void main()
{
    int T, N , H, Y1, Y2, L, i1,i2, j, k,count;
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {
        scanf("%d %d %d %d %d", &N, &H, &Y1, &Y2, &L);
        while(L>0 || N>0)
        {
            scanf("%d %d",&i1,&i2);
            if(i1==1)
            {
                if(i2>=(H-Y1))
                    count++;
                 else
                {
                    count++;
                    L--;
                }
            }
            if(i1==2)
            {
                if(i2<Y2)
                    count++;
                else
                {
                    count++;
                    L--;
                }
            }
            N--;
        }
        printf("%d \n",count);
    }
}
