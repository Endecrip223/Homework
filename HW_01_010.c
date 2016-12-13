#include <stdio.h>

int minTwo(int a, int b)
{
   if(a<b) return a;
   else return b;
}

int maxTwo(int a, int b)
{
   if(a<b) return b;
   else return a;
}

int maxThree(int a, int b, int c)
{
   if(a<b) a=b;
   if(a<c) return c;
   else return a;
   
}

int circ(int u, int p)
{
    if (u>=p) u=0;
    return u;
}


bool buildings(int s[],int x[], int y[], int z[])
{
    int g[3][2]={{x[0],x[1]},{y[0],y[1]},{z[0],z[1]}};
    bool a=false;
    for(int i=0;i<2 && !a;i++)
    {
       for(int j=0;j<8 && !a;j++) 
       {
           if(s[i]>=(g[0][j&1]+g[1][j&2]+g[2][j&4])&&
   (s[i-1]>=maxThree(g[0][1-j&1],g[1][1-j&2],g[2][1-j&4]))
             ) a=true; 
       }
       
    }
    
    if(!a)
    {
     for(int i=0;i<2 && !a;i++)
     {
      for(int j=0;j<3 && !a;j++) 
      {
       for(int k=0;k<8 && !a;k++)  
       {
        if(s[i]>=g[j][i&1]+g[circ(j+1,3)][i&2] &&
           s[1-i]>=g[j][1-i&1]+g[circ(j+2,3)][i&4] &&
           s[1-i]>=g[circ(j+1,3)][1-i&2]+g[circ(j+2,3)][i&4] &&
           s[i]>=g[circ(j+2,3)][i&4])  a=true;        
       }             
      }     
     }    
    }
    return a;
}



int main() 
{
    int a[2]; int b[2]; int c[2];
    int land[2];
    printf("Enter sides of 1 ");
    for(int i=0;i<2;i++)
    {scanf("%d",&a[i]);}
    printf("Enter sides of 2 ");
    for(int i=0;i<2;i++)
    {scanf("%d",&b[i]);}
    printf("Enter sides of 3 ");
    for(int i=0;i<2;i++)
    {scanf("%d",&c[i]);}
    printf("Enter sides of land ");
    for(int i=0;i<2;i++)
    {scanf("%d",&land[i]);}
    
    printf("%i",buildings(land, a, b, c));
   
    return 0;
}
