/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode helper(int ps, int pe, int[] preorder,int is, int ie, int[] inorder){
        if(is>ie || ps>pe ){
            return null;
        }
        TreeNode n = new TreeNode(preorder[ps]);
        int count = is;
        while(inorder[count]!=preorder[ps]){
            count++;
        }
        
        n.left=helper(ps+1,ps+count-is,preorder,is,count-1,inorder);
        n.right=helper(ps+count-is+1,pe,preorder,count+1,ie,inorder);
        return n;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(0,preorder.length-1,preorder,0,inorder.length-1,inorder);
    }
}