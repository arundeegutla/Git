import java.util.*;

public class e {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPeople;
        int target;
        
        while ((numPeople = in.nextInt()) != 0 && (target = in.nextInt()) != 0) {
            
            int rootNum = in.nextInt();
            Node root = new Node(null);

            Queue<Node> q = new ArrayDeque<>();
            q.add(root);

            Integer prev = null;
            Node current = null;
            Node targetNode = null;

            for (int i = 1; i < numPeople; i++) {
                int peep = in.nextInt();

                if (prev == null || peep - prev > 1)
                    current = q.poll();

                Node thisNode = new Node(current);
                current.children.add(thisNode);
                q.add(thisNode);
                prev = peep;
                if (target == peep)
                    targetNode = thisNode;

            }
        
            if (target == rootNum) {
                System.out.println(0);
                continue;
            }
            if (targetNode.parent == root) {
                System.out.println(0);
                continue;
            }

            long sum = 0;

            for (Node sibling : targetNode.parent.parent.children)
                if (sibling != targetNode.parent)
                    sum += sibling.children.size();

            System.out.println(sum);


        }
    }
}

class Node {

    Node parent;
    ArrayList<Node> children;

    Node(Node parent){
        this.parent = parent;
        this.children = new ArrayList<>();
    }

}