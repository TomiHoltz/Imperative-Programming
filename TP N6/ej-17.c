// Escribir una función armaFilas que recibe una matriz de enteros de N filas y M columnas, y un vector de dimensión N.
// La función debe armar los números que se forman con cada fila y guardarlos en el vector.
// Si hubiera números negativos o de más de una cifra en una fila, no se completa el armado de ese número, pero se sigue con la próxima fila.
// La función retorna en su nombre la dimensión final del vector de números.

#include <stdio.h>
#include <assert.h>

#define N 4
#define M 5

int armaFilas(const int m[][M], int v[]);

int main(void)
{
    int m1[N][M] = {{1, 2, 3, 4, 5},
                    {1, 2, 13, 4, 5},
                    {1, 2, 4, 4, 5},
                    {1, 2, -3, 4, 5}};
    int vec[N];
    int n = armaFilas(m1, vec);
    assert(n == 2);
    assert(vec[0] == 12345);
    assert(vec[1] == 12445);

    int m2[N][M] = {{1, 0, 3, 4, 5},
                    {0, 2, 1, 4, 5},
                    {9, 9, 9, 9, 9},
                    {0, 0, 1, 4, 5}};
    n = armaFilas(m2, vec);
    assert(n == 4);
    assert(vec[0] == 10345);
    assert(vec[1] == 2145);
    assert(vec[2] == 99999);
    assert(vec[3] == 145);

    int m3[N][M] = {{11, 0, 3, 4, 5},
                    {0, 2, 1, 14, 5},
                    {9, 9, 9, 91, 9},
                    {0, 0, 1, 14, 5}};
    n = armaFilas(m3, vec);
    assert(n == 0);

    printf("OK!\n");
    return 0;
}

int armaFilas(const int m[][M], int v[])
{
    int dim = 0;

    for (int i = 0; i < N; i++)
    {
        int suma = 0;
        int ignoreRow = 0;

        // En cada fila, debemos recorrerla y concatenar
        for (int j = 0; j < M; j++)
        {
            int actualValue = m[i][j];
            // Si es menor a 10 y mayor o igual a 1, multiplicamos por 10^(N-j)
            if (actualValue >= 0 && actualValue < 10)
            {
                suma *= 10;
                suma += actualValue;
            }
            else
            {
                // De haber algun elemento invalido se saltea la fila
                ignoreRow = 1;
                printf("De value was %d\n", actualValue);
                break;
            }
        }

        if (!ignoreRow)
        {
            v[dim++] = suma;
        }
    }
    
    return dim;
}
