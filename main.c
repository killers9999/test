#include <stdio.h>


int main()
{
    char a,b,c;
    while(scanf("%c%c%c%*c",&a,&b,&c)!=EOF)
    {
        if(a<b&&b<c)
        printf("%c %c %c\n",a,b,c);
    else if(a<c&&b<c)
        printf("%c %c %c\n",a,c,b);
    else if(b<c&&c<a)
        printf("%c %c %c\n",b,c,a);
    else if(b<a&&a<c)
        printf("%c %c %c\n",b,a,c);
    else if(c<a&&a<b)
        printf("%c %c %c\n",c,a,b);
    else printf("%c %c %c\n",c,b,a);
    }
    return 0;
}
