import java.util.*;
public class dice {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int g = in.nextInt() + in.nextInt() + in.nextInt() + in.nextInt();
        int e = in.nextInt() + in.nextInt() + in.nextInt() + in.nextInt();
        if (g>e) System.out.println("Gunnar");
        else if (e>g) System.out.println("Emma");
        else System.out.println("Tie");
    }
}
