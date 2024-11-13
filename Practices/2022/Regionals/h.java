import java.util.*;
class h {
    public static void main(String[] a) {
        Scanner n = new Scanner(System.in);
        int ss = n.nextInt();
        int st = n.nextInt();
        int ms = n.nextInt();
        int mt = n.nextInt();
        for (int i = 1; i<=5000; i++) {
            int s = i+ss;
            int m = i+ms;
            if(s % st == 0 && m % mt == 0) {
                System.out.print(i);
                return;
            }
        }
    }
}
