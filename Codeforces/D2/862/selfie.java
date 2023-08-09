import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class selfie {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numLines = in.nextInt();
            int numPrabo = in.nextInt();

            TreeSet<Double> lines = new TreeSet<>();
            for (int i = 0; i < numLines; i++) {
                lines.add(in.nextDouble());
            }

            for (int i = 0; i < numPrabo; i++) {
                long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
                double right = -Math.sqrt(4*a*c) + b;
                double negright = Math.sqrt(4*a*c) + b;

                if (right == 0) 
                    right = 0;
                    
                Double anss = lines.higher(right);
                if (anss != null && (double)anss < negright) {
                    double ans = anss;
                    System.out.println("YES");
                    System.out.println((int)ans);
                } else {
                    System.out.println("NO");
                }
            }
            System.out.println();
        }
    }   


    public static ArrayList<Double> getRoots(int a, int b, int c) {

        ArrayList<Double> list = new ArrayList<>();
        
        double firstroot, secondroot;
 
        double det = b * b - 4 * a * c;

        if (det > 0) {
            firstroot = (-b + Math.sqrt(det)) / (2 * a);
            secondroot = (-b - Math.sqrt(det)) / (2 * a);
 
            list.add(firstroot);
            list.add(secondroot);
        }
 
        // check if determinant is equal to 0
        else if (det == 0) {
 
            // two real and equal roots
            // determinant is equal to 0
            // so -b + 0 == -b
            firstroot = secondroot = -b / (2 * a);
            list.add(firstroot);
        }

        return list;
    }
}


class FastScanner {
    BufferedReader br; StringTokenizer st;
            public FastScanner() {
                try {
                    br = new BufferedReader(new InputStreamReader(System.in));
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e){e.printStackTrace();}
            }
            public String next() {
                if (st.hasMoreTokens()) return st.nextToken();
                try {st = new StringTokenizer(br.readLine());}
                catch (Exception e) {e.printStackTrace();}
                return st.nextToken();
            }
            public short nextShort() {return Short.parseShort(next());}
            public int nextInt() {return Integer.parseInt(next());}
            public long nextLong() {return Long.parseLong(next());}
            public double nextDouble() {return Double.parseDouble(next());}
            public String nextLine() {
                String line = "";
                if(st.hasMoreTokens()) 
    line = st.nextToken();
                else 
    try {return br.readLine();}catch(IOException e){e.printStackTrace();}
                while(st.hasMoreTokens()) line += " "+st.nextToken();
                return line;
            }
    }
    