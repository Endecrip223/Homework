#include <stdio.h>
int main()
{
    int mass[10]={3,9,12,4,6,71,2,8,10,5};
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<9;j++)
        {
            if (mass[j]>mass[j+1])
            {
                mass[j]=mass[j]+mass[j+1];
                mass[j+1]=mass[j]-mass[j+1];
                mass[j]=mass[j]-mass[j+1];
            }
        }
    }
    
    for (int i=0;i<10;i++) printf("%d/",mass[i]);
}
