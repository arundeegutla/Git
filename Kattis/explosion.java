import java.util.Scanner;

public class explosion {

    public static int total = 0;
    public static int win = 0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int d = in.nextInt();

        int myMinions = 0;
        int otherMinions = 0;

        for (int i = 0; i < n; i++)
            myMinions += in.nextInt();
        for (int i = 0; i < m; i++)
            otherMinions += in.nextInt();

        boolean[][][] visited = new boolean[myMinions + 1][otherMinions + 1][d + 1];
    
        getAll(myMinions, otherMinions, d, visited);

        System.out.println(win + " " + total);
        System.out.println((double)win/total);

    }
    private static void getAll(int myMinions, int otherMinions, int d, boolean[][][] visited) {

        if (otherMinions == 0) {
            win++;
            visited[myMinions][otherMinions][d] = true;
        }

        if(d == 0) {
            total++;
            visited[myMinions][otherMinions][d] = true;
            System.out.println(myMinions + " " + otherMinions + " " + d);
        }

        if (myMinions > 0 && d > 0)
            getAll(myMinions-1, otherMinions, d-1, visited); 
        if(otherMinions > 0  && d > 0)
            getAll(myMinions, otherMinions-1, d-1, visited);

        visited[myMinions][otherMinions][d] = true;
    }
}