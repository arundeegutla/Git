import java.util.*;
/**
 * h
 */
public class h {
    public static Team[] allTeams;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTeams = in.nextInt();
        int numProblems = in.nextInt();
        int numSubmissions = in.nextInt();
        int highestRank = in.nextInt();

        allTeams = new Team[numTeams];
        for (int i = 0; i < numTeams; i++)
            allTeams[i] = new Team(i+1, numProblems);

        for (int i = 0; i < numSubmissions; i++) {
            int teamId = in.nextInt() - 1;
            int problem = in.nextInt() - 1;
            int time = in.nextInt();
            int verdict = in.nextInt();
            if (time >= 300)
                continue;

            var curTeam = allTeams[teamId];

            if (curTeam.solvedTime[problem] != -1)
                continue;
            
            if (verdict == 0) {
                curTeam.WAs[problem]++;
            } else {
                curTeam.solvedTime[problem] = time;
                curTeam.ACs.add(problem);
            }
        }

        update();
        Arrays.sort(allTeams);

        int prevRank = 1;
        for (int i = 0; i < allTeams.length; i++) {
            if (i!=0 && allTeams[i].compareTo(allTeams[i-1]) != 0)
                prevRank = i+1;
            if (prevRank > highestRank)
                break;
            printTeam(allTeams[i], prevRank);
        }



    }

    private static void printTeam(Team team, int rank) {
        System.out.printf("%-4d%-4d%3d%5d\n", rank, team.teamId, team.numSolved, team.totalConsumed);
    }

    private static void update() {
        for (Team team : allTeams) {
            long total = 0;
            for (int problem : team.ACs) {
                team.numSolved++;
                team.timeConsumed[problem] = (20*team.WAs[problem]) + team.solvedTime[problem];
                total += team.timeConsumed[problem];
            }
            team.totalConsumed = total;
        }
    }
}


class Team implements Comparable<Team> {
    int teamId;
    int numSolved;
    long totalConsumed;
    long[] timeConsumed;

    int[] WAs;
    int[] solvedTime;
    ArrayList<Integer> ACs;

    public Team(int teamId, int numProblems) {
        this.teamId = teamId;
        this.WAs = new int[numProblems];
        this.solvedTime = new int[numProblems];
        this.timeConsumed = new long[numProblems];
        Arrays.fill(solvedTime, -1);
        this.ACs = new ArrayList<>();
    }

    @Override
    public int compareTo(Team o) {
        if (this.numSolved != o.numSolved)
            return o.numSolved - this.numSolved;
        if (this.totalConsumed != o.totalConsumed)
            return this.totalConsumed < o.totalConsumed ? -1 : 1;

        for (int i = numSolved-1; i >= 0; i--) {
            int myAC = this.ACs.get(i);
            int otherAC = o.ACs.get(i);
            if (this.timeConsumed[myAC] != o.timeConsumed[otherAC])
                return this.timeConsumed[myAC] < o.timeConsumed[otherAC] ? -1 : 1;
        }

        return 0;
    }

    @Override
    public String toString() {
        return "{" + teamId + ":::" + ACs.toString() + "}";
    }
}