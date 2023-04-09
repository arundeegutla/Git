import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class units {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numUnits = in.nextInt();

        while (numUnits != 0) {
            
            HashMap<String, Integer> index = new HashMap<>();
            HashMap<Integer, String> unit = new HashMap<>();

            Dist[][] conversions = new Dist[numUnits][numUnits];

            for (int i = 0; i < numUnits; i++) {
                String u = in.next();
                unit.put(i, u);
                index.put(u, i);
            }
            
            for (int i = 0; i < numUnits - 1; i++) {
                
                String a = in.next();
                in.next();
                long num = in.nextLong();
                String b = in.next();



                conversions[index.get(a)][index.get(b)] = new Dist(new BigInteger(String.valueOf(num)), new BigInteger("1"));
                conversions[index.get(b)][index.get(a)] = new Dist(new BigInteger("1"), new BigInteger(String.valueOf(num)));

            }

            for (int i = 0; i < numUnits; i++) {
                DFS(i, conversions);
            }



            // printArray(conversions);
            
    
            int start = 0;

            for (int i = 0; i < conversions.length; i++) {
                if (checkIncreasing(conversions[i])) {
                    start = i;
                }
            }

            // printArray(conversions[start]);

            boolean[] visited = new boolean[numUnits];

            visited[start] = true;
            System.out.print(1 + "" + unit.get(start) + " = ");

            for (int i = 1; i < numUnits; i++) {

                BigInteger lowest = new BigInteger("-1");
                int dex = -1;

                for (int j = 0; j < numUnits; j++) {

                    BigInteger thisDist = convertToLong(conversions[start][j]);

                    if (!visited[j] && (lowest.compareTo(new BigInteger("-1")) == 0 || lowest.compareTo(thisDist) == 1)) {
                        lowest = thisDist;
                        dex = j;
                    }
                }

                visited[dex] = true;
                System.out.print(lowest.toString() + "" + unit.get(dex) + (i != numUnits - 1 ? " = " : "\n"));

            }

            numUnits = in.nextInt();
        }


        in.close();

        


    }

    private static void printArray(Dist[] conversions) {

        for (int i = 0; i < conversions.length; i++) {
            System.out.print(convertToLong(conversions[i]) + " ");
        }

        System.out.println();

    }

    private static BigInteger convertToLong(Dist dist) {
        if (dist == null) {
            return new BigInteger("0");
        }
        return dist.numerator.divide(dist.denominator);
    }

    private static boolean checkIncreasing(Dist[] ds) {
        for (int i = 0; i < ds.length; i++) {

            if (ds[i] != null && ds[i].numerator.compareTo(ds[i].denominator) <= 0) {
                return false;
            }

        }
        return true;
    }

    private static void DFS(int index, Dist[][] conversions) {

        boolean[] visited = new boolean[conversions.length];
        
        DFS(index, index, conversions, visited, new BigInteger("1"), new BigInteger("1"));

    }

    private static void DFS(int start, int index, Dist[][] conversions, boolean[] visited, BigInteger top, BigInteger bottom) {

        visited[index] = true;

        for (int i = 0; i < visited.length; i++) {
            if (!visited[i] && conversions[index][i] != null) {

                BigInteger numerator = new BigInteger(String.valueOf(top)).multiply(conversions[index][i].numerator);
                BigInteger denominator = new BigInteger(String.valueOf(bottom)).multiply(conversions[index][i].denominator);
                
                conversions[start][i] = new Dist(numerator, denominator);

                DFS(start, i, conversions, visited, numerator, denominator);
            }
        }
    }

}


class Dist{

    BigInteger numerator;
    BigInteger denominator;

    public Dist(BigInteger numerator, BigInteger denominator){
        this.numerator = numerator;
        this.denominator = denominator;
    }

    @Override
    public String toString() {
        return "{" + numerator + ", " + denominator + "} ";
    }

}