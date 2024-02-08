package trees;

public class BinaryTree {

    static class Node{
        int value;
        Node left, right;

        public Node(int value){
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    Node root = null;

    // approach 1
    // public void insert(Node currentNode, int value){

    //     if(root == null){
    //         root = new Node(value);
    //     }
    //     else{
    //        while (currentNode != null) {

    //             if(value < currentNode.value) {
    //                 if(currentNode.left != null){
    //                     insert(currentNode.left,value);
    //                 }
    //                 else{
    //                     currentNode.left = new Node(value);
    //                     return;
    //                 }
    //             }

    //             else if(value > currentNode.value) {
    //                 if(currentNode.right != null){
    //                     insert(currentNode.right, value);
    //                 }
    //                 else{
    //                     currentNode.right = new Node(value);
    //                     return;
    //                 }
    //             }
            
    //        }

    //     }

    // }

    // approach 2 
    public void insert(Node node, int value) {
        if (value < node.value) { 
            if (node.left != null) { 
                insert(node.left, value); 
            } 
            else { 
                System.out.println(" Inserted " + value + " to left of " + node.value); 
                node.left = new Node(value); 
            } } 
        else if (value > node.value) {
          if (node.right != null) {
            insert(node.right, value);
          } else {
            System.out.println("  Inserted " + value + " to right of "
                + node.value);
            node.right = new Node(value);
          }
        }
      }

    public void traverse(Node node){
        if(node.left != null){
            traverse(node.left);
        }
        System.out.println("->" + node.value);

        if(node.right != null){
            traverse(node.right);
        }
    }


    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(); 
        tree.root = new Node(5);
        tree.insert(tree.root,2);
        tree.insert(tree.root,4);
        tree.insert(tree.root,3);
        // tree.insert(tree.root,6);
        // tree.insert(tree.root,7);
        // tree.insert(tree.root,3);
        // tree.insert(tree.root,9);

        tree.traverse(tree.root);
    }
    
}
