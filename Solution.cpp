
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        trackPaths(paths, "", root);
        return paths;
    }

    void trackPaths(vector<string>& paths, string path, TreeNode* node) {
        
        if (node == nullptr) {
            return;
        }

        path.append(to_string(node->val));

        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        } else {
            path.append("->");
            trackPaths(paths, path, node->left);
            trackPaths(paths, path, node->right);
        }
    }
};
