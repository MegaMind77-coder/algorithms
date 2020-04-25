#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000
#define PRIME 1000007

struct node{ // structure of node stored in hashtable
    int key; //stores the value of the data, for example the number in the array
    int count; // stores the frequency of that particular key in the array
    int heap_idx; //stores the index of the correspoding frequecy in the freq_heap
    struct node *left; //doubly linked node element
    struct node *right;
};

struct heap{ //structure of element in frquency(maxheap)
    int freq; //stores frequency of key 
    struct node* point; // pointer to corresponding node in hashtable with that particular frequency
};

struct node *hashtable[2*MAX]; //global hashtable, array of struct pointer
struct heap freq_heap[MAX]; // array of structures, for frequency heap(MaxHeap)
int last_idx = 0;// this is the length of freq_heap which is zero, before any inserton


//returns pointer to new node to be inserted in hashtable
struct node *new_node(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->key = data;
    new->count = 1; // count is initialized to one
    new->heap_idx = MAX;
    new->left = NULL;
    new->right = NULL;
    return new;
}

//normal topdownheapify for frq_heap

void Topdownheapify(int node_idx){
    int rep = 0;//replacement index
    while(2*node_idx+2 < last_idx){
        if(freq_heap[2*node_idx+1].freq < freq_heap[2*node_idx+2].freq){
            rep = 2*node_idx + 2;
        }
        else{
            rep = 2*node_idx + 1;
        }
        if(freq_heap[node_idx].freq < freq_heap[rep].freq){
            struct heap temp = freq_heap[node_idx];
            freq_heap[node_idx] = freq_heap[rep];
            freq_heap[node_idx].point->heap_idx = node_idx; //also changes the corresponding heap_idx in the hashtable after every change in position
            //of the element in the freq_heap(element in hastable for corresponding frequency)
            freq_heap[rep] = temp;
            freq_heap[rep].point->heap_idx = rep;
            node_idx = rep;
        }
        else
        {
            break;
        }        
    }
}

// normal BottumupHeapify for the freq_heap,
//also takes care of changes in the heap_index and updates them in the corresponding node in the hashtable
void Bottomupheapify(int node_idx){
    int rep = (node_idx-1)/2;
    while(rep >= 0 && freq_heap[node_idx].freq > freq_heap[rep].freq ){
        struct heap temp = freq_heap[node_idx];
        freq_heap[node_idx] = freq_heap[rep];
        freq_heap[node_idx].point->heap_idx = node_idx;
        freq_heap[rep] = temp;
        freq_heap[rep].point->heap_idx = rep;
        node_idx = rep;
        rep = (node_idx-1)/2;
    }
}


// adds element to the heap, called after creating a node element in the hastable
void add_to_heap(struct node *point){
    freq_heap[last_idx].freq = point->count;
    freq_heap[last_idx].point = point;
    freq_heap[last_idx].point->heap_idx = last_idx; // updates heap_idx in the hashtable before bottumupheapify
    //increments the length of heap array
    last_idx+=1;
    Bottomupheapify(last_idx-1);//takes care of changes of heapindexes also
}


// called when the frequency of an element has to be updated after an already existing element is inserted into te hashtable
void update(int node_idx, int new_freq){
    if(freq_heap[node_idx].freq < new_freq){ //if the frequency has increased, we call bottumupheapify
        freq_heap[node_idx].freq = new_freq;
        Bottomupheapify(node_idx);        
    }

    else if(freq_heap[node_idx].freq > new_freq){ //else we call bottumup heapify
        freq_heap[node_idx].freq = new_freq;
        Topdownheapify(node_idx);      
    }
}


int hashvalue(int data){ //returns hashvalue of element to be inserted
    int hashvalue = data%PRIME;
    if (hashvalue <= 0)
    {
        hashvalue += data;
    }
    return hashvalue;
}


void add(int data){
    int hash = hashvalue(data);
    if(hashtable[hash] == NULL){ //checks if there is no element corresponding to the hashvalue, calls add_to_heap 
        struct node *new = new_node(data);
        hashtable[hash] = new;
        add_to_heap(hashtable[hash]);
    }
    else{
        struct node *temp = hashtable[hash];
        while(temp->key != data || temp->right!=NULL){ //otherwise we check if there is an element for the corresponding data, that is we look for the same key
        //if no match id found we add a corresponding element at the end of the heap
            temp = temp->right;
        }
        if(temp->key != data && temp->right == NULL){ //if it does not exist we add the elment
            struct node *new = new_node(data);
            temp->right = new;
            new->left = new;
            add_to_heap(new);
        }
        else if(temp->key == data){//if key is matched, we update the count in hashtable, and then update it in the heap
            temp->count+= 1;
            update(temp->heap_idx, temp->count);
        }
    }
}

void del_max_freq(){ // deletes the element with max heap
    int del_freq = freq_heap[0].freq;//since we need to delete all element wit the max heap, we store the max_frequency
    while(freq_heap[0].freq == del_freq){  //after deleting the element we check if the top of the heap after topdownheapify has the same frequency if so we reiterate
    //until top of the heap has different freq
        struct node *del_point = freq_heap[0].point;
        freq_heap[0].point = NULL;
        if(del_point->left == NULL && del_point->right == NULL){ //if it is the first element of the hashtable[hashvalue]  and there is no other elemnt,
        //we simply free the node
            free(del_point);
        }
        else if(del_point->left == NULL && del_point->right!=NULL)//pointer changes if the node is the head of the linked list, with other nodes linked
        //we need to change the head of the list and update the pointer in the heap
        {
            struct node *del = del_point;
            (del_point->right)->left = del_point->left;
            del_point = del_point->right;
            freq_heap[del_point->heap_idx].point = del_point;
            free(del);
        }
        else if (del_point->right == NULL && del_point->left!=NULL)// pointer changes if the node is the last element in the linked list
        {
            (del_point->left)->right = del_point->right;
            free(del_point);
        }
        else{ // pointer changes is it is the a middle element in the linked list
            struct node *del = del_point;
            (del_point->left)->right = del_point->right;
            (del_point->right)->left = del_point->left;
            free(del_point);
        }
        freq_heap[0] = freq_heap[last_idx-1];
        freq_heap[0].point->heap_idx = 0;
        last_idx-=1;// updating length of heap 
        Topdownheapify(0);
    }
}

int main(){

    int arr[] = {1,2,3,2,3,1,2,2,3,4,5,7,1};
    int size = sizeof(arr)/sizeof(int);
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
    del_max_freq();
    printf("%d",freq_heap[0].point->key);
    //2 occurs 4 times, 1 occurs 3 times hence,3 occurs 3 times, 1 comes on top of the heap, print statement proves the same
    //last_idx is the size of the heap before an insertion sorry it is litle misleading
    //printf("%d", freq_heap[0].point->key);
    return 0;
}