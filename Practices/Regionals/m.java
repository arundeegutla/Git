import java.util.Scanner;
/**
 * m
 */
public class m {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();
        System.out.println(getMin(line.length()/2 - 1, 0, 1, line.toCharArray(), line.length()));
    }

    private static int getMin(int at, int prevChanged, int prevMatch, char[] line, int len) {
        if(at==-1)
            return 0;

        
        
        if (prevChanged == 0 && prevMatch == 1) {
            if (line[at] == line[len - at - 1])
                return getMin(at-1, 0, 1, line, len);

            int changed = getMin(at-1, 1, 1, line, len) + 1;
            int didntchange = getMin(at-1, 0, 0, line, len);
            return Math.min(changed, didntchange);
        }
        

        return 0;
    }
}