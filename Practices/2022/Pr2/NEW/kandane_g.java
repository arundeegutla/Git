import java.util.Scanner;

public class kandane_g {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String rain = in.nextLine();

        int[] blues = new int[rain.length()];
        int[] reds = new int[rain.length()];

        for (int i = 0; i < rain.length(); i++) {

            if (rain.charAt(i) == 'B'){
                blues[i]++;
                reds[i]--;
            }
            else{
                reds[i]++;
                blues[i]--;
            }
        }


        int blueLeft = 0;
        int blueRight = 0;
        int blueMax = Integer.MIN_VALUE;
        int sum = 0;
        int tempLeft = 0;
 
        for (int i = 0; i < blues.length; i++) {
            sum += blues[i];
            if (blueMax < sum) {
                blueMax = sum;
                blueLeft = tempLeft;
                blueRight = i;
            }
            if (sum < 0){
                sum = 0;
                tempLeft = i + 1;
            }
        }



        int redMax = Integer.MIN_VALUE;
        sum = 0;
        tempLeft = 0;
        int redLeft = 0;
        int redRight = 0;

        for (int i = 0; i < reds.length; i++) {
            sum += reds[i];
            if (redMax < sum) {
                redMax = sum;
                redLeft = tempLeft;
                redRight = i;
            }
            if (sum < 0){
                sum = 0;
                tempLeft = i + 1;
            }
        }

    
        if (blueMax > redMax) {
            System.out.println((blueLeft + 1) + " " + (blueRight + 1));
        } else if (redMax > blueMax) {
            System.out.println((redLeft + 1) + " " + (redRight + 1));
        } else {
            if (blueLeft < redLeft) {
                System.out.println((blueLeft + 1) + " " + (blueRight + 1));
            }else if (redLeft < blueLeft) {
                System.out.println((redLeft + 1) + " " + (redRight + 1)); 
            } else {
                if ((blueRight - blueLeft) < (redRight - redLeft)) {
                    System.out.println((blueLeft + 1) + " " + (blueRight + 1));
                } else 
                    System.out.println((redLeft + 1) + " " + (redRight + 1)); 
            }
        }
            

        
    }


}

// BBRRBRRBRB 3 7
// BBRBBRRB 1 5