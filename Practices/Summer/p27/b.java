import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * b
 */
public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Value> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            for (int j = 0; j < l; j++) {
                list.add( new Value(in.nextInt(), i, j));
            }
        }
        Collections.sort(list);
        System.out.println(list);
    }
}

class Value implements Comparable<Value> {
    int num;
    int row;
    int col;
    Value(int num, int row, int col) {
        this.num = num;
        this.col = col;
        this.row = row;
    }
    @Override
    public int compareTo(Value o) {
        if(o.row == row) 
            return this.col - o.col;
        return this.num - o.num;
    }
    @Override
    public String toString() {
        return "{" + num + ", " + row + ", " + col + "}";
    }
}