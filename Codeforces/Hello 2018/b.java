import java.util.ArrayList;
import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numNodes = in.nextInt();

        ArrayList<Node> list = new ArrayList<>();
        for (int i = 0; i < numNodes; i++)
            list.add(new Node(i));


        for (int i = 0; i < numNodes - 1; i++)
            list.get(in.nextInt() - 1).children.add(list.get(i+1));

        
        for (Node node : list) {
            if (node.children.size() == 0) {
                continue;
            }
            int count = 0;
            for (Node edge : node.children) {
                if (edge.children.size() == 0) {
                    count++;
                }
            }
            if (count < 3) {
                System.out.println("No");
                return;
            }

        }

        System.out.println("Yes");
    }
}


class Node{
    int index;
    ArrayList<Node> children;

    Node(int index){
        this.index = index;
        children = new ArrayList<>();
    }
}