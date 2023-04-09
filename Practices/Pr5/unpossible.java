
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class unpossible {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numCams = in.nextInt();

            int[] numHitting = new int[numCams];
            boolean[][] guards = new boolean[numCams][numCams];

            for (int j = 0; j < numCams - 1; j++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                guards[y][x] = true;
                numHitting[y]++;
            }

            ArrayList<Integer> q = new ArrayList<>();

            for (int j = 0; j < numCams; j++) {

                boolean hasGuard = false;
                for (int j2 = 0; j2 < numCams; j2++) {

                    if (guards[j][j2]) {
                        hasGuard = true;
                        break;
                    }
                }
                if (!hasGuard) {
                    q.add(j);
                }
            }


            while(q.size() != 0){
                int index = q.remove(0);
                System.out.println(index + 1);

                for (int j = 0; j < numCams; j++) {
                    if (guards[j][index]) {
                        numHitting[j]--;
                        if (numHitting[j] == 0) {
                            q.add(j);
                            Collections.sort(q);
                        }
                    }
                }
            }

        }

        in.close();
    }
}


