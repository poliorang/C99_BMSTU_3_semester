#include "matrix.h"

#define SC_ERR 1
#define FILE_ERR 2
#define ALL_ERR 3

int main()
{
    setbuf(stdout, NULL);


    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
        return FILE_ERR;

    int32_t n, m;
    if (fscanf(f, "%d%d", &n, &m) != 2)
        return SC_ERR;

    int32_t **data = allocate_matrix(n, m);

    if (data == NULL)
        return ALL_ERR;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fscanf(f, "%d", &data[i][j]) != 1)
                return SC_ERR;


    int *rows = calloc((size_t)n, sizeof (int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (data[i][j] == 0)
            {
                rows[i] = 1;
                if (i != 0)
                    for (int k = i; k > 0; k--)
                    {
                        if  (data[k][j] == 0)
                            rows[k] = 1;
                        else
                            continue;
                    }
                if (i != n - 1)
                    for (int k = i; k < n - 1; k++)
                    {
                        if (data[k][j] == 0)
                            rows[k] = 0;
                        else
                            continue;
                    }
                break;
            }
        }


    FILE *fout = fopen("out.txt", "w");
    int non = 0;
    for (int i = 0; i < n; i++)
        if (rows[i])
            non++;

    fprintf(fout, "%d %d\n", n - non, m);
    for (int i = 0; i < n; i++)
    {
        if (!rows[i])
            for (int j = 0; j < m; j++)
                fprintf(fout, "%d ", data[i][j]);
    }

    fclose(f);
    fclose(fout);
    free_matrix(data, n);
    free(rows);


    return EXIT_SUCCESS;
}
