
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}


/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function (root) {
    return trackPaths([], [], root);
};


/**
 * @param {string[]} paths
 * @param {string[]} path
 * @param {TreeNode} node
 * @return {string[]}
 */
function trackPaths(paths, path, node) {

    if (node === null) {
        return null;
    }

    let length = path.length;
    path.push(node.val);

    if (node.left === null && node.right === null) {
        paths.push(path.join(''));
    } else {
        path.push("->");
        trackPaths(paths, path, node.left);
        trackPaths(paths, path, node.right);
    }

    path.length = length;

    return paths;
}
