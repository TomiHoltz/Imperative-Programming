
void secuenciaAsc(const int v[], size_t dim, int *comienzo, int *longitud)
{
    *comienzo = 0;
    // Si es vacía, debe quedar *longitud en cero
    // Si no es vacía, tenemos al menos la primer secuencia con longitud uno
    *longitud = dim > 0;
    for (int i = 1, comienzoAux = 0, longitudAux = 1; i < dim; i++)
    {
        if (v[i - 1] < v[i])
        {
            longitudAux++;
        }
        else
        {
            comienzoAux = i;
            longitudAux = 1;
        }
        if (longitudAux > *longitud)
        {
            *comienzo = comienzoAux;
            *longitud = longitudAux;
        }
    }
}