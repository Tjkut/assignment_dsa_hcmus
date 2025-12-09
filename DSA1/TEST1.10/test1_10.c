#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000

void taoChuoiChen(char *out, const char *in)
{
    int len = strlen(in);
    int p = 0;

    for(int i = 0; i < len; i++)
    {
        out[p++] = in[i];
        out[p++] = in[i] + 1;
    }
    out[p] = '\0';
}

int main()
{
    char s[MAX];
    char pat[10][MAX];
    char tmp[MAX];
    char ans[MAX];
    ans[0] = '\0';

    int k;

    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    scanf("%d", &k);
    getchar();

    for(int i = 0; i < k; i++)
    {
        fgets(pat[i], sizeof(pat[i]), stdin);
        pat[i][strcspn(pat[i], "\n")] = '\0';
    }

    int i = 0;
    int n = strlen(s);

    while(i < n)
    {
        int ok = 0;

        for(int j = 0; j < k; j++)
        {
            int lenp = strlen(pat[j]);

            if(strncmp(&s[i], pat[j], lenp) == 0)
            {
                taoChuoiChen(tmp, pat[j]);
                strcat(ans, tmp);
                i += lenp;
                ok = 1;
                break;
            }
        }

        if(!ok)
        {
            int l = strlen(ans);
            ans[l] = s[i];
            ans[l+1] = '\0';
            i++;
        }
    }

    printf("%s", ans);
    return 0;
}

