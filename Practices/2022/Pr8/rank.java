import java.util.HashMap;
import java.util.Scanner;

import javax.swing.plaf.synth.SynthPasswordFieldUI;

public class rank {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), g = s.nextInt();

        String[] teamOrder = new String[n];
        for (int i = 0; i < n; i++) {
            teamOrder[i] = ("T" + (i + 1));
        }

        HashMap<String, Integer> currrank = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++)
            currrank.put(teamOrder[i], (i + 1));

        s.nextLine();
        for (int i = 0; i < g; i++) {
            String[] currg = s.nextLine().split(" ");
            String team1 = currg[0], team2 = currg[1];

            if (currrank.get(team1) > currrank.get(team2)) {
                int t1rank = currrank.get(team1);
                int t2rank = currrank.get(team2);

                for (int j = t2rank - 1; j < t1rank - 1; j++) {
                    teamOrder[j] = teamOrder[j + 1];
                    currrank.put(teamOrder[j], currrank.get(teamOrder[j]) - 1);
                }
                currrank.put(team2, t1rank);
                teamOrder[t1rank - 1] = team2;
            }
        }

        for (int i = 0; i < n; i++)
            System.out.print(teamOrder[i] + " ");
        System.out.println("");
    }
}
