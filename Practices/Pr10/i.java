import java.util.Calendar;
import java.util.Scanner;

public class i {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int distance, sp1, sp2;

        while ((distance = in.nextInt()) != 0 && (sp1 = in.nextInt()) != 0 && (sp2 = in.nextInt()) != 0) {
            
            
            int hour1 = distance/sp1;
            distance %= sp1;
            int minute1 = (int)(distance/((double)sp1/60));
            distance %= ((double)sp1/60);
            int second1 = (int)(distance/((double)sp1/3600));
            distance %= ((double)sp1/3600);


            int hour2 = distance/sp2;
            distance %= sp2;
            int minute2 = (int)(distance/((double)sp2/60));
            distance %= ((double)sp2/60);
            int second2 = (int)(distance/((double)sp2/3600));
            distance %= ((double)sp2/3600);


            Calendar cal = Calendar.getInstance();
            cal.set(2022, 1, 1, hour1, minute1, second1);
            Calendar cal2 = Calendar.getInstance();
            cal.set(2022, 1, 1, hour2, minute2, second2);


            System.out.println(cal.getTimeInMillis() - cal2.getTimeInMillis());

        }
    }
}
