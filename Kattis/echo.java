import java.util.Scanner;

public class echo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String w = in.nextLine();
        for (int i = 0; i < 3; i++) System.out.print(w + (i != 2 ? " " : "\n"));
        in.close();
    }
}