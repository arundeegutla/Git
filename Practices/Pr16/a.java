import java.util.*;

public class a {
    public static ArrayList<Place> places;
    public static Must[] allMusts;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPlaces = in.nextInt();
        int mustVisit = in.nextInt();
        int connections = in.nextInt();
        int totalTime = in.nextInt();
        int taxiTime = in.nextInt();

        places = new ArrayList<>();
        for (int i = 0; i < numPlaces; i++)
            places.add(new Place(i));

        allMusts = new Must[mustVisit + 1];
        allMusts[0] = new Must(places.get(0), 0);
        for (int i = 0; i < mustVisit; i++)
            allMusts[i+1] = new Must(places.get(in.nextInt()), in.nextInt());

        for (int i = 0; i < connections; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            int time = in.nextInt();
            places.get(start).addEdge(places.get(end), time);
            places.get(end).addEdge(places.get(start), time);
        }
        

        for (int i = 0; i < allMusts.length; i++) {
            HashMap<Place, Integer> map = allMusts[i].map;
            Queue<Place> q = new ArrayDeque<>();
            map.put(allMusts[i].thisPlace, 0);
            q.add(allMusts[i].thisPlace);
            while (!q.isEmpty()) {
                Place p = q.poll();
                int travel = map.get(p);
                for (Edge e : p.edges) {
                    if (!map.containsKey(e.to) || map.get(e.to) > travel + e.timeHere) {
                        map.put(e.to, travel + e.timeHere);
                        q.add(e.to);
                    }
                }
            }
        }

        int[][] dist = new int[allMusts.length][allMusts.length];
        for (int i = 0; i < dist.length; i++) {
            for (int j = 0; j < dist.length; j++) {
                Integer d = allMusts[i].map.get(allMusts[j].thisPlace);
                dist[i][j] = d == null ? (int)1e9 : d + allMusts[j].spending;
            }
        }

        int didnt = tspNoTaxiSolver(dist);
        int did = tspTaxiSolver(dist, taxiTime);

        if (didnt <= totalTime) {
            System.out.println("possible without taxi");
            return;
        } else if (did <= totalTime) {
            System.out.println("possible with taxi");
        } else {
            System.out.println("impossible");
        }
    }

    private static int tspNoTaxiSolver(int[][] dist) {
        int n = dist.length;
        int[][] memo = new int[1<<n][n];
        for (int[] oneD : memo)
            Arrays.fill(oneD, -1);
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            shortest = Math.min(shortest, tspNoTaxi((1<<i), i, dist, memo) + dist[0][i]);
        return shortest;
    }

    private static int tspNoTaxi(int visited, int current, int[][] dist, int[][] memo) {
        if (memo[visited][current] != -1)
            return memo[visited][current];
        
        if (visited == ((1<<dist.length) - 1))
            return dist[current][0];
        
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < dist.length; i++)
            if ((visited & (1<<i)) == 0)
                shortest = Math.min(shortest, tspNoTaxi(visited | (1<<i), i, dist, memo) + dist[current][i]);
        return memo[visited][current] = shortest;
    }

    private static int tspTaxiSolver(int[][] dist, int taxiTime) {
        int n = dist.length;
        int[][][] memo = new int[1<<n][n][2];
        for (int[][] twoD : memo)
            for (int[] oneD : twoD)
                Arrays.fill(oneD, -1);
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            shortest = Math.min(shortest, Math.min(tspTaxi((1<<i), i, false, dist, memo, taxiTime) + dist[0][i], 
                                                   tspTaxi((1<<i), i, true, dist, memo, taxiTime) + taxiTime + allMusts[i].spending));
        return shortest;
    }

    private static int tspTaxi(int visited, int current, boolean tookTaxi, int[][] dist, int[][][] memo, int taxiTime) {
        if (memo[visited][current][tookTaxi?1:0] != -1)
            return memo[visited][current][tookTaxi?1:0];
        
        if (visited == ((1<<dist.length) - 1))
            return tookTaxi ? dist[current][0] : Math.min(dist[current][0], taxiTime);
        
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < dist.length; i++)
            if ((visited & (1<<i)) == 0)
            {
                shortest = Math.min(shortest, tspTaxi(visited | (1<<i), i, tookTaxi, dist, memo, taxiTime) + dist[current][i]);
                if (!tookTaxi)
                    shortest = Math.min(shortest, tspTaxi(visited | (1<<i), i, !tookTaxi, dist, memo, taxiTime) + taxiTime + allMusts[i].spending);
            }
        return memo[visited][current][tookTaxi?1:0] = shortest;
    }
}

class Must {
    Place thisPlace;
    HashMap<Place, Integer> map;
    int spending;
    public Must(Place thisPlace, int spending)
    {
        this.thisPlace = thisPlace;
        this.spending = spending;
        map = new HashMap<>();
    }
}

class Place {

    int num;
    ArrayList<Edge> edges;

    Place(int num) {
        this.num = num;
        edges = new ArrayList<>();
    }

    public void addEdge(Place to, int time) {
        edges.add(new Edge(this, to, time));
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(num);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Place)obj).num == num;
    }

}

class Edge {
    Place from;
    Place to;
    int timeHere;
    Edge(Place from, Place to, int time)
    {
        this.from = from;
        this.to = to;
        this.timeHere = time;
    }
}
