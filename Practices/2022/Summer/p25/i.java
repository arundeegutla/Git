import java.util.*;

public class i {
    public static void main(String[] args) {
        
    }
}


class Dinic {
    Queue<Integer> q;
    ArrayList<Edge>[] adj;
    int n; 
    int s; 
    int t; 
    int oo = (int)1E9;
    boolean[] blocked; 
    int[] dist;
    Dinic (int n) {
        this.n = n; s = 0; t = n-1;
        q = new ArrayDeque<>();
        adj = new ArrayList[n];
        blocked = new boolean[n];
        dist = new int[n];
        init(q, adj, blocked, dist);
    }
    add(int f, int t, int cap) {
        Edge e = new Edge(f, t, cap);
        Edge rev = new Edge(t, f, 0);
        adj[f].add(rev.rev = e);
        adj[t].add(e.rev = rev);
    }
    boolean bfs() {
        q.clear();
        Arrays.fill(dist, -1);
        dist[t] = 0; q.add(t);
        while(!q.isEmpty()) {
            int node = q.poll();
            if(node == s) return true;
            for(Edge e : adj[node]) {
                if(e.rev.cap > e.rev.flow && dist[e.to] == -1) {
                    dist[e.to] = dist[node] + 1;
                    q.add(e.to);
                }
            }
        }
        return dist[s] != -1;
    }
    int dfs(int pos, int min) {
        if(pos == t) return min;
        int flow = 0;
        for(Edge e : adj[pos]) {
            int cur = 0;
            if(!blocked[e.to] && dist[e.to] == dist[pos]-1 && e.cap - e.flow > 0) {
                cur = dfs(e.to, Math.min(min-flow, e.cap - e.flow));
                e.flow += cur;
                e.rev.flow = -e.flow;
                flow += cur;
            }
            if(flow == min) return flow;
        }
        blocked[pos] = flow != min;
        return flow;
    }

    int flow() {
        clearEdges();
        int ret = 0;
        while(bfs()) {
            Arrays.fill(blocked, false);
            ret += dfs(s, oo);
        }
        return ret;
    }
}

class Edge {
    int from;
    int to;
    int cap;
    Edge rev;
    Edge(int from, int to, int cap) {
        this.from = from;
        this.to = to;
        this.cap = cap;
    }
}