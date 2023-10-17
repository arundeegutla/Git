import java.util.HashMap;
import java.util.Scanner;

public class cipher {

    public static HashMap<String, Coordinate> ciphers;
    public static char[][] grid;
    public static boolean[] used;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        ciphers = new HashMap<>();
        grid = new char[5][5];
        used = new boolean[26];
        getCipher(in.nextLine().replace(" ", "").toUpperCase());


        String text = in.nextLine().replace(" ", "").toUpperCase();

        for (int i = 0; i < text.length(); i++) {
            char[] digraph = new char[2];

            if (i+1 >= text.length() || text.charAt(i) == text.charAt(i+1)) {
                digraph[0] = text.charAt(i);
                digraph[1] = 'X';
            } else {
                digraph[0] = text.charAt(i);
                digraph[1] = text.charAt(i+1);
                i++;
            }

            printEnCrypted(digraph);
            
        }

        System.out.println();

        in.close();

    }

    private static void printEnCrypted(char[] digraph) {

        int aRow = ciphers.get(digraph[0] + "").row;
        int aCol = ciphers.get(digraph[0] + "").column;
        int bRow = ciphers.get(digraph[1] + "").row;
        int bCol = ciphers.get(digraph[1] + "").column;

        if (aRow == bRow) {
            System.out.print(grid[aRow][(aCol + 1) % 5] + "" + grid[bRow][(bCol + 1) % 5]);
        } else if (aCol == bCol){
            System.out.print(grid[(aRow + 1) % 5][aCol] + "" + grid[(bRow + 1) % 5][bCol]);
        } else{
            System.out.print(grid[aRow][bCol] + "" + grid[bRow][aCol]);
        }

    }

    public static void getCipher(String key) {
        int at = 0;
        int lastUsed = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                while(at < key.length() && used[(int)(key.charAt(at) - 'A')]) at++;

                if (at < key.length()) {

                    grid[i][j] = key.charAt(at);
                    ciphers.put(key.charAt(at) + "", new Coordinate(i, j));
                    used[(int)(key.charAt(at) - 'A')] = true;

                } else {
                    while(lastUsed < 26 && used[lastUsed] || (char)((char)lastUsed + 'A') == 'Q') lastUsed++;
                    if(lastUsed < 26){

                        ciphers.put((char)((char)lastUsed + 'A') + "", new Coordinate(i, j));
                        grid[i][j] = (char)((char)lastUsed + 'A');
                        used[lastUsed] = true;
                    }
                    
                }

            }
        }

    }

    
}


class Coordinate{
    int row;
    int column;

    public Coordinate(int row, int column){
        this.row = row;
        this.column = column;
    }

    @Override
    public String toString() {
        return "{" + row + ", " + column + "}";
    }
}