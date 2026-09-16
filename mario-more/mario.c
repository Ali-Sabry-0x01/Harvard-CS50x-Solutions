#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int height ;
do
{
height = get_int("what's the height of the pyramid ? ");

}
while(height >9 || height<=0);
for (int i=0 ; i<height ; i++)
{
for(int k = height-i-1 ; k>0 ; k--)
{
printf(" ");
}
for (int j=0 ; j<=i ; j++)
{
printf("#");
}
printf("  ");
for (int q=0 ; q<=i ; q++)
{
printf("#");
}
printf("\n");
}
}
