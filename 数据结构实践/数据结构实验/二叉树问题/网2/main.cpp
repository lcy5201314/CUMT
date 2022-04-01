#include <iostream>
#include <cstring>
#define MAX 50+3
using namespace std;
typedef char Elem_Type;
typedef struct BiTree
{
    Elem_Type data;//数据
    struct BiTree *Lchild;//左孩子
    struct BiTree *Rchild;//右孩子
}BiTree;      //要查找的元素  查找的地方    数组的长度
int Search_Num(Elem_Type num,Elem_Type *array,int len)
{
    for(int i=0; i<len; i++)
       if(array[i] == num)
         return i;
    //return -1;//没有找到
}                     //前序遍历         中序遍历   中序数组长度
BiTree *Resume_BiTree(Elem_Type *front,Elem_Type *center,int len)
{
    if(len <= 0)
      return NULL;
    BiTree *temp = new BiTree;
    temp->data = *front;
    int index = Search_Num(*front,center,len);
    temp->Lchild = Resume_BiTree(front+1,center,index);
    temp->Rchild = Resume_BiTree(front+index+1,center+index+1,len-index-1);
    return temp;
}
void PostOrderTraverse(BiTree *root)//后序遍历
{
    if( root != NULL)
    {
        PostOrderTraverse(root->Lchild);
        PostOrderTraverse(root->Rchild);
        cout<<root->data;
    }
}
int main(void)
{
    Elem_Type *preorder = new Elem_Type [MAX];//前序
    Elem_Type *inorder  = new Elem_Type [MAX];//中序
    cin>>preorder;cin>>inorder;
    BiTree *root = Resume_BiTree(preorder,inorder,strlen(inorder));
    PostOrderTraverse(root);
    cout<<endl;
    return 0;
}
