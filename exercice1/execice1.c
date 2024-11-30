#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[100000], c[] = "(){}[]";
    int l;
    bool test = true, yesorno = true;

    printf("Entrez une chaîne : ");
    gets(s);
    l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (!strchr(c, s[i]))
        {

            yesorno = false;
            return 0;
        }
    }

    if (l % 2 != 0)
    {
        yesorno = false;
        return 0;
    }

    if (l % 2 == 0)
    {
        for (int i = 0, j = l - 1; i < l / 2 && j >= l / 2; i++, j--)
        {
            if ((strchr(")]}", s[i]) || strchr("([{", s[j])))
            {
                yesorno = false;
                break;
            }

            if (!((s[j] == s[i] + 1) || (s[j] == s[i] + 2)))
            {
                yesorno = false;
                return 0;
            }
        }

        if (yesorno)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
