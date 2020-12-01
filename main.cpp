#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class TernaryTree{
private:
    Node *root;
    int leaf_count_h(Node *);
    int node_sum_h(Node *);

public:
    void construct_tree();
    void traverse_LMRW(int,  Node * );
    int leaf_count();
    int degree_one_nodes_count(Node *current, int i);
    int node_sum();


    TernaryTree() {
        root = NULL;
    }


};
void TernaryTree::construct_tree() {

}
void TernaryTree::traverse_LMRW(int A, Node * n) {
    if(A <= n->data) {
        if(n->left != NULL)
            traverse_LMRW(A, n->left);
        else {
            n->left=new Node;
            n->left->data=A;
            n->left->left = NULL;
            n->left->right = NULL;
        }
    }
    else if(A > n->data) {
        if(n->right != NULL)
            traverse_LMRW(A, n->right);
        else {
            n->right = new Node;
            n->right->data = A;
            n->right->left = NULL;
            n->right->right= NULL;
        }
    }
}
int TernaryTree::leaf_count_h(Node *current){
    static int cnt = 0;
    if (current != NULL) {
        if ((current->left == NULL) and (current->right == NULL))
            cnt += 1;
        leaf_count_h(current->left);
        leaf_count_h(current->right);
    }
    return cnt;
}

int TernaryTree::leaf_count() {
    return leaf_count_h(root);
}
int TernaryTree::degree_one_nodes_count(Node *current, int i) {
    static int sum = 0;
    if (current != NULL) {
        sum += current->data;
        node_sum_h(current->left);
        node_sum_h(current->right);
    }
    return sum;
}
int TernaryTree::node_sum() {
    return node_sum_h(root);
}

int main() {
    int A[14] = {7,4,2,2,3,1,8,4,0,6,5,9,4,6};
    int n = sizeof(A)/sizeof(A[0]);
    TernaryTree T;
    T.construct_tree();
    T.traverse_LMRW(A[14], reinterpret_cast<Node *>(n));
    T.leaf_count();
    T.degree_one_nodes_count(reinterpret_cast<Node *>(A[14]), n);
    return 0;
}

