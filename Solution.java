
import java.util.ArrayList;
import java.util.List;

public class Solution {

    public List<String> binaryTreePaths(TreeNode root) {
        return trackPaths(new ArrayList<>(), new StringBuilder(), root);
    }

    public List<String> trackPaths(List<String> paths, StringBuilder path, TreeNode node) {

        if (node == null) {
            return null;
        }

        int length = path.length();
        path.append(node.val);

        if (node.left == null && node.right == null) {
            paths.add(path.toString());
        } else {
            path.append("->");
            trackPaths(paths, path, node.left);
            trackPaths(paths, path, node.right);
        }

        path.setLength(length);

        return paths;
    }
}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
