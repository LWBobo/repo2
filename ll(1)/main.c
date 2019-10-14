#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char A[20];/*分析栈*/
char B[20];/*剩余串*/
char v1[20]={'i','+','*','(',')','#'};/*终结符  */
char v2[20]={'E','G','T','S','F'};/*非终结符   */

int j=0,b=0,top=0,l,m,n;/*l为输入串长度 */
char ch,x;/*x为当前栈顶字符*/
int k=1,flag=0,finish=0;

typedef struct type/*产生式类型定义      */
{
char origin;/*大写字符  */
char array[5];/*产生式右边字符 */
int length;/*字符个数      */
}type;




void print()/*输出分析栈  */
 {
    int a;                 /*指针*/
    for(a=0;a<=top+1;a++)
        printf("%c",A[a]);
    printf("\t\t");
 }

void print1()/*输出剩余串*/
{
    int j;
    for(j=0;j<b;j++)
        printf(" ");
    for(j=b;j<=l;j++)
        printf("%c",B[j]);
    printf("\t\t\t");
}


int main(){
    type e,t,g,g1,s,s1,f,f1,cha;/*结构体变量  */
    type C[10][10];/*预测分析表
         */
      /*把文法产生式赋值结构体*/
    e.origin='E';
    strcpy(e.array,"TG");
    e.length=2;/*更改 length 赋值*/
    t.origin='T';
    strcpy(t.array,"FS");
    t.length=2;/*更改 length 赋值*/
    g.origin='G';
    strcpy(g.array,"+TG");
    g.length=3;/*更改 length 赋值*/
    g1.origin='G';
    g1.array[0]='^';
    g1.array[1]='\0';/*更改 字符串结束标志*/
    g1.length=1;/*更改 length 赋值*/
    s.origin='S';
    strcpy(s.array,"*FS");
    s.length=3;/*更改 length 赋值*/
    s1.origin='S';
    s1.array[0]='^';
    s1.array[1]='\0';/*更改 字符串结束标志*/
    s1.length=1;/*更改 length 赋值*/
    f.origin='F';
    strcpy(f.array,"(E)");
    f.length=3;/*更改 length 赋值*/
    f1.origin='F';
    f1.array[0]='i';
    f1.array[1]='\0';/*更改 字符串结束标志*/
    f1.length=1;/*更改 length 赋值*/

    for(m=0;m<=4;m++)/*初始化分析表*/
            for(n=0;n<=5;n++)
                C[m][n].origin='N';/*全部赋为空*/
       /*填充分析表*/
    C[0][0]=e;C[0][3]=e;
    C[1][1]=g;C[1][4]=g1;C[1][5]=g1;
    C[2][0]=t;C[2][3]=t;
    C[3][1]=s1;C[3][2]=s;C[3][4]=C[3][5]=s1;
    C[4][0]=f1;C[4][3]=f;




    printf("可输入的字符为\'i\',\'+\',\'*\',\'(\',\')\',\'#\'注意：以第一个\'#\'作为字符串结束:\n");
    do/*读入分析串*/{
        scanf("%c",&ch);
        if ((ch!='i') &&(ch!='+') &&(ch!='*')&&(ch!='(')&&(ch!=')')&&(ch!='#'))
        {
            printf("Error!输入串中有非法字符!\n");
            exit(1);
        }
        B[j]=ch;
        j++;
    }while(ch!='#');
    printf("对字符串的分析过程如下：\n");
    l=j;/*分析串长度*/
    ch=B[0];/*当前分析字符*/
    A[top]='#'; A[++top]='E';/*'#','E'进栈*/
    printf("步骤\t\t分析栈\t\t剩余字符\t\t所用产生式 \n");




    /*推导过程如下*/
    do
    {
        x=A[top--];/*x为当前栈顶字符*/
        printf("%d",k++);/*步骤序号*/
        printf("\t\t");
        for(j=0;j<=5;j++)/*判断是否为终结符*/
            if(x==v1[j])
            {
                flag=1;
                break;
            }
        if(flag==1)/*如果是终结符*/
        {
            if(x=='#')
            {
                if(ch=='#')
                {


                    finish=1;/*结束标记*/
                    print();/*更改 最后成功时对齐*/
                    print1();


                    printf("acc!\n");/*接受 */
                    printf("输入串符合该文法！\n");
                    getchar();
                    getchar();
                    exit(1);
                }
                else
                {
                    print();
                    print1();
                    printf("Error!\n");
                    printf("当前分析栈中是#，但是剩余串还有字符未匹配。\n");
                    printf("输入串不符合该文法！\n");
                    getchar();
                    getchar();
                    exit(0);
                }
            }
            if(x==ch)
            {
                print();
                print1();
                printf("%c匹配\n",ch);
                ch=B[++b];/*下一个输入字符*/
                flag=0;/*恢复标记*/
            }
            else
            {
                if(ch=='#')
                {
                    print();
                    print1();
                    printf("Error!\n");
                    printf("剩余串中是#，但是分析栈还有字符未匹配。\n");
                    printf("输入串不符合该文法！\n");
                    getchar();
                    getchar();
                    exit(0);
                }
                else
                {
                    print();
                    print1();
                    printf("Error!%c匹配出错\n",ch);/*输出出错终结符*/
                    printf("与当前输入字符不匹配！\n");
                    printf("输入串不符合该文法！\n");
                    getchar();
                    getchar();
                    exit(1);
                }
            }
        }
        else/*非终结符处理*/
        {
            for(j=0;j<=4;j++)
                if(x==v2[j])
                {
                    m=j;/*行号*/
                    break;
                }
            for(j=0;j<=5;j++)
                if(ch==v1[j])
                {
                    n=j;/*列号*/
                    break;
                }
            cha=C[m][n];/*记录应用的产生式*/
            if(cha.origin!='N')
            {
                print();
                print1();
                printf("%c->",cha.origin);
                for(j=0;j<cha.length;j++)
                    printf("%c",cha.array[j]);
                printf("\n");
                for(j=(cha.length-1);j>=0;j--)
                {
                    A[++top]=cha.array[j];
                    if(A[top]=='^')/*为空则不进栈*/
                    top--;
                }
            }
            else
            {
                print();
                print1();
                printf("Error!\n");
                printf("当前栈顶元素是非终结符，但是找不到当前输入字符相应的产生式！\n");
                printf("输入串不符合该文法！\n");
                getchar();
                    getchar();
                exit(0);
            }
        }
    }while(1);
    return 0;
}
