#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 225
void Result(FILE *f, int n)
{
    char ligne[n][MAX_LENGTH];
    int x = 0; 
    while (fgets(ligne[x % n], MAX_LENGTH, f)!= NULL)
    {
        x++;
    }
    int y = x > n? x % n : 0;
    int i;
    for (i = y; i < y + n; i++)
    {
        printf("%s", ligne[i % n]);
    }
}
int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr,"Utilisation: %s <nom_fichier> <nombre_ligne>\n", argv[0]);
        return 1;
    }
    char *Test = argv[1];
    int n = atoi(argv[2]);
    FILE *f = fopen(Test, "r");
    if (f == NULL)
    {
        printf("Error\n");
        return 1;
    }

    Result(f, n);

    fclose(f);

    return 0;

}