import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numNums = in.nextInt();
            
            if(numNums == 1){
                System.out.println(in.nextInt());
                continue;
            }

            long[] arr = new long[numNums];
            for (int i = 0; i < numNums; i++)
                arr[i] = in.nextInt();
            if(go(0, arr, (2*numNums)))
                for (int i = 0; i < arr.length; i++)
                    System.out.print(arr[i] + (i==arr.length-1?"\n":" "));
        }
    }

    private static boolean go(int at, long[] arr, int numOps) {
        if(numOps < 0)
            return false;

        if(at == 0) {
            long num = arr[at];
            for (int i = 0; i <= numOps; i++) {
                arr[at] = num + i;
                if(go(at+1, arr, numOps-i))
                    return true;
            }
            arr[at] = num;
            return false;
        }

        if (at == arr.length - 1) {
            long num = arr[at];
            for (int i = 0; i <= numOps; i++) {
                arr[at] = num + i;
                if (arr[at]%arr[at-1] != 0)
                    return true;
            }
            arr[at] = num;
            return false;
        }

        long num = arr[at];
        for (int i = 0; i <= numOps; i++) {
            arr[at] = num + i;
            if (arr[at]%arr[at-1] != 0 && go(at+1, arr, numOps-i))
                return true;
        }
        arr[at] = num;
        return false;
    }


}
