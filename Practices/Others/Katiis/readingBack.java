
import java.util.HashSet;
import java.util.Scanner;


public class readingBack {

    public static HashSet<Integer> culmanatings;
    public static boolean[][] dependecyMatrix;
    public static int[] pages;
    public static boolean[] read;
    public static int lowestFound = Integer.MAX_VALUE;
    public static boolean[] dontUSE;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numChapters = in.nextInt();
        int numDependencies = in.nextInt();

        pages = new int[numChapters];
        read = new boolean[numChapters];
        dependecyMatrix = new boolean[numChapters][numChapters];
        dontUSE = new boolean[numChapters];

        culmanatings = new HashSet<>();

        for (int i = 0; i < numChapters; i++) {
            pages[i] = in.nextInt();
        }

        for (int i = 0; i < numDependencies; i++) {
            int startIndex = in.nextInt() - 1;
            int toIndex = in.nextInt() - 1;
            dependecyMatrix[startIndex][toIndex] = true;
        }

        for (int i = 0; i < numChapters; i++) {
            boolean isEnd = true;

            for (int j = 0; j < numChapters; j++) {
                if (dependecyMatrix[i][j]) {
                    isEnd = false;
                }
            }
            if (isEnd) {
                culmanatings.add(i);
            }
        }

        boolean[] visited = new boolean[numChapters];
        int[] perm = new int[2];
        System.out.println(getLowestTwoChapter(perm, visited, 0));

        in.close();
    }

    public static int getLowestTwoChapter(int[] perm, boolean[] visited, int k) {

        if (k == 2){
            boolean[] used = new boolean[visited.length];
            return getLowest(perm, used);
        }

        for (int end : culmanatings) {
            if (!visited[end] && (k == 0 || perm[k-1] < end) && !dontUSE[end]) {
                visited[end] = true;
                perm[k] = end;
                
                int thisLowest = getLowestTwoChapter(perm, visited, k+1);

                if (thisLowest < lowestFound) {
                    lowestFound = thisLowest;
                }

                visited[end] = false;

            }
        }

        return lowestFound;
    }

    public static int getLowest(int[] perm, boolean[] used) {
        return pagesNeedToRead(perm[0], used) + pagesNeedToRead(perm[1], used);
    }

    private static int pagesNeedToRead(int id, boolean[] used) {

        int totalPages = 0;
        if (!used[id]) {
            totalPages = pages[id];
            used[id] = true;
        }

        for (int i = 0; i < pages.length; i++) {
            if (dependecyMatrix[i][id]) {
                totalPages += pagesNeedToRead(i, used);
            }
        }

        if (totalPages > lowestFound) {
            dontUSE[id] = true;
        }

        return totalPages;
    }

    public static void printMatrix() {
        for (int i = 0; i < dependecyMatrix.length; i++) {
            System.out.print(i+1 + ": ");
            for (int j = 0; j < dependecyMatrix.length; j++) {
                System.out.print(dependecyMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
