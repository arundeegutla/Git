import java.util.PriorityQueue;
import java.util.Scanner;

public class narrowArtPQ {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numRows = in.nextInt();
        int numToOff = in.nextInt();


        while (numRows != 0 && numToOff != 0) {

            int[][] rooms = new int[numRows][2];
            boolean[][] used = new boolean[numRows][2];
            PriorityQueue<Cell> q = new PriorityQueue<>();

            int total0 = 0;
            int total1 = 0;

            for (int i = 0; i < numRows; i++) {
                rooms[i][0] = in.nextInt();
                rooms[i][1] = in.nextInt();

                total0 += rooms[i][0];
                total1 += rooms[i][1];


                q.add(new Cell(i, 0, rooms[i][0]));
                q.add(new Cell(i, 1, rooms[i][1]));
            }

            if (numToOff == numRows) {

                System.out.println(Math.max(total1, total0));

            } else{

                while (numToOff > 0) {
                    
                    // printGrid(used, rooms);
                    // System.out.println();

                    Cell thisCell = q.poll();
    
                    if (!isInTheWay(thisCell, used)) {
    
                        if (thisCell.col == 0)
                            total0 -= thisCell.amount;
                        else
                            total1 -= thisCell.amount;
    
                        numToOff--;
                        used[thisCell.level][thisCell.col] = true;
                    }
    
                }
    
                System.out.println(total0 + total1);

            }

            
            numRows = in.nextInt();
            numToOff = in.nextInt();
        }



    }

    private static boolean isInTheWay(Cell thisCell, boolean[][] used) {

        if (thisCell.col == 0 && used[thisCell.level][1]) {
            return true;
        }

        if (thisCell.col == 1 && used[thisCell.level][0]) {
            return true;
        }

        int top = thisCell.level - 1;
        int bottom = thisCell.level + 1;
        int other = thisCell.col == 1 ? 0 : 1;

        if (top >= 0 && used[top][other]) {
            return true;
        }

        if (bottom < used.length && used[bottom][other]) {
            return true;
        }

        return false;
    }


    private static void printGrid(boolean[][] used, int[][] rooms) {

        int missing = 0;
        for (int i = 0; i < rooms.length; i++) {

            if (!used[i][0]) {
                System.out.print(rooms[i][0] + " ");
            }else{
                missing++;
                System.out.print("  ");
            }

            if (!used[i][1]) {
                System.out.print(rooms[i][1] + " ");
            }else{
                missing++;
                System.out.print("  ");
            }

            System.out.println(missing);

        }
    }
}

class Cell implements Comparable<Cell>{
    
    int level;
    int col;
    int amount;

    public Cell(int level, int col, int amount){
        this.level = level;
        this.col = col;
        this.amount = amount;
    }
    
    @Override
    public int compareTo(Cell o) {
        return this.amount - o.amount;
    }

    @Override
    public String toString() {
        return amount + "";
    }

}