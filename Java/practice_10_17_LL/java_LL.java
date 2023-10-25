package practice_10_17_LL;
import java.util.*;

public class java_LL {
    public static void main(String[] args) {
        ArrayList<String> strlist = new ArrayList<>(10);
        for (int i = 0; i < 10; i++) {
            strlist.add("" + i);
        }
        for (String x : strlist) {
            System.out.println(x);
        }
    }
}
