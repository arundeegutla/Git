import java.util.Arrays;
import java.util.Scanner;

/**
 * f
 */
public class f {

    public static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int n = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= n; i++) {
            System.out.print("Case #" + i + ": ");solve();
        }
    }

    private static void solve() {
        String[] verses = in.nextLine().split(", ");

        int n = verses.length;
        // System.out.println(Arrays.toString(verses));

        verses[n-1] = verses[n-1].substring(0, verses[n-1].length()-1);
        int[] syllables = new int[n];
        for (int i = 0; i < n; i++) {
            loop:for(var s : verses[i].split(" ")){
                if(s.length() == 6) {
                    if(s.contains("ng") || s.contains("ny")){
                        syllables[i] += 2;
                        continue loop;
                    }
                }
                if(s.length() == 3) {
                    if("aeiou".contains(s.charAt(0)+"")){
                        syllables[i] += 2;
                        continue loop;
                    }
                }
                if(s.length() >= 6){
                    syllables[i] += 3;
                } else if (s.length() >= 4) {
                    syllables[i] += 2;
                } else {
                    syllables[i] += 1;
                }
            }
            
        }
        int[] points = new int[5];
        
        for(int i = 0; i < Math.min(n, 4); i++)
            points[0] += syllables[i] >= 8 && syllables[i] <= 12 ? 10 : 0;

        for(int i = 0; i+2 < Math.min(n, 4); i++)
            if(verses[i].substring(verses[i].length()-2, verses[i].length()).equals(verses[i+2].substring(verses[i+2].length()-2, verses[i+2].length())))
                points[1] += 20;

        for(int i = 0; i+2 < Math.min(n, 4); i++)
            if(syllables[i] == syllables[i+2])
                points[2] += 10;

        points[3] = n>4?(n-4)*10:0;

        for(int i = 0; i < 3; i++)
            points[4] += points[i];
        points[4] -= points[3];
        for(int i = 0; i < 5; i++){
            System.out.print(points[i] + (i==4?"\n":" "));
        }
    }
    
}