
#include <stdio.h>

struct poly
{
    int coef;
    int exp;
};

int main()
{
    int n1, n2;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n1);

    if(n1 <= 0)
    {
        printf("Invalid number of terms\n");
        return 1;
    }

    struct poly p[n1];

    printf("Enter the coefficient and exponent of the first polynomial:\n");
    for(int i = 0; i < n1; i++)
    {
        scanf("%d %d", &p[i].coef, &p[i].exp);
    }

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n2);

    if(n2 <= 0)
    {
        printf("Invalid number of terms\n");
        return 1;
    }

    struct poly q[n2];

    printf("Enter the coefficient and exponent of the second polynomial:\n");
    for(int i = 0; i < n2; i++)
    {
        scanf("%d %d", &q[i].coef, &q[i].exp);
    }

    printf("\nThe first polynomial is:\n");
    for(int i = 0; i < n1; i++)
    {
        printf("%dx^%d", p[i].coef, p[i].exp);
        if(i < n1 - 1)
            printf(" + ");
    }

    printf("\nThe second polynomial is:\n");
    for(int i = 0; i < n2; i++)
    {
        printf("%dx^%d", q[i].coef, q[i].exp);
        if(i < n2 - 1)
            printf(" + ");
    }

    int i = 0, j = 0, k = 0;
    struct poly result[n1 + n2];

    while(i < n1 && j < n2)
    {
        int sum = 0;

        if(p[i].exp == q[j].exp)
        {
            sum = p[i].coef + q[j].coef;

            if(sum != 0)
            {
                result[k].coef = sum;
                result[k].exp = p[i].exp;
                k++;
            }

            i++;
            j++;
        }
        else if(p[i].exp > q[j].exp)
        {
            result[k] = p[i];
            k++;
            i++;
        }
        else
        {
            result[k] = q[j];
            k++;
            j++;
        }
    }

    while(i < n1)
    {
        result[k] = p[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        result[k] = q[j];
        j++;
        k++;
    }

    printf("\n\nThe final added result:\n");

    if(k == 0)
    {
        printf("0\n");
    }
    else
    {
        for(int i = 0; i < k; i++)
        {
            if(i > 0 && result[i].coef > 0)
                printf(" + ");
            else if(i > 0)
                printf(" ");

            printf("%dx^%d", result[i].coef, result[i].exp);
        }
        printf("\n");
    }

    return 0;
}