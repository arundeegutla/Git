import java.util.Scanner;

public class problem99 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String numberAsString = in.nextLine();
        int number = 0;
        int lastTwoDigits = 0;

        for (int i = 0; i < numberAsString.length(); i++) {
            number = number*10 + (int)(numberAsString.charAt(i) - '0');
            if (i > numberAsString.length() - 3) {
                lastTwoDigits = lastTwoDigits*10 + (int)(numberAsString.charAt(i) - '0');
            }
        }

        if (number < 149) {
            System.out.println(99);
        } else {
            if (lastTwoDigits >= 49) {

                number /= 100;
                number = number*100 + 99;
                
                System.out.println(number);
            } else {
                number /= 100;
                number = number*100;
                
                System.out.println(number - 1);
            }

        }

        in.close();

    }
}
