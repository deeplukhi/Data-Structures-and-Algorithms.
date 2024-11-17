public class RemovLeaf {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static class BuildTree {
        static int index = -1;

        public static Node build(int nodes[]) {
            index++;
            if (index >= nodes.length || nodes[index] == -1) {
                return null;
            }
            Node newNode = new Node(nodes[index]);
            newNode.left = build(nodes);
            newNode.right = build(nodes);
            return newNode;
        }
    }

    public static Node RemovLeaf(Node root, int target) {
        if (root == null) {
            return null;
        }
        root.left = RemovLeaf(root.left, target);
        root.right = RemovLeaf(root.right, target);

        if (root.left == null && root.right == null && root.data == target) {
            return null;
        }

        return root;
    }

    public static void preOrder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    public static void main(String[] args) {
        int nodes[] = { 5, 3, 8, 3, -1, 7, 9, -1, -1, -1, -1, -1, -1 };
        Node root = BuildTree.build(nodes);
        int target = 3;
        root = RemovLeaf(root, target);

        preOrder(root); // Expected output: 5 3 8 7 9
    }
}