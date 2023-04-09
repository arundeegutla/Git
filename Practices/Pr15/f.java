import java.util.*;

public class f {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCities = in.nextInt();
        int numEdges = in.nextInt();

        ArrayList<Vertex> list = new ArrayList<>();
        for (int i = 0; i < numCities; i++)
            list.add(new Vertex(i));

        for (int i = 0; i < numEdges; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int weight = in.nextInt();
            list.get(from).addEdge(list.get(to), weight);
            list.get(to).addEdge(list.get(from), weight);
        }

        Ball[] balls = new Ball[8];
        for (int i = 0; i < balls.length; i++) {
            if (i == 0) {
                balls[i] = new Ball(list.get(0));
                continue;
            }
            Vertex v = list.get(in.nextInt() - 1);
            balls[i] = new Ball(v);
        }

        for (Ball ball : balls) {
            Queue<Vertex> q = new ArrayDeque<>();
            HashMap<Integer, Long> map = ball.map;
            q.add(ball.thisVertex);
            map.put(ball.thisVertex.num, (long)0);
            while (!q.isEmpty()) {
                Vertex v = q.poll();
                long travel = map.get(v.num);
                for (Edge e : v.edges) {
                    if (!map.containsKey(e.to.num) || (map.get(e.to.num) > travel + e.weight)) {
                        map.put(e.to.num, travel + e.weight);
                        q.add(e.to);
                    }
                }
            }
        }

        long min = tspSolver(balls);

        if (min == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(min);

    }

    private static long tspSolver(Ball[] balls) {
        int n = balls.length;

        long[][] memo = new long[1<<n][n];
        for (long[] oneD : memo)
            Arrays.fill(oneD, -1);

        long min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long thisShortest = tsp((1<<n) - 1, i, balls, memo);
            min = Math.min(min, thisShortest);
        }
        return min;
    }

    private static long tsp(int mask, int next, Ball[] balls, long[][] memo) {

        if (memo[mask][next] != -1)
            return memo[mask][next];

        if (Integer.bitCount(mask) == 1) {
            Long zeroToStart = balls[0].map.get(balls[next].thisVertex.num);
            if (zeroToStart != null)
                return balls[0].map.get(balls[next].thisVertex.num);
            return Integer.MAX_VALUE;
        }

        int oldmask = mask - (1<<next);
        long min = Integer.MAX_VALUE;

        for (int i = 0; i < balls.length; i++) {
            Long dist = balls[i].map.get(balls[next].thisVertex.num);
            if ((oldmask & (1<<i)) != 0 && dist != null)
                min = Math.min(min, tsp(oldmask, i, balls, memo) + dist);
        }
        return memo[mask][next] = min;
    }
}


class Ball {

    Vertex thisVertex;
    HashMap<Integer, Long> map;

    public Ball (Vertex thisVertex)
    {
        this.thisVertex = thisVertex;
        map = new HashMap<>();
    }
}

class Vertex {
    int num;
    ArrayList<Edge> edges;
    public Vertex(int num) {
        this.num = num;
        edges = new ArrayList<>();
    }

    public void addEdge(Vertex to, int weight)
    {
        this.edges.add(new Edge(this, to, weight));
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(num);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Vertex)obj).num == num;
    }
}

class Edge {
    Vertex from;
    Vertex to;
    int weight;

    public Edge(Vertex from, Vertex to, int weight)
    {
        this.to = to;
        this.from = from;
        this.weight = weight;
    }

}
