#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

struct node
{
    ll val;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *CreateBBST(ll arr[], ll l, ll r){
    struct node *node = NULL;
    if(l <= r){
        ll mid = (l+r)/2;
        node = (struct node *)malloc(sizeof(struct node));
        node->val = arr[mid];
        node->left = CreateBBST(arr, l, mid-1);
        node->right = CreateBBST(arr, mid+1, r);
        if(node->left){
            node->left->parent = node;
        }
        if(node->right){
            node->right->parent = node;
        }
    }
    return node;
}

int main() {
    ll arr[] = {1,2,3,4,5,6,7,8};
    struct node *root = CreateBBST(arr, 0, 7);
    //printf("%lld", root->right->right->val);
    return 0;
}