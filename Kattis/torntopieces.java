import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 * torntopieces
 */
public class torntopieces {

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);

        int numPieces = in.nextInt();
        in.nextLine();

        Graph graph = new Graph();

        for (int i = 0; i < numPieces; i++) 
        {
            String[] edges = in.nextLine().split(" ");

            for (int j = 1; j < edges.length; j++)
                graph.addEdge(edges[0], edges[j]);

        }

        System.out.println(graph.findPath(in.next(), in.next()));
        in.close();

    }
}

class Graph{


    HashMap<String, Integer> index;
    HashMap<Integer, String> place;

    ArrayList<ArrayList<Edge>> nodes;

    String path;

    int numVerticies;


    public Graph(){

        this.index = new HashMap<>();
        this.place = new HashMap<>();
        this.nodes = new ArrayList<>();

        path = "";
    }

    public String findPath(String start, String end) {
        
        if (index.get(start) == null || index.get(end) == null) {
            return "no route found";
        }

        boolean[] visited = new boolean[numVerticies];
        StringBuilder str = new StringBuilder();

        str.append(start);

        DFS(index.get(start), index.get(end), visited, str);

        if(path.equals("")) return "no route found";
        
        return path;

    }

    private void DFS(int start, int end, boolean[] visited, StringBuilder str) {

        if (start == end) {

            if (path.equals("") || str.length() < path.length()) {
                path = str.toString();
            }

            return;
        }

        visited[start] = true;

        for (Edge e : nodes.get(start)) {
            if (!visited[e.b] && path.equals("")) {
                StringBuilder newStr = new StringBuilder(str).append(" " + place.get(e.b));
                DFS(e.b, end, visited, newStr);
            }
        }
        
        visited[start] = false;

    }

    public void addEdge(String a, String b){


        if (!index.containsKey(a)) {

            int count = index.size();
            index.put(a, count);
            place.put(count, a);

        }

        if (!index.containsKey(b)) {

            int count = index.size();
            index.put(b, count);
            place.put(count, b);
            
        }

        while(nodes.size() <= index.get(a)) {
            nodes.add(new ArrayList<>());
            this.numVerticies++;
        }

        while(nodes.size() <= index.get(b)){
            nodes.add(new ArrayList<>());
            this.numVerticies++;
        }

        nodes.get(index.get(a)).add(new Edge(a, b, index.get(a), index.get(b)));
        nodes.get(index.get(b)).add(new Edge(b, a, index.get(b), index.get(a)));

    }


}


class Edge {

    int a;
    int b;
    String aName;
    String bName;

    public Edge(String aName, String bName, int a, int b){

        this.aName = aName;
        this.bName = bName;
        this.a = a;
        this.b = b;

    }
    
    @Override
    public String toString() {
        return "{" + aName + "--->" + bName + "}";
    }

}