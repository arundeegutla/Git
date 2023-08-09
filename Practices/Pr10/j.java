import java.util.Scanner;

public class j {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        int numLines;
        while((numLines = in.nextInt()) != 0){
            in.nextLine();
            String[] lines = new String[numLines];
            for (int i = 0; i < lines.length; i++)
                lines[i] = in.nextLine();

            int at = 0;
            for (int i = 0; i < lines.length; i++) {
                while (at < lines[i].length() && lines[i].charAt(at) != ' ') {
                    at++;
                }
            }

            System.out.println(at+1);
        }

    }
}
