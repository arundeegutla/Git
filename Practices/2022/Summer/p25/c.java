import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int len = in.nextInt();
        if(len % 2 == 0) {
            System.out.println("NOT POSSIBLE");
            return;
        }

        String str = in.next();
        String fH = str.substring(0, len/2);
        String sH = str.substring((len/2)+1, len);

        if(fH.equals(sH)) {
            System.out.println(fH);
            return;
        }

        char[] u = str.toCharArray();
        char[] firstHalf = fH.toCharArray();
        char[] secondHalf = sH.toCharArray();

        boolean skipped = false;
        boolean second = false;
        for(int i = 0; i <= len/2; i++){
            if(u[i] != secondHalf[i - (skipped==true?1:0)]) {
                if(skipped) break;
                skipped = true;
                continue;
            }
            if(i - (skipped==true?1:0) == (len/2) - 1){
                second = true;
                break;
            }
        }

        skipped = false;
        boolean first = false;
        for(int i = len/2; i < len; i++) {
            int o = i - (len/2) - (skipped==true?1:0);
            if(u[i] != firstHalf[o]) {
                if(skipped) break;
                skipped = true;
                continue;
            }
            if(o == (len/2) - 1) {
                first = true;
                break;
            }
        }

        if(first && second)
            System.out.println("NOT UNIQUE");
        else if (first)
            System.out.println(fH);
        else if (second)
            System.out.println(sH);
        else 
            System.out.println("NOT POSSIBLE");
    }
}
