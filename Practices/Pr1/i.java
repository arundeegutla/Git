import java.util.Scanner;

public class i {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numInstructions = Integer.parseInt(in.nextLine());

        for (int i = 0; i < numInstructions; i++) {
            String instruct = in.nextLine();

            if(instruct.indexOf("Simon says") == 0){
                System.out.println(instruct.substring(10));
            }
        }

        in.close();
    }
}
