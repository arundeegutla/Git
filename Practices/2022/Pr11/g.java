import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class g {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numNodes = in.nextInt();
        int numEdges = in.nextInt();

        ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
        for (int i = 1; i <= numNodes; i++)
            graph.add(new ArrayList<>());

        for (int i = 0; i < numEdges; i++) {
            int from = in.nextInt();
            int to = in.nextInt() - 1;
            graph.get(Math.abs(from) - 1).add(new Edge(from < 0, to));
        }

        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> used = new HashSet<>();
        getAllStoppings(graph, set, used, false, 0);
        // System.out.println(set.toString());
        System.out.println(set.size());
    }

    private static void getAllStoppings(ArrayList<ArrayList<Edge>> graph, HashSet<Integer> set, HashSet<Integer> used, boolean madeabuggymove, int at) {

        used.add(at);
        boolean hasForced = false;
        for (Edge e : graph.get(at)) {
            // System.out.println(e + " " + at);
            if (e.forced)
                hasForced = true;

            if (!used.contains(e.to) && ((madeabuggymove && e.forced) || !madeabuggymove))
                getAllStoppings(graph, set, used, !e.forced || madeabuggymove, e.to);
        }

        if (!hasForced)
            set.add(at);

        used.remove(at);

    }


}
class Edge {
    boolean forced;
    int to;
    Edge(boolean forced, int to){
        this.forced = forced;
        this.to = to;
    }

    @Override
    public String toString() {
        return (forced ? "Forced " : "not ") + to;
    }
}
