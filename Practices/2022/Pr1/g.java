import java.util.Arrays;
import java.util.Scanner;

public class g {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPeople = in.nextInt();
        
        int[] people = new int[numPeople];
        for (int i = 0; i < numPeople; i++) {
            people[i] = in.nextInt();
        }

        Arrays.sort(people);
        

    }
}
