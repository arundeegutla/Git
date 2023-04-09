import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numStrings = in.nextInt();
        in.nextLine();

        HashSet<Parenthseis> set = new HashSet<>();
        for (int i = 0; i < numStrings; i++){
            Parenthseis w = new Parenthseis(in.nextLine());
            if (set.contains(w)) {
                continue;
            }
            set.add(w);
            w.doStack();
        }

        
        int res = 0;
        ArrayList<Parenthseis> list = new ArrayList<>(set);

        // for (Parenthseis parenthseis : set) {
        //     System.out.println(parenthseis);
        // }


        loop : for (int i = 0; i < list.size(); i++){
            String stri = list.get(i).stackStr;
            for (int j = i+1; j < list.size(); j++){
                String strj = list.get(j).reverseStr;
                if (stri.equals(strj)) {
                    // System.out.println();
                    // System.out.println(list.get(i));
                    // System.out.println(list.get(j));
                    // System.out.println();
                    res++;
                    continue loop;
                }
            }
        }
            
                

        System.out.println(res);


    }
}

class Parenthseis {

    String str;
    String stackStr;
    String reverseStr;


    Parenthseis(String str){
        this.str = str;
    }

    public void doStack(){
        Stack<Character> stack = new Stack<>();
        StringBuilder stackStr = new StringBuilder();
        StringBuilder reversestackStr = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {
            if (!stack.isEmpty() && stack.peek() == '(' && str.charAt(i) == ')') {
                stack.pop();
                continue;
            }
            stack.add(str.charAt(i));
        }

        while (!stack.isEmpty()){
            char c = stack.pop();
            if (c == ')') reversestackStr.append('(');
            else reversestackStr.append(')');
            stackStr.append(c);
        }

        this.stackStr = stackStr.toString();
        this.reverseStr = reversestackStr.toString();
    }

    @Override
    public int hashCode() {
        return str.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return ((Parenthseis)obj).str.equals(this.str);
    }

    @Override
    public String toString() {
        return str + ", Have: " + stackStr + ", Need: " + reverseStr;
    }
}