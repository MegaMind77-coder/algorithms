#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct List //adjacency list
{
  int i;
  float w; //weighted list
  struct List *next;
};

struct EdgeList //edge list
{
  int i, j;
  float w;
  struct EdgeList *next;
};

struct EdgeList *newedgelist (struct EdgeList *node, int i, int j, float w)
{
  struct EdgeList *temp = (struct EdgeList *) malloc (sizeof (struct EdgeList));
  temp->i = i;
  temp->j = j;
  temp->w = w;
  temp->next = node;
  return temp;
}

struct List *newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void BellmanFord (struct EdgeList *elist, float SD[], int s, int n)
{
    struct EdgeList *temp;
    int i;
    for (i = 0; i < n; ++i){
        SD[i] = INT_MAX;
    }
    SD[s] = 0;

    for (i = 0; i < n; ++i){
        temp = elist;
        while (temp){
            if (SD[temp->j] > SD[temp->i] + temp->w){
                SD[temp->j] = SD[temp->i] + temp->w;
            }
            temp = temp->next;
        }
    }

}

int main ()
{
    int i, n = 200, l, r, m = 0, j, k;
    float SD[1000];
    struct List *list[n], *temp;
    struct EdgeList *elist = NULL, *etemp;

    for (i = 0; i < n; ++i){
        for (k = 0; k < n / 10; ++k){
            j = rand () % n;
            elist = newedgelist (elist, i, j, (i + j) * 2.1234);
            ++m;
        }
    }

    BellmanFord(elist, SD, 0, n); 

    for(int i=0; i<200; i++){
        printf("%f ", SD[i]);
    }  

    return 0;
}
