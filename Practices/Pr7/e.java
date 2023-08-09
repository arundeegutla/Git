import java.util.Scanner;

public class e {

    public static final int N = (int) (1e7 + 10);
    public static int[] mobius = new int[N];

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        mobius();

        int start1 = in.nextInt();
        int end1 = in.nextInt();

        
        int start2 = in.nextInt();
        int end2 = in.nextInt();


        long tot = 0;
        for (int i = 1; i < N; i++) {
            tot += (long)mobius[i] * getLengthOfFactors(start1, end1, i) * getLengthOfFactors(start2, end2, i); 
        }

        System.out.println(tot);

        in.close();
    }

    
    private static long getLengthOfFactors(int start1, int end1, int x) {
        
        int aFactors = (int) (start1 - 1)/x;
        int bFactors = (int) (end1)/x;

        return bFactors - aFactors;
    }


    public static void mobius() {
        mobius[1] = 1;
        for (int i = 1; i < N; i++)
            for (int j = i + i; j < N; j += i)
                mobius[j] -= mobius[i];
    }

    
}


