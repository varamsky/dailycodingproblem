/*

[Easy]

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

*/

#include <iostream>
#include <map>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    public:
        Node *root;
        BinaryTree(){
            root = NULL;
        }

        void preorderTraversal(Node *root){
            if(root == NULL)
                return;
            cout << root->data << "  ";
            //cout << root->left->data << "  ";

            cout << " left ";
            preorderTraversal(root->left);
            cout << " right ";
            preorderTraversal(root->right);
        }

        // This method makes use of 2 functions
        // Time Complexity of this approach is O(n^2) where n is number of nodes in the given binary tree
        // Below is another approach that does the work of these 2 functions in a single function with O(n) time complexity
        /*bool isUnivalTree(Node *root){
            if(root == NULL)
                return true;
            
            if(((root->left != NULL) && (root->data != root->left->data)) || ((root->right != NULL) && (root->data != root->right->data)))
                return false;
            
            if(isUnivalTree(root->left) == false || isUnivalTree(root->right) == false)
                return false;
            
            return true;
        }

        int countUnivalTrees(Node *root){
            if(root == NULL)
                return 0;
            
            int left_count,right_count = 0;

            left_count = countUnivalTrees(root->left);
            right_count = countUnivalTrees(root->right);

            if(isUnivalTree(root) == true)
                return left_count+right_count+1;
            else
                return left_count+right_count;
        }*/

        // This approach finds count of unival trees in O(n) time complexity
        map<string,int> countUnivals(Node *root){
            map<string,int> result;
            if(root == NULL){
                result["count"] = 0;
                result["isUnival"] = 1; // 0 for false and 1 for true

                return result;
            }

            int left_count,is_left_unival,right_count,is_right_unival;
            map<string,int> methodcall;

            methodcall = countUnivals(root->left);
            left_count = methodcall["count"];
            is_left_unival = methodcall["isUnival"];
            
            methodcall = countUnivals(root->right);
            right_count = methodcall["count"];
            is_right_unival = methodcall["isUnival"];

            //cout << "root data = " << root->data << endl;

            bool is_tree_unival = true;
            if(is_left_unival == 0 || is_right_unival == 0)
                is_tree_unival = false;
            if(root->left != NULL && root->left->data != root->data)
                is_tree_unival = false;
            if(root->right != NULL && root->right->data != root->data)
                is_tree_unival = false;

            if(is_tree_unival == true){
                result["count"] = left_count + right_count + 1;
                result["isUnival"] = 1;

                return result;
            }
            else{
                result["count"] = left_count + right_count;
                result["isUnival"] = 0;

                return result;
            }
        }
};

int main(){
    BinaryTree btree;

// INPUT 1
    /*
    
    The below input of binary tree looks like this-

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
    
    */

    btree.root = new Node(0);

    btree.root->left = new Node(1);

    btree.root->right = new Node(0);

    btree.root->right->left = new Node(1);

    btree.root->right->right = new Node(0);

    btree.root->right->left->left = new Node(1);

    btree.root->right->left->right = new Node(1);


// INPUT 2
/*

    The below input of binary tree looks like this-

    1
   / \
  1   1
 / \   \
1   1   1

*/

    /*btree.root = new Node(1);

    btree.root->left = new Node(1);

    btree.root->right = new Node(1);

    btree.root->left->left = new Node(1);

    btree.root->left->right = new Node(1);

    btree.root->right->right = new Node(1);*/


// INPUT 3
    /*

    The below input of binary tree looks like this-

    2
   / \
  2   2
 / \
5   2

*/

    /*btree.root = new Node(2);

    btree.root->left = new Node(2);

    btree.root->right = new Node(2);

    btree.root->left->left = new Node(5);

    btree.root->left->right = new Node(2);*/


// INPUT 4
    /*

    The below input of binary tree looks like this-

    1
     \
      2

*/

    /*btree.root = new Node(1);

    btree.root->right = new Node(2);*/


    btree.preorderTraversal(btree.root);
    cout << endl;

    //cout << "Is unival tree : " << btree.isUnivalTree(btree.root) << endl;
    //cout << "Number of Unival Trees = " << btree.countUnivalTrees(btree.root) << endl;

    cout << "Number of Unival Trees = " << btree.countUnivals(btree.root)["count"] << endl;

    return 0;
}