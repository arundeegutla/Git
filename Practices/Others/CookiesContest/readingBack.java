
import java.util.*;

public class readingBack {
    public static boolean[] visited;   
    public static int[] pages;   
    public static int[] tree;   

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        visited = new boolean[n];  
        pages = new int[n];
        for (int i = 0; i < pages.length; i++)
            pages[i] = in.nextInt();
        
        int[] incoming = new int[n];
        tree = new int[n];
        Arrays.fill(tree, -1);

        for(int i = 0; i < m; i++){
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            tree[to] = from;
            incoming[from]++;
        }
    
        ArrayList<Integer> culminating = new ArrayList<>();
        for(int i = 0; i < n; i++)
            if(incoming[i] == 0)
                culminating.add(i);
    

        int minn = (int)1e9;
        for(int i = 0; i < culminating.size(); i++) {
            for(int j = i+1; j < culminating.size(); j++) {
                minn = Math.min(minn, go(culminating.get(i)) + go(culminating.get(j)));
                Arrays.fill(visited, false);
            }
        }
        
        System.out.println(minn);
    }

    public static int go(int v) {
        if(v == -1 || visited[v]) return 0;
        visited[v] = true;
        return pages[v] + go(tree[v]);
    }
}
