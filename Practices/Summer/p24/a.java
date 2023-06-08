import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] D = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {-1, -1},{1, 1}};
        while (n-->0) {
            int x = in.nextInt();
            int[][] grid = new int[x*x][x*x];

            int[] count = new int[x*x];
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    for (int[] d : D) {
                        int nRow = i+d[0];
                        int nCol = j+d[1];
                        if(nRow<0||nRow>=(x)||nCol<0||nCol>=(x)) continue;

                        int from = (i*(x))+j;
                        int to = (nRow*(x))+nCol;
                        grid[from][to] = 1;
                        count[from]++;
                    }
                }
            }

            double[][] matrix = new double[x*x][x*x];

            for (int i = 0; i < x*x; i++) {
                for (int j = 0; j < x*x; j++) {
                    if(i!=j){
                        matrix[i][j] = grid[i][j] == 1? -1:0;
                        continue;
                    }
                    matrix[i][j] = count[i];
                }
            }

            double[][] newMatrix = new double[(x*x) - 1][(x*x) - 1];
            for (int i = 0; i < newMatrix.length; i++) {
                for (int j = 0; j < newMatrix.length; j++) {
                    newMatrix[i][j] = matrix[i+1][j+1];
                }
            }

            double ans = det(newMatrix);
            System.out.println((long)Math.round(ans));
            
        }
    }
    private static double det(double[][] matrix) {
        int n = matrix.length;
        double res = 1;
        for (int i = 0; i < n; i++) {
            int b = i;
            for (int j = i+1; j < n; j++) {
                if(Math.abs(matrix[j][i]) > Math.abs(matrix[b][i])) 
                    b = j;
            }

            if(i!=b){
                double[] temp = Arrays.copyOf(matrix[i], n);
                matrix[i] = matrix[b];
                matrix[b] = temp;
                res *= -1;
            }

            res *= matrix[i][i];
            
            if(res == 0) {
                // System.out.println("break");
                return 0;
            }

            for (int j = i+1; j < matrix.length; j++) {
                double v = matrix[j][i] / matrix[i][i];
                if(v!=0) {
                    for (int k = i+1; k < matrix.length; k++) {
                        matrix[j][k] -= v*matrix[i][k];
                    }
                }
            }
        }

        return res;
    }
}