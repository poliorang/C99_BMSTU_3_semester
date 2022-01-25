#include "list.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    if (argc != 3)
        return EXIT_FAILURE;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return EXIT_FAILURE;

    node_t *head = NULL;

    if ((head = create_list(f)) == NULL)
    {
        free_list(head);
        fclose(f);
        return EXIT_FAILURE;
    }

    FILE *fout = fopen(argv[2], "w");
	
    head = reverse_words(head);
    head = reverse_list(head);
	
    print_list(head, fout);
    free_list(head);

    fclose(f);
    fclose(fout);

    return EXIT_SUCCESS;
}
