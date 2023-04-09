import java.util.Scanner;

public class n_arun {

    public static int[] array;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numInts = in.nextInt();
        array = new int[numInts];

        for (int i = 0; i < numInts; i++) {
            array[i] = in.nextInt();
        }

        int[] perm = new int[3];
        boolean[] visited = new boolean[numInts];
        System.out.println(getAllTriangles(perm, visited, 0));

        in.close();

    }

    public static int getAllTriangles(int[] perm, boolean[] visited, int k) {

        if (k == 3) {
            return isValid(perm);
        }
        int totalTris = 0;
        for (int i = 0; i < array.length; i++) {
            if(!visited[i] && (k == 0 || array[perm[k-1]] < array[i])){
                visited[i] = true;
                perm[k] = i;
                totalTris += getAllTriangles(perm, visited, k+1);
                visited[i] = false;
            }
        }
        return totalTris;
    }

    public static int isValid(int[] perm) {


        if(array[perm[0]] + array[perm[1]] > array[perm[2]]){
            System.out.println("FOUND  " + array[perm[0]] + " + " + array[perm[1]] + " > " + array[perm[2]]);
        }
    
        return (((array[perm[0]] + array[perm[1]]) > array[perm[2]]) ? 1 : 0);
    }
}
