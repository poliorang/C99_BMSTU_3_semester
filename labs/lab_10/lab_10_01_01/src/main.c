#include "errors_structures.h"
#include "list.h"
#include "insert.h"
#include "reverse.h"
#include "sort.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    if (argc != ARG_FOUR && argc != ARG_FIVE)
        return ARG_ERR;

    FILE *fin = fopen(argv[ARG_ONE], "r");

    if (fin == NULL)
        return FILE_ERR;

    node_t *list = NULL;
    if ((list = create_list(fin)) == NULL)
    {
        fclose(fin);
        return CREATE_LIST_ERR;
    }

    // reverse
    if (!strcmp(argv[ARG_THREE], "r"))
        list = reverse(list);

    // sort
    if (!strcmp(argv[ARG_THREE], "s"))
        list = sort(list, comparator_packs);

    // insert
    if (!strcmp(argv[ARG_THREE], "i"))
    {
        FILE *fins = fopen(argv[ARG_FOUR], "r");

        if (fins == NULL)
        {
            fclose(fin);
            free_list(&list);
            return FILE_ERR;
        }

        insert_from_file(fins, &list);
        if (list == NULL)
        {
            fclose(fin);
            fclose(fins);
            return INSERT_ERR;
        }
        fclose(fins);
    }

    FILE *fout = fopen(argv[ARG_TWO], "w");
    print_list(fout, list);

    free_list(&list);
    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}
