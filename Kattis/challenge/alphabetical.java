import java.util.Scanner;

public class alphabetical {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String line = in.nextLine();

        int need = 0;
        for (int i = 0; i < line.length(); i++)
            if (line.charAt(i)-'a' == need)
                need++;
        System.out.println(26 - need);
    }

}
