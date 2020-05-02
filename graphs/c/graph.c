#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List //adjacency list
{
  int i;
  float w;
  struct List *next;
};

struct List *newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void BFS (struct List *list[], int s, int n)
{
    bool V[n]; //list of visited nodes
    int Phi[n], i;

    for (i = 0; i < n; ++i)
    {
    Phi[i] = -2;
    V[i] = false;
    }
    struct List *head = (struct List *) malloc (sizeof (struct List)); //queue
    head->i = s;
    head->next = NULL;

    V[s] = true;
    Phi[s] = -1;
    struct List *tail = head, *temp;
    while (head)
    {
        temp = list[head->i];
        while (temp)
        {
            if (!V[temp->i])
            {
                tail->next = (struct List *) malloc (sizeof (struct List));
                tail = tail->next;
                tail->i = temp->i;
                tail->next = NULL;
                V[temp->i] = true;
                Phi[temp->i] = head->i;
            }
            temp = temp->next;
        }
        head = head->next;
    }
    printf (" \n BFS from %d is\n", s);

    for (i = 0; i < n; ++i){
        printf ("(%d,%d)", Phi[i], i);
    }
}

void DFS (struct List *list[], int s, int n)
{
    bool V[n];
    int Phi[n], i;
    for (i = 0; i < n; ++i){
        Phi[i] = -2;
        V[i] = false;
    }
    struct List *head = (struct List *) malloc (sizeof (struct List)); //initializing stack
    head->i = s;
    head->next = NULL;
    Phi[s] = -1;
    struct List *temp, *t1, *h1;
    while (head){
        if (!V[head->i]){   
            V[head->i] = true;
            temp = list[head->i];

            if (temp){
                h1 = head;
                head = head->next;
                while (temp)
                {
                    if (!V[temp->i]){
                        head = newedge (head, temp->i, 0);
                        Phi[temp->i] = h1->i;
                    }
                    temp = temp->next;
                }
            }
            else{
                head = head->next;
            }
        }
        else{
            head = head->next;
        }
    }
    printf (" \n DFS Tree from %d is\n", s);
    for (i = 0; i < n; ++i){
        printf ("(%d,%d)", Phi[i], i);
    }
}

void MaxBottomupheapify (float H[], int HeaptoGraph[], int GraphToHeap[], int i)
{
    int p = (i - 1) / 2, t;
    float temp;
    while (p > -1)
    {
        if (H[i] > H[p])
        {
            temp = H[i];
            H[i] = H[p];
            H[p] = temp;

            t = HeaptoGraph[i];
            HeaptoGraph[i] = HeaptoGraph[p];
            HeaptoGraph[p] = t;

            GraphToHeap[HeaptoGraph[p]] = p;
            GraphToHeap[HeaptoGraph[i]] = i;
            i = p;
            p = (i - 1) / 2;
        }
        else{
            p = -1;
        }
    }
}

void MaxTopdownheapify (float H[], int HeaptoGraph[], int GraphToHeap[], int i, int n)
{
    int c, t;
    float temp;

    while (2 * i + 2 < n)
    {
      if (H[2 * i + 1] > H[2 * i + 2]){
          c = 2 * i + 1;
      }
      else{
          c = 2 * i + 2;
      }
      if (H[i] < H[c]){

	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = HeaptoGraph[i];
	  HeaptoGraph[i] = HeaptoGraph[c];
	  HeaptoGraph[c] = t;
	  GraphToHeap[HeaptoGraph[i]] = i;
	  GraphToHeap[HeaptoGraph[c]] = c;
	  i = c;
	}
      else{
          i = n;
      }
    }
    c = 2 * i + 1;
    if (c < n & H[i] < H[c]){

        temp = H[i];
        H[i] = H[c];
        H[c] = temp;
        t = HeaptoGraph[i];
        HeaptoGraph[i] = HeaptoGraph[c];
        HeaptoGraph[c] = t;

        GraphToHeap[HeaptoGraph[i]] = i;
        GraphToHeap[HeaptoGraph[c]] = c;
        i = c;

    }
}

void MaxAdd (float H[], int HeaptoGraph[], int GraphToHeap[], float X, int *n)
{
    H[*n] = X;
    HeaptoGraph[*n] = *n;
    GraphToHeap[HeaptoGraph[*n]] = *n;
    *n = *n + 1;

    MaxBottomupheapify (H, HeaptoGraph, GraphToHeap, *n - 1);
}

void DeleteMax (float H[], int HeaptoGraph[], int GraphToHeap[], int *n)
{
    int t1;
    float t;
    *n = *n - 1;
    t = H[0];
    H[0] = H[*n];
    H[*n] = t;
    t1 = HeaptoGraph[0];
    HeaptoGraph[0] = HeaptoGraph[*n];
    HeaptoGraph[*n] = t1;
    GraphToHeap[HeaptoGraph[0]] = 0;
    GraphToHeap[HeaptoGraph[*n]] = *n;
    MaxTopdownheapify (H, HeaptoGraph, GraphToHeap, 0, *n);
}

