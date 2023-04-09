import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        in.nextLine();

        in.next();
        
        while(in.hasNextLine()){
            System.out.println(in.nextLine());
            in.next();
        }
    }
}
