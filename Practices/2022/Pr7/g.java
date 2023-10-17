import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;

public class g {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        HashMap<String, Integer> allVariants = new HashMap<>();
        Queue<String> q = new ArrayDeque<>();


        String beg = in.nextLine();
        String end = in.nextLine();


        allVariants.put(beg, 0);
        q.add(beg);


        while (!allVariants.containsKey(end)) {

            String str = q.poll();

            for (int i = 0; i < 8; i++) {

                String variant = click(i, str);

                if (!allVariants.containsKey(variant)) {
                    q.add(variant);
                    allVariants.put(variant, allVariants.get(str) + 1);
                }
                
            }
        }
        
        System.out.println(allVariants.get(end));

        in.close();

    }


    private static String click(int index, String form) {

        if (form.charAt(index) == 'A') return clickedA(index, form);
        else if (form.charAt(index) == 'B') return clickedB(index, form);
        else if (form.charAt(index) == 'C') return clickedC(index, form);
        else if (form.charAt(index) == 'D') return clickedD(index, form);
        else if (form.charAt(index) == 'E') return clickedE(index, form);
        else if (form.charAt(index) == 'F') return clickedF(index, form);

        return form;
    }



    
    private static String clickedF(int index, String str) {

        index++;

        if (index % 2 == 0) return rotate((index/2) - 1, str);
        return rotate(((index+9)/2) - 1, str);
    }

    private static String clickedE(int index, String str) {

        if (index == 0 || index == 7) return str;


        int y = Math.min(index, 7 - index);

        str = rotate(index - y, str);
        str = rotate(index + y, str);

        return str;
    }

    private static String clickedD(int index, String str) {

        if (index == 0 || index == 7) return str;

        int start, end;

        if(index <= 3){
            start = 0;
            end = index;
        } else {
            start = index + 1;
            end = 8;
        }

        for (int i = start; i < end; i++)
            str = rotate(i, str);

        return str;
    }


    private static String clickedC(int index, String str) {
        return rotate(7-index, str);
    }

    private static String clickedB(int index, String str) {
        if (index == 0 || index == 7) return str;

        StringBuilder res = new StringBuilder(str); 
        res.setCharAt(index+1, (str.charAt(index-1)));
        return res.toString();
    }


    private static String clickedA(int index, String str) {

        if (index-1 >= 0) str = rotate(index - 1, str);
        if (index+1 <= 7) str = rotate(index + 1, str);

        return str;
    }

    private static String rotate(int index, String str){

        StringBuilder res = new StringBuilder(str);

        char newChar = (char)(str.charAt(index) + 1);
        
        if (str.charAt(index) == 'F')
            newChar = 'A';

        res.setCharAt(index, newChar);

        return res.toString();

    }

}