import java.util.*;

public class paintings {
    public static int[] favorite;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            favorite = null;
            int n = in.nextInt();
            in.nextLine();
            String[] colors = in.nextLine().split(" ");
            HashMap<String, Integer> id = new HashMap<>();
            for (String string : colors)
                id.put(string, id.size());
            int numWastePairs = in.nextInt();

            HashMap<Integer, HashSet<Integer>> wastepairs = new HashMap<>();

            for (int i = 0; i < numWastePairs; i++) {
                int first = id.get(in.next());
                int second = id.get(in.next());
                HashSet<Integer> list1 = wastepairs.getOrDefault(first, new HashSet<>());
                list1.add(second);
                wastepairs.put(first, list1);

                HashSet<Integer> list = wastepairs.getOrDefault(second, new HashSet<>());
                list.add(first);
                wastepairs.put(second, list);
            }

            int[] perm = new int[n];
            boolean[] used = new boolean[n];

            System.out.println(go(0, perm, used, colors, wastepairs));
            
            for (int i = 0; i < favorite.length; i++) {
                System.out.print(colors[favorite[i]] + (i == n - 1 ? "\n" : " "));
            }
        }
    }
    private static int go(int at, int[] perm, boolean[] used, String[] colors,
        HashMap<Integer, HashSet<Integer>> wastepairs) {

            if (at == perm.length) {
                if (favorite == null) {
                    favorite = Arrays.copyOf(perm, perm.length);
                }
                return 1;
            }

            int count = 0;
            for (int i = 0; i < colors.length; i++) {
                if (!used[i] && (at == 0 || !wastepairs.containsKey(perm[at - 1]) || !(wastepairs.get(perm[at - 1]).contains(i)))) {
                    used[i] = true;
                    perm[at] = i;
                    count += go(at+1, perm, used, colors, wastepairs);
                    used[i] = false;
                }
            }

            return count;
    }
}
