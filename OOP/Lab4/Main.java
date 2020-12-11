import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Map;

public class Main {
    public static void do_smth(List<Integer> a) {
        a.add(5);
        ArrayList <Integer> b = new ArrayList<>();
        b.add(6);
        b.add(7);
        a.clear();
        a.addAll(b);
    }
    public static void main(String[] args) {
        try {
           List<Integer> a = new ArrayList<>();
           a.add(3);
           do_smth(a);
           System.out.println(a);
           DateFormat df = new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss");
           System.out.println("/Point_from_" + df.format(Calendar.getInstance().getTime()));

        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}

