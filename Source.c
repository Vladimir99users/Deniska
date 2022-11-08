#include <stdio.h>
#include <malloc.h>
#include <time.h>
#pragma warning(disable : 4996)
int main() {
    FILE* fp;
    int rows = 10000;
    int cols = 10000;
    double** mas1 = (double**) malloc(rows * sizeof(double*));
    double** mas2 = (double**)malloc(rows * sizeof(double*));
    double** mas3 = (double**)malloc(rows * sizeof(double*));
    for (int row = 0; row < rows; row++)
    {
        mas1[row] = (double*)malloc(cols * sizeof(double));
        mas2[row] = (double*)malloc(cols * sizeof(double));
        mas3[row] = (double*)malloc(cols * sizeof(double));
    }
    printf("\nMemory allocation is completed!\n");
    fp = fopen("file1.txt", "r");
    for(int i= 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            fscanf(fp, "%lf", &mas1[i][j]);
        }
    }
    fclose(fp);
    printf("\nFile1 has been read\n");
    fp = fopen("file2.txt", "r");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(fp, "%lf", &mas2[i][j]);
        }
    }
    fclose(fp);
    printf("\nFile2 has been read\n");
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mas3[i][j] = 0;
            for (int k = 0; k < rows; k++)
                mas3[i][j] += mas1[i][k] * mas2[k][j];
        }
        system("cls");
        printf("\nRows %i completed\n", i);
    }
    fTimeStop = clock();
    for (int i = 0; i < rows; i++)  
    {
        for (int j = 0; j < cols; j++)  
        {
            printf("%f ", mas3[i][j]); 
        }
        printf("\n");
    }
    long dtime = (fTimeStop-fTimeStart)/CLOCKS_PER_SEC;
    printf("\nReal time for multiply %i(s)\n",dtime);
    free(mas1);
    free(mas2);
    free(mas3);
    return(0);
}