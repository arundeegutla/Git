import java.util.HashSet;
import java.util.Scanner;

public class keywords {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashSet<String> set = new HashSet<>();
        int numStrs = in.nextInt();
        in.nextLine();
        while (numStrs-->0)
            set.add(in.nextLine().toLowerCase().replaceAll("-", " "));
        System.out.println(set.size());
    }
}
