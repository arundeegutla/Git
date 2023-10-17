import java.util.Scanner;
/**
 * chocolate
 */
public class chocolate {
    public static String[] combos = "SS SV SC TV TS TC RV RS RC".split(" ");
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        for (int i = 1; i <= numCases; i++) {
            System.out.printf("Puzzle #%d:\n", i);
            solve(in);
        }
    }

    private static void solve(Scanner in) {
        int c = in.nextInt();
        Clue[] allClues = new Clue[c];
        for (int i = 0; i < allClues.length; i++) {
            Clue curClue = new Clue(in.nextInt(), in.nextInt());

            for (int j = 0; j < curClue.n; j++) {
                for (int k = 0; k < curClue.m; k++) {
                    String str = in.next();
                    curClue.p[j][k] = new Pair(str.charAt(0), str.charAt(1));
                }
            }

            allClues[i] = curClue;
        }


        int[] perm = new int[combos.length];
        boolean[] used = new boolean[combos.length];
        go(0, perm, used, allClues);
        
    }

    private static boolean go(int at, int[] perm, boolean[] used, Clue[] allClues) {
        if (at == perm.length) {
            if (allGood(perm, allClues)) {
                printPuzzle(perm);
                return true;
            }
            return false;
        }

        for (int i = 0; i < perm.length; i++) {
            if (!used[i]) {
                used[i] = true;
                perm[at] = i;
                if(go(at+1, perm, used, allClues)) return true;
                used[i] = false;
            }
        }

        return false;
    }

    private static boolean allGood(int[] perm, Clue[] allClues) {

        loop : for (Clue clue : allClues) {
            
            // Clue top left testing.
            for (int i = 0; i <= 3-clue.n; i++) {
                Jloop: for (int j = 0; j <= 3-clue.m; j++) {
                    
                    // test all pairs in curGroup;
                    for (int k = 0; k < clue.n; k++) {
                        for (int l = 0; l < clue.m; l++) {

                            int puzzleRow = i+k;
                            int puzzleCol = j+l;

                            int permAt = 3*puzzleRow+puzzleCol;
                            Pair p = clue.p[k][l];
                            if(!((p.first=='_' || p.first==combos[perm[permAt]].charAt(0)) && (p.second=='_' || p.second==combos[perm[permAt]].charAt(1))))
                                continue Jloop;
                            
                        }
                    }

                    // Worked for every pair in the clue.
                    continue loop;
                }

            }
            // Didnt work;
            return false;
        }

        return true;
    }

    private static void printPuzzle(int[] perm) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int at = 3*i+j;
                System.out.print(combos[perm[at]] + (j==2?"\n":" "));
            }
        }
        System.out.println();
    }
}

class Clue {
    int n, m;
    Pair[][] p;
    Clue(int n, int m) {
        this.n = n;
        this.m = m;
        p = new Pair[n][m];
    }
}

class Pair {
    char first;
    char second;
    Pair(char first, char second) {
        this.first = first;
        this.second = second;
    }
}