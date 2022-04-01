#include <cstdio>
#include <cstdlib>
#include <queue>
 
using namespace std;
 
const int maxx = 52;
 
typedef struct Tree{
	Tree *le;
	Tree *ri;
	char data;
}Tree;
 
Tree *root;
 
char pre[maxx],in[maxx];
 
 
int Height(Tree *root,int height){
	if(root==NULL)return height;
	int lheight = Height(root->le,height+1);
	int rheight = Height(root->ri,height+1);
	return lheight>rheight?lheight:rheight;
}
 
Tree *buildTree(int pl,int pr,int il,int ir){
	if(pl>pr)return NULL;
	int p = il;
	while(in[p]!=pre[pl])++p;
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->data = pre[pl];
	tree->le = buildTree(pl+1,pl+p-il,il,p-1);
	tree->ri = buildTree(pl+p-il+1,pr,p+1,ir);
	return tree;
}
 
void printPre(Tree *root){
	if(root==NULL)return;
	printf("%d ",root->data);
	printPre(root->le);
	printPre(root->ri);
}
 
int main(){
	int n,i,height;
	Tree *root;
 
	while(scanf("%d%*c",&n)!=EOF){
		for(i=0;i<n;++i){
			scanf("%c",&pre[i]);
		}
		scanf("%*c");
		for(i=0;i<n;++i){
			scanf("%c",&in[i]);
		}
		root=buildTree(0,n-1,0,n-1);	
		height = Height(root,0);
		printf("%d\n",height);
	}
	return 0;
}

