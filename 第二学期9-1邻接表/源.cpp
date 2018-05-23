#include<iostream>
#include<vector>
using namespace std;
struct ArcNode
{
	int adjvex;
	int weight;
	ArcNode * nextarc;
};

struct VertexNode
{
	int Vertex;
	ArcNode * firstarc;
};
template<class T>class ALGraph
{
public:
	ALGraph(T a[], int n, int e);//���캯��
	ALGraph(T a[], int n);//���캯��
//	~ALGraph();//��������
	void Print(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << adjlist[i].Vertex << "-> ";
			ArcNode *p= adjlist[i].firstarc;
			while (p)
			{
				cout << p->adjvex<<"->";
				p = p->nextarc;
			}
			cout << endl;
		}
	}
	void DFS(int v);//������ȱ���
	void BFS(int v);//������ȱ���
	void ClearBool()
	{
		for(int i=0;i<100;i++)
		visited[i] =  false ;
	}
private:
	VertexNode * adjlist;//�ڵ�
	int vNum, arcNum;//������Ŀ�ͻ���Ŀ
	bool visited[100] = { false };
};

template<class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	adjlist = new VertexNode[n];
	int i, j, k;
	vNum = n;
	arcNum = e;
	for (k = 0; k < n; k++)
	{
		adjlist[k].Vertex = a[k];//��ʼ���ڵ�
		adjlist[k].firstarc = NULL;//��ʼ����
	}
	for (int k = 0; k < e; k++)
	{
		cin >> i >> j;//���붥��ͱߵ�Ȩֵ
		ArcNode * s = new ArcNode;
		s->adjvex =j;
		s->nextarc = adjlist[i].firstarc;//ͷ�巨
		adjlist[i].firstarc = s;
	}
}

template<class T>
ALGraph<T>::ALGraph(T a[], int n)
{
	int ad;
	adjlist = new VertexNode[n];
	for (int k = 0; k < n; k++)
	{
		adjlist[k].Vertex = a[k];//��ʼ���ڵ�
		adjlist[k].firstarc = NULL;//��ʼ����
	}
	for (int i = 0; i < n; i++)
	{
		vector<T> row;
		for (int l = 0; l < n; l++)
		{
			T temp;
			cin >> temp;
			row.push_back(temp);
		}
		for (int j = n-1; j >= 0; j--)
		{
			ad=row[j];
			if (ad == 0)
			{

			}
			else
			{
				ArcNode * s = new ArcNode;
				s->adjvex = j;
				s->nextarc = adjlist[i].firstarc;//β�巨
				adjlist[i].firstarc = s;
			}
			
		}
	}
}

template<class T>
void ALGraph<T>::DFS(int v)
{
	if (v == 0)
		cout << adjlist[v].Vertex;
	else
		cout << " " << adjlist[v].Vertex;
	visited[v] = true;
	ArcNode * p = adjlist[v].firstarc;
	while (p)
	{
		int j = p->adjvex;
		if (!visited[j])
			DFS(j);
		p = p->nextarc;
	}
}

template<class T>
void ALGraph<T>::BFS(int v)
{
	int queue[100];//����һ���ն���
	int f = 0;
	int r = 0;
	cout << adjlist[v].Vertex ;
	visited[v] = true;
	queue[++r] = v;//v���
	while (f != r)
	{
		v = queue[++f];//��ͷԪ�س���
		ArcNode * p = adjlist[v].firstarc;
		while (p)
		{
			int j = p->adjvex;
			if (!visited[j])
			{
				cout << " " <<adjlist[j].Vertex;
				visited[j] = true;
				queue[++r] = j;//j���
			}
			p = p->nextarc;
		}
	}

}

int main()
{
	int size;
	cin >> size;
	int * a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = i;
	ALGraph<int> Me(a, size);
//	Me.Print(size);
	Me.DFS(0);
	Me.ClearBool();
	cout << endl;
	Me.BFS(0);
//	system("pause");
	return 0;
}
