import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numMethods = in.nextInt();

        
        HashMap<String, Integer> indexes = new HashMap<>();
        ArrayList<Method> graph = new ArrayList<>();
        graph.add(new Method("PROGRAM"));
        indexes.put("PROGRAM", graph.size());

        



    }
}

class Method
{
    String name;
    ArrayList<Edge> edges;
    Method(String name)
    {
        this.name = name;
        edges = new ArrayList<>();
    }
}

class Edge
{
    Method from;
    Method to;
    Edge(Method from, Method to)
    {
        this.from = from;
        this.to = to;
    }
}