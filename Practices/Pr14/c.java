import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;
import java.awt.Point;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        int numLocs = in.nextInt();

        ArrayList<Node> graph = new ArrayList<>(numLocs);
        for (int i = 0; i < numLocs; i++)
            graph.add(new Node(i, in.nextInt()));
        
        int totEdges = in.nextInt();

        for (int i = 0; i < totEdges; i++) {
            int from = in.nextInt(), to = in.nextInt(), weight = in.nextInt();

            graph.get(from - 1).addEdge(graph.get(to-1), weight);
            graph.get(to - 1).addEdge(graph.get(from-1), weight);
        }

        
        Point last = getNums(graph).get(graph.get(graph.size() - 1));

        if (last == null) {
            System.out.println("impossible");
            return;
        }

        System.out.println(last.x + " " + last.y);

    }
    private static HashMap<Node, Point> getNums(ArrayList<Node> graph) {

        int start = 0;
        int end = graph.size() - 1;
        
        HashMap<Node, Point> map = new HashMap<>();
        Queue<Node> q = new ArrayDeque<>();

        map.put(graph.get(0), new Point(0, graph.get(0).items));
        q.add(graph.get(0));

        while (!q.isEmpty()) {
            Node thisNode = q.poll();
            Point info = map.get(thisNode);

            for (Edge e: thisNode.edges) {
                Point eInfo = map.get(e.to);
                if (eInfo == null || eInfo.x > (info.x+e.weight) || (eInfo.x == info.x+e.weight && eInfo.y < (info.y + e.to.items))) {
                    map.put(e.to, new Point(info.x+e.weight, info.y + e.to.items));
                    q.add(e.to);
                }
            }
        }

        return map;

    }
}

class Node {
    int node;
    ArrayList<Edge> edges;
    int items;

    public Node(int node, int items)
    {
        this.node = node + 1;
        this.items = items;
        this.edges = new ArrayList<>();
    }
    
    public void addEdge(Node e, int weight)
    {
        edges.add(new Edge(this, e, weight));
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(node);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Node)obj).node == node;
    }

    @Override
    public String toString() {
        return "{" + node + "++" + items + "}";
    }

}

class Edge {
    int weight;
    Node from;
    Node to;

    public Edge(Node from, Node to, int weight)
    {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}