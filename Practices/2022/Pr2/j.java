import java.util.Scanner;

public class j {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numStars = in.nextInt();
        for (int i = 2; i < numStars; i++) {

            for (int j = 1; j >= 0; j--) {

                double div = 0;

                if (j == 1) {
                    div = (double)(numStars + (i-j)) / (i + (i-j));
                } 
                else div = (double)(numStars) / (i + (i-j));

                

                if(div == (int)div){
                    System.out.println("THISONE: " + i + " " + (i-j) + " " +div);
                }
            }
            
        }
    }
}
