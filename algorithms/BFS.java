package algorithms;

import java.util.LinkedList;
import java.util.Queue;

public class BFS {

    static class TreeNode {
        int data;
        TreeNode left, right;

        public TreeNode(int key) {
            data = key;
            left = right = null;
        }
    }

    public static void main(String[] args) {
        
        TreeNode root = new TreeNode(0);
        root.left = new TreeNode(1);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        System.out.println("Inorder traversal"); 
        traverseBfs(root);

    }

    public static void traverseBfs(TreeNode node){

       Queue<TreeNode> queue = new LinkedList<TreeNode>();
       queue.add(node) ;

       while(!queue.isEmpty()){
        

        TreeNode temp = queue.poll(); 
        System.out.print(temp.data + "->");
        
        /*add left child to the queue */
        if (temp.left != null) {
            queue.add(temp.left);
        }

        /*add right right child to the queue */
        if (temp.right != null) {
            queue.add(temp.right);
        }

       }

    }
    
}
