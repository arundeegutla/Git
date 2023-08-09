import java.util.*;
class e {
    static int[][][] m;
    static int n;
    static int[] t;
    public static void main(String[] a) {
        Scanner b = new Scanner(System.in);
        n=b.nextInt();
        t=new int[n];
        for(int i=0;i<n;i++)t[i]=b.nextInt();
        m=new int[n+1][(1<<3)+1][3+1];
        for(int[][] o:m)for(int[] oo:o)Arrays.fill(oo, -1);
        System.out.print(d(0,0,-1));
    }
    static int d(int a,int f,int c) {
        if(c!=-1&&(f&(1<<c))!=0)return -(int)1e9;
        if (a==n)return 0;
        if(m[a][f][c+1]!=-1)return m[a][f][c+1];
        int l=d(a+1,f,c);
        int q=d(a+1,c==-1||c==t[a]?f:f|(1<<c),t[a]);
        return m[a][f][c+1]=Math.max(l,q+1);
    }
}

