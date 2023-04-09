import java.util.Scanner;

public class prob12 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        String name;

        while (!(name = in.nextLine()).equals("End")) {

            boolean lead = false;
            boolean flex = false;
            boolean involve = false;
            boolean plan = false;

            String line;
            while ( !(line = in.nextLine().toLowerCase()).equals("")) {
                if (line.contains("lead"))
                    lead = true;
                if (line.contains("flexib"))
                    flex = true;
                if (line.contains("involve"))
                    involve = true;
                if (line.contains("plan"))
                    plan = true;
            }

            if (lead && flex && involve && plan) {
                System.out.println(name + ": Meets standards");
            } else 
                System.out.println(name + ": Does not meet standards");
        }
    }
}