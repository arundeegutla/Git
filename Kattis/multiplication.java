import java.util.Scanner;

public class multiplication {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        

        while (in.hasNextLong()) {
            long n = in.nextLong();
            long counter = 2;
            long temp = 1;
            while (temp < n) {
                counter = counter == 2 ? 9 : 2;
                temp *= counter;
            }
            if (counter == 2) System.out.println("Ollie wins.");
            else System.out.println("Stan wins.");
        }
        
        in.close();
    }
}
