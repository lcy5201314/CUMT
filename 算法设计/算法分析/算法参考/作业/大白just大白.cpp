/*���� I: ���just���
��Ŀ����
��Ҷ�֪������׶�ѧ��Ҫ���Ǻ��ϸ�ġ�����ҵ����������������ڴ�����ֱ�����̡�

�ⲻ�ոչ�ȥ����ĩ���ԡ���n��ѧ��������������⡣

��׸����������Ļ��ᣬÿ��ѧ�������ύһ�����֣���Ϊ������ɡ����Ǵ�׷����������ܻ���һЩ��ֵ����ɡ�

�����ǰ����m��������ڹؼ��֡����뿴��������ѧ�������õ����������ʲô��

��ν����������ɾ��ǣ��������г�����ڹؼ������ġ�

���йؼ��֣�ָ���ǣ������г�����һ���͹ؼ�����ȫƥ����ַ�����������ִ�дСд��ͬ��Ҳ��Ϊƥ�䡣���磬�ؼ����� bed 
�����г���Bedroom�㺬��һ���ؼ��֡�

����
һ����������ж��case��ÿ��case��һ�����������ֱ����n �� m

������m�У�ÿ��һ���ؼ��֣��ַ�����

�ٽ�����n���ַ�����m��n��������20

ÿһ����ںͽ�ڹؼ���ֻ�������Сд��ĸ�����Ȳ��ᳬ��4000���ַ���

���
����ÿ��case���һ���ַ�������ʾ���õ����ɡ����ж�����ɰ�����ͬ��Ŀ�Ĺؼ��֣�������˳�������ǰ���Ǹ���

��������
2 3
love
cumt
ACM
ILoveCUMTACM
cumtAACM
2 2
A
b
Ab
bA
�������
ILoveCUMTACM
Ab
����
m���ؼ��ʣ�n����ڣ��ҳ��������Ӵ����ؼ����������Ľ�ڡ���0<=n,m<=20,�ؼ��ʡ���ڳ���L<=4e4����ע�ⲻ���ִ�Сд��

˼·
���԰�������ģʽ����ת��ȫ��д����ȫСд����

ע�⣬����Ҫ���ԭ���Ĵ���������������Ҫ����ԭ�塣

ʵ�ֿ���string���µ�find()������

����*/
#include<iostream>
#include<string>
using namespace std;
const int MAXN = 21;
int main()
{
    int n,m,i,j;
    string text[MAXN],pattern[MAXN];
    string texx[MAXN],patterr[MAXN];
    while(~scanf("%d %d",&n,&m))
    {
        for(i = 0; i < m; i++)
        {
            cin>>pattern[i];
            patterr[i] = pattern[i];
            for(j = 0; patterr[i][j] != '\0'; j++)
            {
                if(islower(patterr[i][j])) patterr[i][j] = patterr[i][j]+'A'-'a';
            }
            //cout<<patterr[i]<<endl;
        }
        for(i = 0; i < n; i++)
        {
            cin>>text[i];
            texx[i] = text[i];
            for(j = 0; texx[i][j] != '\0'; j++)
            {
                if(islower(texx[i][j])) toupper(texx[i][j]);
            }
            //cout<<texx[i]<<endl;
        }
        int maxx = -1,maxt = -1,cur;
        for(i = 0; i < n; i++)
        {
            cur = 0;
            for(j = 0; j < m; j++)
            {
                string::size_type idx = texx[i].find(patterr[j]);
                if(idx != string::npos) cur++;
            }
            if(cur > maxx)
            {
                maxx = cur;
                maxt = i;
            }
        }
        cout<<text[maxt]<<endl;
    }
    return 0;
}
