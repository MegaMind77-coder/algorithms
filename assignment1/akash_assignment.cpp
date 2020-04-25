//this could also be done using segment trees however i use fenwick sine the code for fenwick is much shorter 
// we would construct a 2d segment teee there as well

#include<bits/stdc++.h>
#define MAX 100007

using namespace std;

int fenwick_tree[MAX][32]; //fenwich tree 2d in nature, each column corresponds to the an alphabet in the order 'a', 'b' .......

int num_of_char(int i, int j){ //j is the column number, this thus calculates the number of corresponding character between any tow indexes
    int sum = 0;
    while(i>0){ //normal fenwick tree traversal
        sum += fenwick_tree[i][j];
        i = i - (i&-i);
    }
    return sum;
}   //this function would return the number of characters between any two indices


void update(int idx1, int idx2, int n, int val ){ //changes the value stored in the fenwick tree of the corresponding column 
    while(idx1 <= n){
        fenwick_tree[idx1][idx2] += val;
        idx1 += (idx1 & -idx1);
    }
}

int main(){
    int n, queries;
    cin >> n >> queries; // number of queries
    string str;
    cin >> str;

    for(int i=0;i<n;i++){
        update(i+1, (int)(str[i])-96, n, 1); //we add all the element in the 2d tree, by finding the column number, and updating the cout at
        //index the corresponding in the fewick tree
    }



    int option, l, r, k, idx;
    char c;
    while(queries--){ //number of queries
        cin >> option;
        if(option == 1){
            cin >> l >> r >> k;
            int total_char = 0;//if a type of char causes it to surpass k, that means that it is the ans 
            int i;
            for(i=0; i<26; i++){//we start with 0 which reprsents 'a' 1 =' b and so on
                total_char += num_of_char(r,i) - num_of_char(l-1,i); // gives the number of characters corresponding to that column between any two indices
                if(total_char >= k) //if it crosses the reuired rank
                    break;
            }
            if(total_char >= k ){
                int num = 96 + i; //correspnding ascii char is determined 
                cout << (char)num << endl;
            }
            else{
                cout << "Out of range" << endl;
            }
        }
        else{
            cin >> idx >> c;
            update(idx, (int)(str[idx-1])-96, n, -1); //to update we first remove/reduce the count of the initial character in corresponding col
            update(idx, (int)(c)-96, n, 1); //then pdate count i column of new character 
            str[idx-1] = c;
        }
    }
    return 0;
}

//0(logn) solution 