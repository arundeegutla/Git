import java.util.Scanner;

public class seating {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numPeople = in.nextInt() * 2;

            int[] perm = new int[numPeople];
            boolean[] used = new boolean[numPeople];

            System.out.println(getMaxArrangements(numPeople, perm, used, 0));

        }

        in.close();
    }

    public static int getMaxArrangements(int numPeople, int[] perm, boolean[] used, int k) {
        if (k == numPeople) {

            return 1;
        }

        int numArranements = 0;

        if (k%2 == 0) {
            
            int i = 0;

            while(used[i]) i++;

            perm[k] = i;
            used[i] = true;
            numArranements = getMaxArrangements(numPeople, perm, used, k+1);

            used[i] = false;
        }

        else {
            for (int i = 0; i < numPeople; i++) {

                if (!used[i] && Math.abs(i - perm[k-1]) != 1) {
                    
                    perm[k] = i;
                    used[i] = true;
                    numArranements += getMaxArrangements(numPeople, perm, used, k+1);

                    used[i] = false;
    
                }
            }
        }
        

        return numArranements;
    }

}
