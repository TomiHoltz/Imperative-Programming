// Escribir una función que cambie una matriz cuadrada por su traspuesta, recibiendo sólo los siguientes 2 parámetros:

// un número entero positivo que indique la dimensión de la matriz
// la matriz cuadrada

#include <stdio.h>
#include <assert.h>

#define DIMMAX 10

void transpose(unsigned int dim, int matriz[dim][dim]);

int main(void)
{

    int m[DIMMAX][DIMMAX] = {
        {1, 2, 3, 4, 5, 6},
        {11, 12, 13, 14, 15, 16},
        {21, 22, 23, 24, 25, 26},
        {31, 32, 33, 34, 35, 36},
        {41, 42, 43, 44, 45, 46},
        {51, 52, 53, 54, 55, 56}};

    int t[DIMMAX][DIMMAX] = {
        {1, 11, 21, 31, 41, 51},
        {2, 12, 22, 32, 42, 52},
        {3, 13, 23, 33, 43, 53},
        {4, 14, 24, 34, 44, 54},
        {5, 15, 25, 35, 45, 55},
        {6, 16, 26, 36, 46, 56}};
    transpose(1, m); // no deberia cambiar
    assert(m[0][0] == 1);
    assert(m[0][1] == 2);
    assert(m[1][0] == 11);
    assert(m[1][1] == 12);

    transpose(DIMMAX, m);
    for (int i = 0; i < DIMMAX; i++)
    {
        for (int j = 0; j < DIMMAX; j++)
            assert(m[i][j] == t[i][j]);
    }

    puts("OK!");
}

void transpose(unsigned int dim, int matriz[dim][dim])
{
    int i, j, aux;

    for (i = 0; i < dim; i++)
        for (j = 0; j < i; j++)
        {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    return;
}
