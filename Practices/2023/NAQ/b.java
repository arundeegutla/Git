import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * b
 */
public class b {

    public static int getCount(String s, String d) {
        String ss = new String(s);
        int ssSize = ss.length();
        ss = ss.replaceAll(d, "-");
        int count = (ssSize - ss.length()) / (d.length() - 1);
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.next();

        String[] digits = { "eight", "three", "seven", "zero", "four", "five", "nine", "six", "one", "two" };

        StringBuilder str = new StringBuilder(s);
        long tot = 1;
        long MOD = 9302023L;

        while (true) {
            boolean changed = false;

            int index3 = str.indexOf("threeighth");
            int index8 = str.indexOf("eighthreei");
            if (index3 == -1 && index8 == -1)
                break;

            if (index3 != -1 && (index3 < index8 || index8 == -1)) {
                int at = ("threeighth").length() - 2;
                while (str.indexOf("threeighth", at) == at) {
                    at += ("threeighth").length();
                    at -= 2;
                }
                if (str.indexOf("eight", at + 4) != -1) {
                    tot *= 2;
                    tot %= MOD;
                }
                System.out.println("3 series " + (index3) + " " + (index3 + 4));
                String hereS = str.substring(index3, at + 5);
                System.out.println(hereS);
                hereS = hereS.replaceAll("three", "-");
                System.out.println(hereS);

                str = str.replace(index3, at + 5, hereS);

                changed = true;
            } else if (index8 != -1 && (index8 < index3 || index3 == -1)) {
                int at = ("eighthreei").length() - 2;
                while (str.indexOf("eighthreei", at) == at) {
                    at += ("eighthreei").length();
                    at -= 2;
                }
                if (str.indexOf("three", at + 4) != -1) {
                    tot *= 2;
                    tot %= MOD;
                }
                String hereS = str.substring(index8, at + 5);
                hereS = hereS.replaceAll("eight", "-");
                str.replace(index8, at + 5, hereS);
                changed = true;
            }

            if (!changed) {
                break;
            } else {
                System.out.println(str);
            }
        }

        s = str.toString();

        int get38 = getCount(s, "threeight");
        int get83 = getCount(s, "eighthree");
        long getTwo = getCount(s, "twone");

        for (int i = 0; i < get38; i++) {
            tot *= 2;
            tot %= MOD;
        }

        for (int i = 0; i < getTwo; i++) {
            tot *= 2;
            tot %= MOD;
        }

        for (int i = 0; i < get83; i++) {
            tot *= 2;
            tot %= MOD;
        }

        for (String d : digits) {
            s = s.replaceAll(d, "-");
        }

        System.out.println(s.length());
        System.out.println(tot);

    }
}