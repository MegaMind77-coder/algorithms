#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define PRIME 100003
#define MAX 100000

struct node{ // struct of node stored inside hashtable 
    int count, index; //stores count, and first index of substring
    struct node* next; // pointer to the next node
};

void insert(struct node** root, int index)  // insert function takes pointer to pointer of root node as argument, and inserts the node at
//the beggining of the linked list
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->index = index;
    new->count = 1;
    new->next = (*root);
    (*root) = new;
}

int Count(struct node* hashtable[], char* string, int k, int check_len, int hashvalue,  int i)//function to check for substring match and updating
//count of the substring in the hashtable, it also returns the updated count to check if the value has reached k
{
   // struct node* temp = hashtable[hashvalue];
    int count = -1;
    int len = 0; 
    while(hashtable[hashvalue] != NULL)// moves to end of all the nodes inserted into the hashtable, until a match is found
    {
        for(int j = 0; j<check_len; j++)
        {
            if(string[i+j] != string[hashtable[hashvalue]->index + j]) // checks if every character is equal
            {
                break;
            }
            else
                len++;
        }
        if(len == check_len) // if len equals the length to found it means a match has been found
        {
            hashtable[hashvalue]->count++; // if match found it incremets the count
            count = hashtable[hashvalue]->count; // stores count
            break;
        }
        len = 0;
        hashtable[hashvalue] = hashtable[hashvalue]->next; //if no match found
    }
   // hashtable[hashvalue] = temp; 
    return count;
}


bool check(struct node* hashtable[], char* string, int check_len, int k)//function to check if there exists a string of length check_len,
// that occurs atleast k times
{
    int hashvalue = (string[0]-'0');//stores the hashvalue
    int pow = 2;	//power variable used in rolling hash
    int len = strlen(string); //length of string, and check_len is the length of the substrings which would satisfy the property of occuring k times
    
    for(int i = 1; i<check_len; i++)
    {
        hashvalue = (2*hashvalue + (string[i]-'0'))%PRIME;
        pow *= 2;
    }
    insert(&hashtable[hashvalue], 0); // hashvalue of the first substing of length checkz_len is calculated and it is then inserted in the hatable, with count = 1

    for(int i = 1; i< len-check_len+1; i++)
    {
        hashvalue = (2*hashvalue + (string[i+check_len-1]-'0') - (pow*(string[i-1]-'0'))) % PRIME; // rolling hashfunction calculates slide the window and
        //calculates the hashvalue of the next substring of the same length
        
        if (hashvalue < 0)
            hashvalue += PRIME; 

        if(hashtable[hashvalue] == NULL) //if no substring exists with the same hashvalue, it is inserted into the hashtable
            insert(&hashtable[hashvalue], i);
        else
        {
            if(Count(hashtable, string, k, check_len, hashvalue, i) == k) // else if a string with the same hashvalue already exists,
                //we check if the substring matches the string already stored, if matches we update count and check it its k, if so we break out
                // and return true
                return true;
        }                
    }
    // if the loop doesn't return true anywhere it means that all substrings have been inserted, and no substring has reached a count of k
    return false;
}


int max_len(char* string, int k, int left, int right)
{
    struct node* hashtable[2*MAX] = {NULL}; // inistializes an empty hashtable for every function call
    int mid = (left+right)/2; // basically, we do binary search to find the max length,
    // we start the binary search and check for the mid length, if it occurs k times we check for a greater length else for a smaller length

    if(left < right) // binary search exit condition when left and right pointer do not coincide 
    {
        if(check(hashtable, string, mid, k)) //if there exits a substring of length mid that occurs atleast k times
            return max_len(string, k, mid+1, right); //we do binary search for left pointer moved ahead, since length mid atisfies the prop
        else
            return max_len(string, k, left, mid-1); //else we slide the window behind, by changing the right pointer moved behind
    }
    else //if binary search has ended it means left and right pointer hav crossed each other
    {
        if(check(hashtable, string, mid, k)) //we then chk if len =  mid satisfies and return it 
            return mid;
        else
            return mid-1; // else we return mid -1 
    } 

}

int main()
{
    char* string = (char *)malloc(MAX*sizeof(char));
    scanf("%s",string);

    int len = strlen(string);
    int k;
    scanf("%d",&k);
    
    int max = max_len(string, k, 0, len-1);
    printf("%d",max);

    return 0;
}