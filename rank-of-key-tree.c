import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BST {
     private Node root;
        
        private class Node {
            
            private final Integer key;
            private Node right;
            private Node left;
            private int N;
            
            public Node(Integer key) {
                this.key = key;
                N = 1;
            }
        }
        public boolean isEmpty() {
            return size() == 0;
        }
        
        public int size() {
            return sizeOf(root);
        }
        
        private int sizeOf(Node x) {
            return x == null ? 0 : x.N;
        }
    
        public Integer get(int key) {
            Node x = get(root, key);
            return x == null ? null : x.key;
        }
        
        private Node get(Node x, Integer key) {
            if (x == null) {
                return null;
            }
            int cmp = key.compareTo(x.key);
            if (cmp == 0) {
                return x;
            }
            if (cmp < 0) {
                return get(x.left, key);
            }
            return get(x.right, key);
        }
    
    
    

    public Node insert(Node node,int key){
        if(node == null)
            return new Node(key);
        else if(node.key > key)
            node.left = insert(node.left,key);
        else if(node.key < key)
            node.right = insert(node.right,key);
        
        node.N = 1 + sizeOf(node.left) + sizeOf(node.right);

        return node;
    }


    public void insert(int key) {
        root = insert(root,key);

    }
    
    public Integer getRank(Node node,int key){
        if(node == null)
            return -1;
        if(node.key == key)
            return sizeOf(node.left);
        if(node.key > key)
            return getRank(node.left,key);
        
        int x = getRank(node.right,key);

        if(x == -1)
            return -1;
        else
            return 1 + sizeOf(node.left) + x;
        
    }


    public Integer getRank(int key){
        return getRank(root,key);
    } 
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BST bst = new BST();
        int n = in.nextInt();
        for(int i = 0 ; i < n ; i++){
            bst.insert(in.nextInt());
        }
        int m = in.nextInt();
        for(int i = 0 ; i < m ; i++){
            System.out.println(bst.getRank(in.nextInt()));
        }
    }
}
