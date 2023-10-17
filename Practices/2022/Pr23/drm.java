import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.*;

public class drm {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String word = in.nextLine();

        char[] first = word.substring(0, word.length()/2).toCharArray();
        char[] second = word.substring(word.length()/2).toCharArray();

        int r1 = 0;
        int r2 = 0;
        

        for (char c : first)  r1 += c-'A';
        for (int i = 0; i < first.length; i++)  {
            first[i] = (char)(((first[i]-'A' + r1) % 26) + 'A');
        }

        for (char c : second) r2 += c-'A';
        for (int i = 0; i < second.length; i++) 
            second[i] = (char)(((second[i]-'A' + r2) % 26) + 'A');

        StringBuilder str = new StringBuilder();

        for (int i = 0; i < second.length; i++) {
            str.append((char)(( ((first[i]-'A') + (second[i]-'A')) % 26) + 'A'));
        }

        System.out.println(str);
    }
}
