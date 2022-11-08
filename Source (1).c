#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
int main()
{
    FILE* fp;
    fp = fopen("file2.txt", "w+");
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            fprintf(fp, "%f ", randfrom(-100, 100));
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return(0);
}