void MaxBuildHeap (float H[], int HeaptoGraph[], int GraphToHeap[], int n)
{
    int i = n / 2;
    while (i > -1)
    {
      MaxTopdownheapify (H, HeaptoGraph, GraphToHeap, HeaptoGraph[i--], n);
    }
}

void Bottomupheapify (float H[], int HeaptoGraph[], int GraphToHeap[], int i)
{
    int p = (i - 1) / 2, t;
    float temp;
    while (p > -1)
    {
        if (H[i] < H[p])
        {
            temp = H[i];
            H[i] = H[p];
            H[p] = temp;
            t = HeaptoGraph[i];
            HeaptoGraph[i] = HeaptoGraph[p];
            HeaptoGraph[p] = t;
            GraphToHeap[HeaptoGraph[i]] = i;
            GraphToHeap[HeaptoGraph[p]] = p;
            i = p;
            p = (i - 1) / 2;
        }

        else{
            p = -1;
        }
    }

}

void Topdownheapify (float H[], int HeapToGraph[], int GraphToHeap[], int i, int n)
{
    int c, t;
    float temp;

    while (2 * i + 2 < n)
    {

        if (H[2 * i + 1] < H[2 * i + 2]){
            c = 2 * i + 1;
        }
        else{
            c = 2 * i + 2;
        }
        if (H[i] > H[c])
        {
            temp = H[i];
            H[i] = H[c];
            H[c] = temp;
            t = HeapToGraph[i];
            HeapToGraph[i] = HeapToGraph[c];
            HeapToGraph[c] = t;
            GraphToHeap[HeapToGraph[c]] = c;
            GraphToHeap[HeapToGraph[i]] = i;
            i = c;
        }
        else{
            i = n;
        }
    }
    c = 2 * i + 1;
    if (c < n & H[i] > H[c])
    {
        temp = H[i];
        H[i] = H[c];
        H[c] = temp;
        t = HeapToGraph[i];
        HeapToGraph[i] = HeapToGraph[c];
        HeapToGraph[c] = t;

        GraphToHeap[HeapToGraph[c]] = c;
        GraphToHeap[HeapToGraph[i]] = i;
        i = c;
    }

}

void Add (float H[], int HeapToGraph[], int GraphToHeap[], float X, int *n)
{

  H[*n] = X;
  HeapToGraph[*n] = *n;
  GraphToHeap[HeapToGraph[*n]] = *n;
  *n = *n + 1;

  Bottomupheapify (H, HeapToGraph, GraphToHeap, *n - 1);
}

void DeleteMin (float H[], int HeapToGraph[], int GraphToHeap[], int *n)
{
  float t;
  int t1;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = HeapToGraph[0];
  HeapToGraph[0] = HeapToGraph[*n];
  HeapToGraph[*n] = t1;
  GraphToHeap[HeapToGraph[0]] = 0;
  GraphToHeap[HeapToGraph[*n]] = *n;
  Topdownheapify (H, HeapToGraph, GraphToHeap, 0, *n);
}

void BuildHeap (float H[], int HeapToGraph[], int GraphToHeap[], int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, HeapToGraph, GraphToHeap, i--, n);
    }
}

void DecreaseKey (float H[], int HeapToGraph[], int GraphToHeap[], int i, float X)
{
  H[i] = X;
  Bottomupheapify (H, HeapToGraph, GraphToHeap, i);
}

void IncreaseKey (float H[], int HeapToGraph[], int GraphToHeap[], int i, float X)
{
  H[i] = X;
  MaxBottomupheapify (H, HeapToGraph, GraphToHeap, i);
}

void Dijkstra (struct List *list[], int s, int n)
{
    int HeapToGraph[100000], GraphToHeap[100000];
    struct List *node;
    float H[100000]; //min heap
    int i, u, v, m = n;
    bool V[n]; //visited
    int Phi[n]; //parent graph_node 
    for (i = 0; i < n; ++i)
    {
        Phi[i] = -2;
        H[i] = INT_MAX;
        HeapToGraph[i] = i;
        GraphToHeap[i] = i;
        V[i] = false;
    }

    H[0] = 0;
    Phi[s] = -1;
    HeapToGraph[0] = s;
    HeapToGraph[s] = 0;

    GraphToHeap[0] = s;
    GraphToHeap[s] = 0;

    for (i = 0; i < n && H[0] < INT_MAX; ++i) //exactly n vertices deleted once 
    {
        u = HeapToGraph[0];
        V[u] = true;
        node = list[u];
        DeleteMin (H, HeapToGraph, GraphToHeap, &m);
        while (node)
        {
            v = node->i;
            if (!V[v] && H[GraphToHeap[v]] > H[GraphToHeap[u]] + node->w)
            {
                DecreaseKey (H, HeapToGraph, GraphToHeap, GraphToHeap[v], H[GraphToHeap[u]] + node->w);
                Phi[v] = u;
            }
            node = node->next;
        }
    }
    printf (" \n The shortest path from %d is\n", s);
    for (i = 0; i < n; ++i){
    printf (" %d %f %d", i, H[GraphToHeap[i]], Phi[i]);
    }
}

