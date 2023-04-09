import java.util.*;

public class h
{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        Graph g = new Graph(n);

        HashMap<String, Integer> map = new HashMap<>();

        ArrayList<Integer> start = new ArrayList<>();

        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            String[] split = in.nextLine().split(" ");

            int ind = 0;
            if (map.containsKey(split[0])){
                ind = map.get(split[0]);
            }
            else {
                map.put(split[0], cur);
                cur++;
            }

            if (split[0].split("::")[1].equals("PROGRAM"))
            {
                start.add(ind);
            }

            // System.out.println("k: " + split[1]);
            if (split[1].equals("0"))
            {
                in.nextLine();
                continue;
            }
            
            String[] methods = in.nextLine().split(" ");
            for (String s: methods)
            {
                int need = 0;
                if (map.containsKey(s))
                {
                    need = map.get(s);
                }
                else
                {
                    map.put(s, cur);
                    need = cur;
                    cur++;
                }

                if (need == ind)
                {
                    continue;
                }
                else 
                {
                    g.addEdge(ind, need);
                }
            }

        }
        // g.printGraph();
        
        int idk = n;
        for (int i: start)
        {
            g.bfs(i);
        }

        for (boolean b: g.allVisited)
        {
            if (b)
                idk--;
        }
        
        // int size = g.path.size();
        // int ret = n - size;
        System.out.println(idk);

    }
}

class Graph
{
    public int V;
    public ArrayList<ArrayList<Integer>> adj;
    public ArrayList<Integer> path;
    public boolean[] allVisited;

    Graph (int v)
    {
        V = v;
        adj = new ArrayList<>(v);
        for (int i = 0; i < V; i++)
        {
            adj.add(new ArrayList<>());
        }
        path = new ArrayList<>();
        allVisited = new boolean[V];
        Arrays.fill(allVisited, false);
    }

    public void addEdge(int v, int w)
    {
        adj.get(v).add(w);
        // System.out.println("adding: " + v + " <- " + w);
    }

    public void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            ArrayList<Integer> idk = adj.get(i);
            for (int x : idk)
            {
                System.out.println(i + " <- " + x);
            }
        }
    }


    public void bfs(int s)
    {
        boolean[] visited = new boolean[V];
        ArrayList<Integer> path = new ArrayList<>();
 
        LinkedList<Integer> queue = new LinkedList<Integer>();
 
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.add(s);
 
        while (queue.size() != 0) {
            s = queue.poll();
            // System.out.print("print " + s + " ");
            path.add(s);
 

            Iterator<Integer> i = adj.get(s).listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    allVisited[n] = true;
                    queue.add(n);
                }
            }
        }

        // int ret = 0;
        // for (boolean idk: visited)
        // {
        //     if (idk)
        //         ret++;
        // }

        // return ret;
        // return path.size();
    }
}