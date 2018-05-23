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
	ALGraph(T a[], int n, int e);//构造函数
	ALGraph(T a[], int n);//构造函数
//	~ALGraph();//析构函数
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
	void DFS(int v);//深度优先遍历
	void BFS(int v);//广度优先遍历
	void ClearBool()
	{
		for(int i=0;i<100;i++)
		visited[i] =  false ;
	}
private:
	VertexNode * adjlist;//节点
	int vNum, arcNum;//顶点数目和弧数目
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
		adjlist[k].Vertex = a[k];//初始化节点
		adjlist[k].firstarc = NULL;//初始化弧
	}
	for (int k = 0; k < e; k++)
	{
		cin >> i >> j;//输入顶点和边的权值
		ArcNode * s = new ArcNode;
		s->adjvex =j;
		s->nextarc = adjlist[i].firstarc;//头插法
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
		adjlist[k].Vertex = a[k];//初始化节点
		adjlist[k].firstarc = NULL;//初始化弧
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
				s->nextarc = adjlist[i].firstarc;//尾插法
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
	int queue[100];//生成一个空队列
	int f = 0;
	int r = 0;
	cout << adjlist[v].Vertex ;
	visited[v] = true;
	queue[++r] = v;//v入队
	while (f != r)
	{
		v = queue[++f];//队头元素出队
		ArcNode * p = adjlist[v].firstarc;
		while (p)
		{
			int j = p->adjvex;
			if (!visited[j])
			{
				cout << " " <<adjlist[j].Vertex;
				visited[j] = true;
				queue[++r] = j;//j入队
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
