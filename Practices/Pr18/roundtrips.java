import java.io.*;
import java.util.*;

/**
 * roundtrips
 */
public class roundtrips {
    public static void main(String args[])
	{
        Scanner in = new Scanner(System.in);
        int numNodes = in.nextInt();
        int numEdges = in.nextInt();
		Graph g = new Graph(numNodes);
        for (int i = 0; i < numEdges; i++)
            g.addEdge(in.nextInt(), in.nextInt());
		System.out.println(g.getSccCount());
	}
}

class Graph
{
	int V;
	Vertex[] g;
    
	Graph(int v)
	{
		V = v;
		g = new Vertex[v];
		for (int i=0; i<v; i++)
			g[i] = new Vertex(i);
	}

	void addEdge(int v, int w) { 
        g[v].edges.add(g[w]);
    }

	void DFSUtil(int v, boolean visited[], Queue<Integer> component)
	{
        component.add(v);
		visited[v] = true;

        for (Vertex e : g[v].edges)
            if (!visited[e.num])
                DFSUtil(e.num, visited, component);
	}

	Graph reverse()
	{
		Graph m = new Graph(V);
		for (int v = 0; v < V; v++)
			for (Vertex e : g[v].edges)
				m.g[e.num].edges.add(new Vertex(v));
		return m;
	}

	void dfs1(int v, boolean visited[], Stack<Integer> stack) {
		visited[v] = true;
		for (Vertex e : g[v].edges)
			if(!visited[e.num])
                dfs1(e.num, visited, stack);
		stack.add(v);
	}

	int getSccCount() {

        int[] roots = new int[V];
        ArrayList<Integer> root_nodes = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
		Stack<Integer> stack = new Stack<>();

		boolean visited[] = new boolean[V];
		for (int i = 0; i < V; i++)
			if (!visited[i])
                dfs1(i, visited, stack);      
		Arrays.fill(visited,false);

		Graph gr = reverse();
		while (!stack.isEmpty())
		{
			int v = stack.pop();
			if (!visited[v])
			{
                Queue<Integer> component = new ArrayDeque<>();
				gr.DFSUtil(v, visited, component);
            
                int root = component.poll();
                for (int b : component)
                    roots[b] = root;
                root_nodes.add(root);
                map.put(root, map.size());
			}
		}

        int total = 0;

        for (int i = 0; i < V; i++) {
            
        }

        ArrayList<Component> allComponents = new ArrayList<>(); 
        for (int i = 0; i < root_nodes.size(); i++)
            allComponents.add(new Component(i));

        
        return total;
	}

}

class Component {
    int num;
    ArrayList<Integer> vs;
    int numNodes;
    HashMap<Component, Integer> edges;
    Component(int num) {
        this.num = num;
        this.numNodes = 0;
        vs = new ArrayList<>();
        edges = new HashMap<>();
    }
    @Override
    public int hashCode() {
        return Integer.hashCode(num);
    }
    @Override
    public boolean equals(Object obj) {
        return ((Component)obj).num == this.num;
    }
    @Override
    public String toString() {
        return vs + "--->" + edges;
    }
}


class Vertex {
    int num;
    ArrayList<Vertex> edges;
    Vertex(int num) {
        this.num = num;
        this.edges = new ArrayList<>();
    }
    @Override
    public int hashCode() {
        return Integer.hashCode(num);
    }
    @Override
    public boolean equals(Object obj) {
        return ((Vertex)obj).num == this.num;
    }
    @Override
    public String toString() {
        ArrayList<Integer> e = new ArrayList<>();
        for (Vertex v : edges)
            e.add(v.num);
        return num + "---->" + edges;
    }
}

