import java.util.Scanner;

public class repetetion {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int max = 1;
        int count = 1;
        String line = in.nextLine();
        for (int i = 0; i+1 < line.length(); i++) {
            if (line.charAt(i) == line.charAt(i+1)) {
                count++;
                max = Math.max(max, count);
            }else{
                count = 1;
            }
        }
        System.out.println(max);
    }
}
