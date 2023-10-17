import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.*;

public class ceremony {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] freq = new int[(int)1e6+1];
        for (int i = 0; i < n; i++)
            freq[in.nextInt()]++;
    
        int min = n;
        int removed = 0;
        for (int i = 1; i < freq.length; i++) {
            if (freq[i]>0) {
                removed+=freq[i];
                min = Math.min(min, i+n-removed);
            }
        }

        System.out.println(min);
    }
}
