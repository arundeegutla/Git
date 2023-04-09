import java.util.Scanner;

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numInputs = Integer.parseInt(in.nextLine());

        for (int i = 0; i < numInputs; i++) {
            String word = in.nextLine();


            int padding = (int)(Math.sqrt(word.length()) + 0.6);

            String strPadding = ""; 
            for (int j = 0; j < padding*padding - word.length(); j++) {
                strPadding += "*";
            }

            word += strPadding;


            char[][] grid = new char[padding][padding];

            int charat = 0;

            for (int j = padding-1; j >= 0; j--) {

                for (int j2 = 0; j2 < padding; j2++) {
                    grid[j2][j] = word.charAt(charat);
                    charat++;
                }
            }  

            for (int j = 0; j < padding; j++) {
                for (int j2 = 0; j2 < padding; j2++) {
                    if (grid[j][j2] != '*') {
                        System.out.print(grid[j][j2]);
                    }
                }
            }

            System.out.println();
        }
    }

}
