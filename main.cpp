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


/*管理员界面*************************************************************************************************/
void input()
{
    int i;
    printf("请输入录入课程数目：");
    scanf("%d",&N);
    printf("请输入：课程编码 课程名称 总学时 学分\n");
    for(i=0;i<N;i++)
    scanf("%d %s%d%d",&cour[i].num,cour[i].name,&cour[i].hours,&cour[i].score);
    printf("录入完毕\n");
    printf("*********************************************\n\n");
}
void change()/*需修改，加一个报错*/
{
    int n;
    printf("请输入需要修改的课程数目：");
    scanf("%d",&n);
    while(n--)
    {
        char s[10];
        int i;
        printf("请输入需要修改的课程名称：");
        scanf("%s",s);
        for(i=0;i<N;i++)
                  if((strcmp(s,cour[i].name))==0)break;

        printf("请输入修改后的课程信息：课程编码 课程名称 总学时 学分\n");
        scanf("%d %s%d%d",&cour[i].num,cour[i].name,&cour[i].hours,&cour[i].score);
    }
    printf("修改完毕\n");
    printf("*******************************************************\n\n");

}
void dele()
{
    int n;
    printf("请输入需要删除的课程数目：");
    scanf("%d",&n);
    while(n--)
    {
        char s[10];
        int i,j;
        printf("请输入需要删除的课程名称：");
        scanf("%s",s);
        for(i=0;i<N;i++)
            if((strcmp(s,cour[i].name))==0)break;
        for(j=i;j<N-1;j++)
            cour[j]=cour[j+1];
        N--;
    }
    printf("删除完毕\n");
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
    printf("请输入更改后的密码：");
    scanf("%d",&CODE);
    printf("更改密码完毕\n");
    printf("**********************************************************\n\n");
}
void menu1()
{
   int n,m;
    while(1)
    {
       printf("   请输入管理员密码：    ");
       scanf("%d",&n);
       if(n!=CODE)printf("密码错误！！     \n");
       else
          while(1)
           {
              printf("     1:录入课程信息\n");
              printf("     2:修改课程信息\n");
              printf("     3:删除课程信息\n");
              printf("     4:显示全部课程信息\n");
              printf("     5:更改管理员密码\n");
              printf("     0:退出管理员界面\n");
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
/*巴啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦小魔仙*/



void search()
{
    int n;
    printf("输入1按课程名查询，输入2按学分查询\n");
    printf("请输入：");
    scanf("%d",&n);
    switch(n)
    {
        case 1:  while(1)
                {
                  char s[10];
                  int i;
                  printf("请输入课程名查询(输入0结束查询）：");
                  scanf("%s",s);
                  if(s[0]=='0')break;
                  for(i=0;i<N;i++)
                  if((strcmp(s,cour[i].name))==0)
                     printf("%d %s %d %d\n",cour[i].num,cour[i].name,cour[i].hours,cour[i].score);

                }
        case 2:  while(1)
                {
                  int i,m;
                  printf("请输入学分查询(输入0结束查询）：");
                  scanf("%d",&m);
                  if(m==0)break;
                  for(i=0;i<N;i++)
                  if(m==cour[i].score)
                     printf("%d %s %d %d\n",cour[i].num,cour[i].name,cour[i].hours,cour[i].score);

                }
                break;
    }

}
void cmp1()/*按学时升序排序*/
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
void cmp2()/*按学时降序排序*/
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
void cmp3()/*按学分升序排序*/
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
void cmp4()/*按学分降序排序*/
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
        printf("             1：浏览所有选修课程\n");
        printf("             2:按信息查询课程\n");
        printf("             3:\n");
        printf("             0:退出学生管理系统\n");
        printf("              请输入：");
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
    printf("           **                欢迎使用学生选修课程系统！                       **           \n");
    printf("           **                如果您是管理员，请输入：1                        **           \n");
    printf("           **                如果您是学生，请输入：2                          **           \n");
    printf("           **                退出系统，请输入：0                              **           \n");
    printf("           **                                                                 **           \n");
    printf("           **                                                                 **           \n");
    printf("           *********************************************************************           \n");
    printf("           *********************************************************************           \n");
    printf("             请输入：\n");
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