void PrimsMin (struct List *list[], int s, int n)
{
    int HeapToGraph[100000], GraphToHeap[100000];
    struct List *node;
    float H[100000], mst = 0;
    int i, u, v, m = n;
    bool V[n];
    int Phi[n];
    for (i = 0; i < n; ++i)
    {
        Phi[i] = -2;
        H[i] = INT_MAX;
        HeapToGraph[i] = i;
        GraphToHeap[i] = i;
        V[i] = false;
    }

    H[0] = 0;
    Phi[s] = -1;
    HeapToGraph[0] = s;
    HeapToGraph[s] = 0;
    GraphToHeap[0] = s;
    GraphToHeap[s] = 0;

    for (i = 0; i < n && H[0] < INT_MAX; ++i)
    {
        u = HeapToGraph[0];
        V[u] = true;
        node = list[u];
        DeleteMin (H, HeapToGraph, GraphToHeap, &m);
        while (node)
        {
        v = node->i;
            if (!V[v] && H[B[v]] > node->w)
            {
                DecreaseKey (H, HeapToGraph, GraphToHeap, GraphToHeap[v], node->w);
                Phi[v] = u;
            }
        node = node->next;
        }
    }
    for (i = 0; i < n; ++i){
        mst += H[GraphToHeap[i]];
    }
    printf (" \n Minimim Spanning Tree is %f\n", mst);
    for (i = 0; i < n; ++i){
        printf (" %d %f %d", i, H[B[i]], Phi[i]);
    }
}

void PrimsMax (struct List *list[], int s, int n)
{
    int HeapToGraph[100000], GraphToHeap[100000];
    struct List *node;
    float H[100000], mst = 0;
    int i, u, v, m = n;
    bool V[n];
    int Phi[n];
    for (i = 0; i < n; ++i)
    {
        Phi[i] = -2;
        H[i] = INT_MIN;
        HeapToGraph[i] = i;
        GraphToHeap[i] = i;
        V[i] = false;
    }

    H[0] = 0;
    Phi[s] = -1;
    HeapToGraph[0] = s;
    HeapToGraph[s] = 0;
    GraphToHeap[0] = s;
    GraphToHeap[s] = 0;
    for (i = 0; i < n && H[0] > INT_MIN; ++i){
        u = HeapToGraph[0];
        V[u] = true;
        node = list[u];
        DeleteMax (H, HeapToGraph, GraphToHeap, &m);
        while (node){
        v = node->i;
        if (!V[v] && H[GraphToHeap[v]] < node->w){
            IncreaseKey (H, HeapToGraph, GraphToHeap, GraphToHeap[v], node->w);
            Phi[v] = u;
            }
        node = node->next;
        }
    }
    for (i = 0; i < n; ++i){
    mst += H[GraphToHeap[i]];
    }
    printf (" \n Maximum Spanning Tree is %f\n", mst);
    for (i = 0; i < n; ++i){
        printf (" %d %f %d", i, H[GraphToHeap[i]], Phi[i]);
    }
}

int main ()
{
  int A[100000], B[100000], n = 6, m, i, j, k;
  float H[100000];
  bool AM[1000][1000];


  struct List *list[n], *temp, *list1[n];
  for (i = 0; i < n; ++i)
    list[i] = NULL;
  for (i = 0; i < n; ++i)
    for (k = 0; k < n / 2; ++k)
      {
	j = rand () % n;
	if (!AM[i][j] & i != j)
	  {
	    AM[i][j] = true;
	    list[i] = newedge (list[i], j, i * j * 2.23 + 1);
	    ++m;
	    printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  }
      }

  printf ("\n%d\n", m);
  Dijkstra (list, 0, n);
  BFS (list, 0, n);
  DFS (list, 0, n);
  printf ("\n%d\n", m);

  m = 0;
  for (i = 0; i < n; ++i)
    {
      j = rand () % n;
      while (j < n)
	{
	  if (i == j)
	    j++;
	  list1[i] = newedge (list1[i], j, i * j * 2.23 + 1);
	  list1[j] = newedge (list1[j], i, i * j * 2.23 + 1);

	  ++m;
	  printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  j += rand () % n + 1;
	}
    }
  printf ("\n%d\n", m);
  Dijkstra (list1, 0, n);
  PrimsMin (list1, 0, n);
  PrimsMax (list1, 0, n);

  return 0;
}
