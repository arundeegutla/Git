import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numRooms = in.nextInt();

        ArrayList<Key> g = new ArrayList<>();
        for (int i = 0; i < numRooms; i++)
            g.add(new Key(i, numRooms));

        for (int i = 0; i < numRooms; i++) {
            int numKeys = in.nextInt();
            if (i > 0 && numKeys > 0)
                g.get(i-1).opensNext = true;
            for (int j = 0; j < numKeys; j++) {
                int next = in.nextInt() - 1;
                g.get(i).opens[next] = true;
            }
        }

        getMax(g);
        System.out.println(getMax(g));
    }

    private static int getMax(ArrayList<Key> g) {
        return DFS(0, 0, g) + 1;
    }

    private static int DFS(int at, int used, ArrayList<Key> g) {

        if (at == g.size() - 1)
            return 0;

        if (g.get(at).opensNext)
            return DFS(at+1, used, g) + 1;

        int max = 0;
        for(int i = 0; i <= at; i++)
        {
            Key cur = g.get(i);
            if (!cur.used && cur.opens[at+1]) {
                cur.used = true;
                max = Math.max(max, DFS(at+1, g) + 1);
                cur.used = false;
            }
        }
        return max;
    }
}

class Key {
    int from;
    boolean[] opens;
    boolean used;
    boolean opensNext;
    Key(int from, int size){
        this.from = from;
        opens = new boolean[size];
        used = false;
    }

    @Override
    public String toString() {
        return from + " can open " + Arrays.toString(opens) + " opens next ? " + opensNext;
    }
}