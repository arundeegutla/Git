import java.util.*;

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();
        
        Method[] all = new Method[n];
        HashMap<String, Integer> ref = new HashMap<>();

        for (int i = 0; i < n; i++)
        {
            String[] line = in.nextLine().split(" ");
            ref.put(line[0], i);
            all[i] = new Method(line[0]);
            if (line[0].contains("PROGRAM"))
            {
                all[i].setCalled(true);
            }

            if (!line[1].equals("0"))
            {
                String[] idk = in.nextLine().split(" ");
                for (String s: idk)
                {
                    all[i].addInvoke(s);
                }
            }
            else
            {
                in.nextLine();
            }
        }

        int used = 0;
        // check if invoked is true
        for (Method m: all)
        {
            boolean ans = true;
            if (m.invoked.isEmpty() && m.called)
            {
                used++;
                continue;
            }
            for (String s: m.invoked)
            {
                // get ind
                if (s.equals(m.name))
                {
                    continue;
                }

                int ind = ref.get(s);
                if (!all[ind].called)
                {
                    ans = false;
                }
                
            }
            if (ans == true)
                used++;
            m.setCalled(ans);
        }

        System.out.println(n - used);

    }
}

class Method
{
    public String name;
    public ArrayList<String> invoked;
    public boolean called;

    public Method(String n)
    {
        name = n;
        called = false;
        invoked = new ArrayList<>();
    }

    public void addInvoke(String n)
    {
        invoked.add(n);
    }

    public void setCalled(boolean b)
    {
        called = b;
    }
}
