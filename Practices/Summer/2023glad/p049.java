import java.util.*;

public class p049 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        Node[] g = new Node[n];
        for (int i = 0; i < g.length; i++)
            g[i] = new Node(i);
        for (int i = 0; i < m; i++) {
            int from = in.nextInt()-1;
            int to = in.nextInt()-1;
            int w = in.nextInt();
            g[from].edges.add(new Edge(g[to], w));
            g[to].edges.add(new Edge(g[from], w));
        }

        for (int i = 0; i < k; i++) {
            int c = in.nextInt()-1;
            int id = in.nextInt();
            g[c].balls.add(id);
        }

        long min = (long)1e18;
        Queue<State> q = new ArrayDeque<>();
        HashMap<State, Integer> map = new HashMap<>();

        State start = new State(g[0], g[0].balls);
        q.add(start);
        map.put(start, 0);

        while (!q.isEmpty()) {
            State curState = q.poll();
            Node here = curState.v;
            HashSet<Integer> curBalls = curState.curBalls;
            int dist = map.get(curState);

            if(curBalls.size() >= 7) {
                min = Math.min(dist, min);
                continue;
            }

            for (Edge e : here.edges) {
                HashSet<Integer> hereBalls = new HashSet<>(curBalls);hereBalls.addAll(e.to.balls);
                State newState = new State(e.to, hereBalls);
                Integer d = map.get(newState);
                if(d==null || d > dist+e.w){
                    map.put(newState, dist+e.w);
                    q.add(newState);
                }
            }
        }

        System.out.println(min==(long)1e18?-1:min);
    }
}

class State {
    Node v;
    HashSet<Integer> curBalls;
    State(Node v, HashSet<Integer> curBalls) {
        this.v = v;
        this.curBalls = curBalls;
    }
    @Override
    public int hashCode() {
        return v.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return ((State)obj).v.equals(v) && ((State)obj).curBalls.equals(curBalls);
    }
}

class Node {
    int id;
    ArrayList<Edge> edges;
    HashSet<Integer> balls;
    Node(int id){
        this.id = id;
        edges = new ArrayList<>();
        balls = new HashSet<>();
    }
    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
    @Override
    public boolean equals(Object obj) {
        return ((Node)obj).id == id;
    }
}

class Edge {
    Node to;
    int w;
    Edge(Node to, int w){
        this.to = to;
        this.w = w;
    }
}
