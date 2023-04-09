import java.util.HashSet;
import java.util.Scanner;

public class dancerecital {
    public static int MIN = (int)1e9;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numPerformances = in.nextInt();
        HashSet<Character>[] performances = new HashSet[numPerformances];

        for (int i = 0; i < numPerformances; i++) {
            char[] characters = in.next().toCharArray();
            performances[i] = new HashSet<>();
            for (char c : characters)
                performances[i].add(c);
        }

        int[] perm = new int[numPerformances];
        boolean[] used = new boolean[numPerformances];
        go(0, 0, performances, perm, used);
        System.out.println(MIN);
    }
    private static void go(int at, int total, HashSet<Character>[] performances, int[] perm, boolean[] used) {
        if (at == performances.length) {
            MIN = Math.min(MIN, total);
            return;
        }

        for (int i = 0; i < performances.length; i++) {
            if (!used[i]) {
                used[i] = true;
                perm[at] = i;

                if (at == 0)
                    go(at+1, 0, performances, perm, used);
                else {
                    int numChanges = total + getChanges(performances[perm[at - 1]], performances[i]);
                    if (numChanges < MIN)
                        go(at+1, numChanges, performances, perm, used);
                }
                
                used[i] = false;
            }
        }
    }
    private static int getChanges(HashSet<Character> before, HashSet<Character> after) {
        int changes = 0;
        for (char c : after)
            if (before.contains(c))
                changes++;
        return changes;
    }
}
