import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class e {
    public static ArrayList<Junction> graph;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numJunctions = in.nextInt();
        int numEdges = in.nextInt();
        int numPrevJunctions = in.nextInt();
        in.nextLine();

        String[] path = in.nextLine().split(" ");
        System.out.println(Arrays.toString(path));
        graph = new ArrayList<>();

        for (int i = 0; i < numJunctions; i++) 
            graph.add(new Junction(i));

        for (int i = 0; i < numEdges; i++) {
            int start = in.nextInt() - 1;
            int end = in.nextInt() - 1;
            int time = in.nextInt();

            graph.get(start).addEdge(graph.get(end), time);
            graph.get(end).addEdge(graph.get(start), time);
        }

            
        int pathTime = getPathTime(0, path);

        System.out.println(pathTime);
        boolean[] used = new boolean[numJunctions];
        if (isThereSecondPath(graph.get(0), pathTime, used, String.valueOf(path), new StringBuilder("1"))) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }

    private static boolean isThereSecondPath(Junction here, int pathTime, boolean[] used, String path, StringBuilder thisPath) {

        if (pathTime < 0) 
            return false;

        if(here.equals(graph.get(graph.size() - 1)))
            return !thisPath.toString().equals(path);

        used[here.num] = true;

        for (Edge e : here.edges) {
            if (!used[e.to.num]) {
                if (isThereSecondPath(e.to, pathTime - e.time, used, path, new StringBuilder(thisPath).append(e.to.num + 1)))
                    return true;
            }
        }
        used[here.num] = false;

        

        return false;
    }


    private static int getPathTime(int at, String[] path) {

        if (at == path.length - 1)
            return 0;

        Junction here = graph.get((Integer.parseInt(path[at])) - 1);
        Junction to = graph.get((Integer.parseInt(path[at+1])) - 1);

        int travel = (int)1e9;
        for (Edge e : here.edges)
            if (e.to.equals(to)) 
                travel = Math.min(travel, e.time + getPathTime(at+1, path));

        return travel;
    }
}

class Junction {

    int num;
    ArrayList<Edge> edges;

    Junction(int num){
        this.num = num;
        edges = new ArrayList<>();
    }

    public void addEdge(Junction to, int time)
    {
        edges.add(new Edge(this, to, time));
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(num);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Junction)obj).num == num;
    }

}


class Edge {

    Junction from;
    Junction to;
    int time;

    Edge(Junction from, Junction to, int time)
    {
        this.from = from;
        this.to = to;
        this.time = time;
    }

    @Override
    public String toString() {
        return from.num + "-" + time + "->" + to.num;
    }
}