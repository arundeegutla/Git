import java.util.Scanner;

public class c {
    static int count;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        count = 0;
        int n = in.nextInt();
        halfer(n);
        System.out.println(n - count); 
    }
    private static void halfer(int n) {
        if (n <= 0) {
            return; 
        }
        count++;
        halfer((int)n/2);
    }
}
