#include<stdio.h>
#include<string.h>
int CODE;
int N;
struct course
{
    int num;
    char name[10];
    int hours;
    int score;

}cour[1000];


/*����Ա����*************************************************************************************************/
void input()
{
    int i;
    printf("������¼��γ���Ŀ��");
    scanf("%d",&N);
    printf("�����룺�γ̱��� �γ����� ��ѧʱ ѧ��\n");
    for(i=0;i<N;i++)
    scanf("%d %s%d%d",&cour[i].num,cour[i].name,&cour[i].hours,&cour[i].score);
    printf("¼�����\n");
    printf("*********************************************\n\n");
}
void change()/*���޸ģ���һ������*/
{
    int n;
    printf("��������Ҫ�޸ĵĿγ���Ŀ��");
    scanf("%d",&n);
    while(n--)
    {
        char s[10];
        int i;
        printf("��������Ҫ�޸ĵĿγ����ƣ�");
        scanf("%s",s);
        for(i=0;i<N;i++)
                  if((strcmp(s,cour[i].name))==0)break;

        printf("�������޸ĺ�Ŀγ���Ϣ���γ̱��� �γ����� ��ѧʱ ѧ��\n");
        scanf("%d %s%d%d",&cour[i].num,cour[i].name,&cour[i].hours,&cour[i].score);
    }
    printf("�޸����\n");
    printf("*******************************************************\n\n");

}
void dele()
{
    int n;
    printf("��������Ҫɾ���Ŀγ���Ŀ��");
    scanf("%d",&n);
    while(n--)
    {
        char s[10];
        int i,j;
        printf("��������Ҫɾ���Ŀγ����ƣ�");
        scanf("%s",s);
        for(i=0;i<N;i++)
            if((strcmp(s,cour[i].name))==0)break;
        for(j=i;j<N-1;j++)
            cour[j]=cour[j+1];
        N--;
    }
    printf("ɾ�����\n");
    printf("***************************************************************\n\n");
}
void print()
{
    int i;
    for(i=0;i<N;i++)
        printf("%d %s %d %d\n",cour[i].num,cour[i].name,cour[i].hours,cour[i].score);
    printf("**************************************************************\n\n");

}
void code1()
{
    printf("��������ĺ�����룺");
    scanf("%d",&CODE);
    printf("�����������\n");
    printf("**********************************************************\n\n");
}
void menu1()
{
   int n,m;
    while(1)
    {
       printf("   ���������Ա���룺    ");
       scanf("%d",&n);
       if(n!=CODE)printf("������󣡣�     \n");
       else
          while(1)
           {
              printf("     1:¼��γ���Ϣ\n");
              printf("     2:�޸Ŀγ���Ϣ\n");
              printf("     3:ɾ���γ���Ϣ\n");
              printf("     4:��ʾȫ���γ���Ϣ\n");
              printf("     5:���Ĺ���Ա����\n");
              printf("     0:�˳�����Ա����\n");
              scanf("%d",&m);
              if(m==0)break;
              switch(m)
               {
                 case 1:input();break;
                 case 2:change();break;
                 case 3:dele();break;
                 case 4:print();break;
                 case 5:code1();break;
               }
            }
       if(m==0)break;
    }
}
/*��������������������������������������������������������������������������������Сħ��*/



void search()
{
    int n;
    printf("����1���γ�����ѯ������2��ѧ�ֲ�ѯ\n");
    printf("�����룺");
    scanf("%d",&n);
    switch(n)
    {
        case 1:  while(1)
                {
                  char s[10];
                  int i;
                  printf("������γ�����ѯ(����0������ѯ����");
                  scanf("%s",s);
                  if(s[0]=='0')break;
                  for(i=0;i<N;i++)
                  if((strcmp(s,cour[i].name))==0)
                     printf("%d %s %d %d\n",cour[i].num,cour[i].name,cour[i].hours,cour[i].score);

                }
        case 2:  while(1)
                {
                  int i,m;
                  printf("������ѧ�ֲ�ѯ(����0������ѯ����");
                  scanf("%d",&m);
                  if(m==0)break;
                  for(i=0;i<N;i++)
                  if(m==cour[i].score)
                     printf("%d %s %d %d\n",cour[i].num,cour[i].name,cour[i].hours,cour[i].score);

                }
                break;
    }

}
void cmp1()/*��ѧʱ��������*/
{
    struct course temp;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N-i;j++)
    {
        if(cour[j].hours<cour[j+1].hours)
        {
            temp=cour[j];
            cour[j]=cour[j+1];
            cour[j+1]=temp;
        }
    }
}
void cmp2()/*��ѧʱ��������*/
{
    struct course temp;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N-i;j++)
    {
        if(cour[j].hours>cour[j+1].hours)
        {
            temp=cour[j];
            cour[j]=cour[j+1];
            cour[j+1]=temp;
        }
    }
}
void cmp3()/*��ѧ����������*/
{
    struct course temp;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N-i;j++)
    {
        if(cour[j].score<cour[j+1].score)
        {
            temp=cour[j];
            cour[j]=cour[j+1];
            cour[j+1]=temp;
        }
    }
}
void cmp4()/*��ѧ�ֽ�������*/
{
    struct course temp;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N-i;j++)
    {
        if(cour[j].score>cour[j+1].score)
        {
            temp=cour[j];
            cour[j]=cour[j+1];
            cour[j+1]=temp;
        }
    }
}
void menu2()
{
    int n;
    while(1)
    {
        printf("             1���������ѡ�޿γ�\n");
        printf("             2:����Ϣ��ѯ�γ�\n");
        printf("             3:\n");
        printf("             0:�˳�ѧ������ϵͳ\n");
        printf("              �����룺");
        scanf("%d",&n);
        if(n==0)break;
        switch(n)
        {
            case 1:print();break;
            case 2:search();break;
        }
    }
}


int main()
{

    int m;
    CODE=123456;
    while(1)
    {
    printf("           *********************************************************************           \n");
    printf("           *********************************************************************           \n");
    printf("           **                                                                 **           \n");
    printf("           **                                                                 **           \n");
    printf("           **                ��ӭʹ��ѧ��ѡ�޿γ�ϵͳ��                       **           \n");
    printf("           **                ������ǹ���Ա�������룺1                        **           \n");
    printf("           **                �������ѧ���������룺2                          **           \n");
    printf("           **                �˳�ϵͳ�������룺0                              **           \n");
    printf("           **                                                                 **           \n");
    printf("           **                                                                 **           \n");
    printf("           *********************************************************************           \n");
    printf("           *********************************************************************           \n");
    printf("             �����룺\n");
    scanf("%d",&m);
    if(m==0)break;
        switch(m)
        {
           case 1:menu1();break;
           case 2:menu2();break;
        }
    }

    return 0;
}
