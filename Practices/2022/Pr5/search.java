import java.util.Scanner;

public class search {

    public static int[][] D = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numWords = in.nextInt();
        in.nextLine();

        int p = 0;
        while(numWords != 0){

            p++;
            String[] words = new String[numWords];
            for (int i = 0; i < numWords; i++) {
                words[i] =  in.nextLine();
            }

            int numSizeR = in.nextInt();
            int numSizeC = in.nextInt();
            in.nextLine();

            char[][] grid = new char[numSizeR][numSizeC];

            for (int i = 0; i < numSizeR; i++) {
                
                String val = in.nextLine();

                for (int j = 0; j < numSizeC; j++) {
                    grid[i][j] = val.charAt(j);
                }
            }

            System.out.println("Puzzle number " + p + ":");
            boolean found = true;
            for (String cs : words) {

                if(!isInGrid(cs, grid, numSizeR, numSizeC)){
                    System.out.println(cs);
                    found = false;
                }
            }

            if (found) {
                System.out.println("ALL WORDS FOUND");
            }

            System.out.println();

            numWords = in.nextInt();
            in.nextLine();
        }

        in.close();
        


     }

    public static boolean isInGrid(String word, char[][] grid, int numSizeR, int numSizeC) {
        
        for (int i = 0; i < numSizeR; i++) {
            for (int j = 0; j < numSizeC; j++) {
                if (word.charAt(0) == grid[i][j]) 
                {
                    for (int j2 = 0; j2 < D.length; j2++) 
                    {
                        if (isInGrid(word, grid, numSizeR, numSizeC, 0, j2, i, j)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    public static boolean isInGrid(String word, char[][] grid, int numSizeR, int numSizeC, int k, int path, int startR, int startC) {

        if (k == word.length() - 1 && word.charAt(k) == grid[startR][startC]) {
            return true;
        }

        if (word.charAt(k) != grid[startR][startC]) {
            return false;
        }

        startR = startR + D[path][0];
        startC = startC + D[path][1];


        if (startR < 0 || startC < 0) {
            return false;
        }

        if (startR >= numSizeR || startC >= numSizeC) {
            return false;
        }

        
        return isInGrid(word, grid, numSizeR, numSizeC, k+1, path, startR, startC);
    }
}
