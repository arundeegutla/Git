import java.util.*;

public class datum {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        int day = in.nextInt();
        int month = in.nextInt();

        Calendar date = Calendar.getInstance();

        date.set(2009, month-1, day);

        int week = date.get(Calendar.DAY_OF_WEEK);
        
        if (week == 7) {
            System.out.println("Saturday");
        } else if(week == 6){
            System.out.println("Friday");
        } else if(week == 5){
            System.out.println("Thursday");
        } else if(week == 4){
            System.out.println("Wednesday");
        } else if(week == 3){
            System.out.println("Tuesday");
        } else if(week == 2){
            System.out.println("Monday");
        } else if(week == 1){
            System.out.println("Sunday");
        }

        in.close();
        
    }



}
