package _705_DesignHashSet;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class _705_DesignHashSet_debug {
    public static void main(String[] args) {
        System.out.println("_705_DesignHashSet_debug");

        int a = 2;
//        int b = a  >>> 16;
        int b = a ^ 3;
        System.out.println(a);
        System.out.println(b);

        int c = 1 << 31;


        System.out.println(c);


        Map<Integer, String> d = new HashMap<Integer, String>();
        d.put(1, "a");
        d.put(2, "a");
        d.put(3, "a");
        int hascode = d.hashCode();

        System.out.println(d);
        System.out.println(hascode);

    }
}
