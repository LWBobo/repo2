#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char A[20];/*����ջ*/
char B[20];/*ʣ�മ*/
char v1[20]={'i','+','*','(',')','#'};/*�ս��  */
char v2[20]={'E','G','T','S','F'};/*���ս��   */

int j=0,b=0,top=0,l,m,n;/*lΪ���봮���� */
char ch,x;/*xΪ��ǰջ���ַ�*/
int k=1,flag=0,finish=0;

typedef struct type/*����ʽ���Ͷ���      */
{
char origin;/*��д�ַ�  */
char array[5];/*����ʽ�ұ��ַ� */
int length;/*�ַ�����      */
}type;




void print()/*�������ջ  */
 {
    int a;                 /*ָ��*/
    for(a=0;a<=top+1;a++)
        printf("%c",A[a]);
    printf("\t\t");
 }

void print1()/*���ʣ�മ*/
{
    int j;
    for(j=0;j<b;j++)
        printf(" ");
    for(j=b;j<=l;j++)
        printf("%c",B[j]);
    printf("\t\t\t");
}


int main(){
    type e,t,g,g1,s,s1,f,f1,cha;/*�ṹ�����  */
    type C[10][10];/*Ԥ�������
         */
      /*���ķ�����ʽ��ֵ�ṹ��*/
    e.origin='E';
    strcpy(e.array,"TG");
    e.length=2;/*���� length ��ֵ*/
    t.origin='T';
    strcpy(t.array,"FS");
    t.length=2;/*���� length ��ֵ*/
    g.origin='G';
    strcpy(g.array,"+TG");
    g.length=3;/*���� length ��ֵ*/
    g1.origin='G';
    g1.array[0]='^';
    g1.array[1]='\0';/*���� �ַ���������־*/
    g1.length=1;/*���� length ��ֵ*/
    s.origin='S';
    strcpy(s.array,"*FS");
    s.length=3;/*���� length ��ֵ*/
    s1.origin='S';
    s1.array[0]='^';
    s1.array[1]='\0';/*���� �ַ���������־*/
    s1.length=1;/*���� length ��ֵ*/
    f.origin='F';
    strcpy(f.array,"(E)");
    f.length=3;/*���� length ��ֵ*/
    f1.origin='F';
    f1.array[0]='i';
    f1.array[1]='\0';/*���� �ַ���������־*/
    f1.length=1;/*���� length ��ֵ*/

    for(m=0;m<=4;m++)/*��ʼ��������*/
            for(n=0;n<=5;n++)
                C[m][n].origin='N';/*ȫ����Ϊ��*/
       /*��������*/
    C[0][0]=e;C[0][3]=e;
    C[1][1]=g;C[1][4]=g1;C[1][5]=g1;
    C[2][0]=t;C[2][3]=t;
    C[3][1]=s1;C[3][2]=s;C[3][4]=C[3][5]=s1;
    C[4][0]=f1;C[4][3]=f;




    printf("��������ַ�Ϊ\'i\',\'+\',\'*\',\'(\',\')\',\'#\'ע�⣺�Ե�һ��\'#\'��Ϊ�ַ�������:\n");
    do/*���������*/{
        scanf("%c",&ch);
        if ((ch!='i') &&(ch!='+') &&(ch!='*')&&(ch!='(')&&(ch!=')')&&(ch!='#'))
        {
            printf("Error!���봮���зǷ��ַ�!\n");
            exit(1);
        }
        B[j]=ch;
        j++;
    }while(ch!='#');
    printf("���ַ����ķ����������£�\n");
    l=j;/*����������*/
    ch=B[0];/*��ǰ�����ַ�*/
    A[top]='#'; A[++top]='E';/*'#','E'��ջ*/
    printf("����\t\t����ջ\t\tʣ���ַ�\t\t���ò���ʽ \n");




    /*�Ƶ���������*/
    do
    {
        x=A[top--];/*xΪ��ǰջ���ַ�*/
        printf("%d",k++);/*�������*/
        printf("\t\t");
        for(j=0;j<=5;j++)/*�ж��Ƿ�Ϊ�ս��*/
            if(x==v1[j])
            {
                flag=1;
                break;
            }
        if(flag==1)/*������ս��*/
        {
            if(x=='#')
            {
                if(ch=='#')
                {


                    finish=1;/*�������*/
                    print();/*���� ���ɹ�ʱ����*/
                    print1();


                    printf("acc!\n");/*���� */
                    printf("���봮���ϸ��ķ���\n");
                    getchar();
                    getchar();
                    exit(1);
                }
                else
                {
                    print();
                    print1();
                    printf("Error!\n");
                    printf("��ǰ����ջ����#������ʣ�മ�����ַ�δƥ�䡣\n");
                    printf("���봮�����ϸ��ķ���\n");
                    getchar();
                    getchar();
                    exit(0);
                }
            }
            if(x==ch)
            {
                print();
                print1();
                printf("%cƥ��\n",ch);
                ch=B[++b];/*��һ�������ַ�*/
                flag=0;/*�ָ����*/
            }
            else
            {
                if(ch=='#')
                {
                    print();
                    print1();
                    printf("Error!\n");
                    printf("ʣ�മ����#�����Ƿ���ջ�����ַ�δƥ�䡣\n");
                    printf("���봮�����ϸ��ķ���\n");
                    getchar();
                    getchar();
                    exit(0);
                }
                else
                {
                    print();
                    print1();
                    printf("Error!%cƥ�����\n",ch);/*��������ս��*/
                    printf("�뵱ǰ�����ַ���ƥ�䣡\n");
                    printf("���봮�����ϸ��ķ���\n");
                    getchar();
                    getchar();
                    exit(1);
                }
            }
        }
        else/*���ս������*/
        {
            for(j=0;j<=4;j++)
                if(x==v2[j])
                {
                    m=j;/*�к�*/
                    break;
                }
            for(j=0;j<=5;j++)
                if(ch==v1[j])
                {
                    n=j;/*�к�*/
                    break;
                }
            cha=C[m][n];/*��¼Ӧ�õĲ���ʽ*/
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
                    if(A[top]=='^')/*Ϊ���򲻽�ջ*/
                    top--;
                }
            }
            else
            {
                print();
                print1();
                printf("Error!\n");
                printf("��ǰջ��Ԫ���Ƿ��ս���������Ҳ�����ǰ�����ַ���Ӧ�Ĳ���ʽ��\n");
                printf("���봮�����ϸ��ķ���\n");
                getchar();
                    getchar();
                exit(0);
            }
        }
    }while(1);
    return 0;
}
