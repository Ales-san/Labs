import java.util.Calendar;
import java.util.GregorianCalendar;

public class CurrentDate {
    private static CurrentDate instance;
    private static Calendar calendar;
    private CurrentDate() {
        calendar = new GregorianCalendar(2020, Calendar.OCTOBER, 1, 1, 1, 0);
    }
    public static Calendar getDate() {
        if(instance == null) {
            instance = new CurrentDate();
        }
        return (Calendar) calendar.clone();
    }

    public static void setCalendar(Calendar calendar) {
        CurrentDate.calendar = calendar;
    }
}
