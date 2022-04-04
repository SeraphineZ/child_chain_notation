#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 20
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int TElemType;
typedef int Status;
#define OK 1

//--------------树的孩子链表存储表示----------------------
typedef struct CTNode{
    //孩子节点
    int child;
    struct CTNode* next;
}*ChildPtr;

typedef struct {
    TElemType data;
    ChildPtr firstchild;//孩子链表头指针
}CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;    //结点数和根的位置
}CTree;

Status CreateTree(CTree &T){
    //构建一棵树
    cout<<"请输入结点数以及根结点的位置下标："<<endl;
    cin>>T.n>>T.r;
    cout<<"请输入各结点的值："<<endl;
    for(int i=0;i<T.n;++i){
        cin>>T.nodes[i].data;
        T.nodes[i].firstchild=NULL;
    }
    cout<<"创建每个结点的孩子结点...\n";
    for(int i=0;i<T.n;++i){
        printf("请输入位置为%d的结点的孩子个数（>=0）,有孩子则输入孩子们的位置：\n",i);
        int nChild=0;
        cin>>nChild;
        ChildPtr  p=NULL;   //p指向插入孩子的前一个位置
        ChildPtr  q=NULL;   //q用于提示即将插入的新b孩子链表结点
        for(int j=0;j<nChild;++j){
            q=new CTNode;   //为孩子的位置开辟一个空间
            if(!q)
                exit(OVERFLOW);
            cin>>q->child;  //将孩子链表结点置入位置值
            q->next=NULL;
            if(j==0)    //将孩子链表头结点指向孩子链表第一个结点
                T.nodes[i].firstchild=q;
            else
                p->next=q;
            p=q;
        }
    }
    return OK;
}

Status PrintChild(const ChildPtr &C)
{//打印出结点的孩子
    if(C)
    {
        ChildPtr p;
        p = C;
        while(p)
        {
            printf("%d ->",p->child);
            p = p->next;
        }
        printf("NULL");
        return TRUE;
    }
    else
    {
        printf("NULL");
        return FALSE;
    }

}

void PrintChildTree(const CTree &T)//输出树的结点及他们的孩子
{
    printf("\n位置%d为树的根%d\n\n", T.r, T.nodes[T.r].data);
    for(int i = 0; i < T.n; ++i)
    {
        printf("位置%d,结点值%d ->", i, T.nodes[i].data);
        PrintChild(T.nodes[i].firstchild);
        printf("\n");

    }
}

Status FindChildOfNode(const CTree &T, TElemType e)//找结点e的孩子
{
    for(int i = 0; i < T.n; i++)
    {
        if(T.nodes[i].data == e)
        {
            printf("结点%d ->",e);
            PrintChild(T.nodes[i].firstchild);
            printf("\n");
            return TRUE;
        }
    }
    printf("无此结点\n");
    return FALSE;
}

int main()  //测试
{
    CTree T;
    CreateTree(T);
    PrintChildTree(T);
    while(1)
    {
        int data;
        printf("请输入你要查找其孩子的结点\n");
        scanf("%d",&data);
        FindChildOfNode(T,data);
        system("pause");
    }
    return 0;
}