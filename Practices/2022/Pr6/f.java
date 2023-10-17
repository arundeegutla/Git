import java.util.Scanner;

public class f {

    public static int lowest = -1;
    public static int numAnswers;
    public static String[] answers;
    public static int length;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        numAnswers = in.nextInt();
        int length = in.nextInt();
        in.nextLine();


        answers = new String[numAnswers];

        for (int i = 0; i < numAnswers; i++) {
            answers[i] = in.nextLine();
        }


        int[] perm = new int[length];    
        getLowestPerm(perm, 0, length);

        System.out.println(lowest);
        in.close();
    }

    public static void getLowestPerm(int[] perm, int k, int size) {

        if (k == size) {
            getLowest(perm);
        } else {

            for (int i = 0; i < 2; i++) {
                perm[k] = i;
                getLowestPerm(perm, k+1, size);
            }
        }

        
    }

    public static void getLowest(int[] solution){

        int thisLowest = Integer.MAX_VALUE;

        for (int i = 0; i < numAnswers; i++) {
            int thisScore = 0;

            for (int j = 0; j < solution.length; j++) {
                if (answers[i].charAt(j) == 'T' && solution[j] == 1) {
                    thisScore++;
                }
                else if (answers[i].charAt(j) == 'F' && solution[j] == 0){
                    thisScore++;
                }
            }
            if (thisScore < thisLowest) {
                thisLowest = thisScore;
            }
        }

        if (lowest < thisLowest) {
            lowest = thisLowest;
        }

    }
}
