import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class paintings {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- > 0) {
            int n = s.nextInt(); s.nextLine();
            String[] colors = s.nextLine().split(" ");
            int id = 0;
            HashMap<Integer, String> map = new HashMap<Integer, String>();
            HashMap<String, Integer> map2 = new HashMap<String, Integer>();
            for (String c : colors) {
                map.put(id, c);
                map2.put(c, id);
                id++;
            }
            int m = s.nextInt(); s.nextLine();
            ArrayList<ArrayList<Integer>> noadj = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; i++) noadj.add(new ArrayList<Integer>());

            for (int i = 0; i < m; i++) {
                String[] in = s.nextLine().split(" ");
                noadj.get(map2.get(in[0])).add(map2.get(in[1]));
                noadj.get(map2.get(in[1])).add(map2.get(in[0]));
            }

            perm = new int[n];
            op = new int[n];
            used = new boolean[n];
            for (int i = 0; i < n; i++) op[i] = map2.get(colors[i]);
            found = false;
            num = 0;
            res = "";
            perm(perm, op, used, 0, n, noadj, map);
            System.out.println(num);
            System.out.println(res);
        }
    }

    static int[] perm, op;
    static boolean[] used;
    static boolean found;
    static int num;
    static String res;

    static void perm(int[] perm, int[] op, boolean[] used, int idx, int n, ArrayList<ArrayList<Integer>> adjList, HashMap<Integer, String> map) {
        if (idx == n) {
            if (!found) {
                for (int i : perm) res += map.get(i) + " ";
                found = true;
            }
            num++;
        } else {
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    if (idx != 0 && adjList.get(op[i]).contains(perm[idx - 1])) continue;
                    used[i] = true;
                    perm[idx] = op[i];
                    perm(perm, op, used, idx + 1, n, adjList, map);
                    used[i] = false;
                }
            }
        }
    }
}
