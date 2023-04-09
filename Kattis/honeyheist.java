import java.util.ArrayDeque;
import java.util.ArrayList;
// import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;

public class honeyheist {

    public static ArrayList<Integer> sizes;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int honeyCombSize = in.nextInt();
        int maxChew = in.nextInt();
        int starting = in.nextInt();
        int ending = in.nextInt();
        int numNull = in.nextInt();

        ArrayList<Cell> verticies = new ArrayList<>();
        HashSet<Integer> nulls = new HashSet<>();
        buildSizes(honeyCombSize);

        for (int i = 0; i < numNull; i++)
            nulls.add(in.nextInt());
        
        if (nulls.contains(ending) || nulls.contains(starting)) {
            System.out.println("No");
            in.close();
            return;
        }
        
        buildGraph(honeyCombSize, verticies, nulls);

        // printGraph(verticies);

        HashMap<Cell, Integer> map = new HashMap<>();
        Queue<Cell> q = new ArrayDeque<>();

        map.put(verticies.get(starting - 1), 0);
        q.add(verticies.get(starting - 1));

        while (!q.isEmpty() && !map.containsKey(verticies.get(ending - 1))) 
        {
            Cell thisCell = q.poll();

            if (map.get(thisCell) + 1 > maxChew) {
                continue;
            }

            for (Cell cell : thisCell.edges) {
                if (!map.containsKey(cell)) {
                    map.put(cell, map.get(thisCell) + 1);
                    q.add(cell);
                } else {

                    if (map.get(cell) > map.get(thisCell) + 1) {
                        map.put(cell, map.get(thisCell) + 1); 
                        q.add(cell);
                    }

                }
            }
        }


        if (map.containsKey(verticies.get(ending - 1))) {
            System.out.println(map.get(verticies.get(ending - 1)));
        } else {
            System.out.println("No");
        }

        in.close();
    

    }

    // private static void printGraph(ArrayList<Cell> verticies) {
    //     for (Cell cell : verticies) {
    //         if (cell == null) {
    //             continue;
    //         }
    //         System.out.print(cell.id + " ++++++++");
    //         Collections.sort(cell.edges);
    //         for (Cell connect : cell.edges) {
    //             System.out.print(" " + connect.id);
    //         }
    //         System.out.println();
    //     }
    // }

    private static void buildGraph(int honeyCombSize, ArrayList<Cell> verticies, HashSet<Integer> nulls) {
        int total = (int)Math.pow(honeyCombSize, 3) - (int)Math.pow(honeyCombSize - 1, 3);

        for (int i = 1; i <= total; i++) {
            if (nulls.contains(i)) verticies.add(null);
            else verticies.add(new Cell(i));
        }

        int level = 0;
        int count = 1;


        for (int i = 0; i < verticies.size(); i++) {
            if (verticies.get(i) != null) {          
                ArrayList<Integer> connectingCells = getAllConnectingCells(honeyCombSize, verticies.get(i).id, level, count);
                for (int cell : connectingCells) {
                    if (!nulls.contains(cell)) {
                        verticies.get(i).edges.add(verticies.get(cell - 1));
                        verticies.get(cell - 1).edges.add(verticies.get(i));
                    }
                }   
            }
            if (sizes.get(level) - count == 0) {
                level++;
                count = 0;
            }
            count++;
        }
    }

    private static void buildSizes(int honeyCombSize) {
        sizes = new ArrayList<>();

        int minus = 0;

        for (int i = 0; i < honeyCombSize*2 - 1; i++) {

            if(honeyCombSize + i > honeyCombSize*2 - 1) 
                minus += 2;
                
            sizes.add((honeyCombSize + i) - minus);

        }
    }

    private static ArrayList<Integer> getAllConnectingCells(int honeyCombSize, int id, int level, int count) {

        ArrayList<Integer> cells = new ArrayList<>();

        if (level < honeyCombSize - 1) {
            cells.add(id + sizes.get(level));
            cells.add(id + sizes.get(level) + 1);

        } else if (level != sizes.size() - 1) {
            if (sizes.get(level) != count)
                cells.add(id + sizes.get(level));

            if (count != 1) 
                cells.add(id + sizes.get(level) - 1);
        }

        if (sizes.get(level) != count) {
            cells.add(id + 1);
        }

        return cells;
    }


    
}

class Cell implements Comparable<Cell>{

    int id;
    ArrayList<Cell> edges;

    public Cell(int id){
        this.id = id;
        this.edges = new ArrayList<>();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj || this.id == ((Cell)obj).id) {
            return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }

    @Override
    public int compareTo(Cell o) {
        return this.id - o.id;
    }
}