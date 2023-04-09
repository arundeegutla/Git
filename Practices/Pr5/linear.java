import java.util.Scanner;

public class linear {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            
            int a = in.nextInt();
            int b = in.nextInt();

            int lBound = in.nextInt();
            int uBound = in.nextInt();

            int total = 0;

            for (int j = lBound; j <= uBound; j++) 
            {
                
                double y = getFunction(a, b , j);


                if (y == (int)y) {

                    System.out.printf("(%d, %d)", j, (int)y);
                    System.out.println();
                    total++;
                } else {
                    System.out.printf("(%d, %.1000f)", j, y);
                    System.out.println();
                }

            }

            System.out.println(total);

        }

        in.close();
    }

    private static double getFunction(int a, int b, int x) {
        return (1/(double)b) - (((double)x/1)*((double)a/b));
    }


}
