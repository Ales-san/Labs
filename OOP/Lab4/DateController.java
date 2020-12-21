import java.util.ArrayList;
import java.util.Calendar;

public class DateController extends IPointController {
    Calendar calendar;

    public DateController(Calendar calendar) {
        this.calendar = calendar;
    }

    public int countRedundant(ArrayList<RestorePoint> restorePoints) {
        if(restorePoints.size() == 0 || !restorePoints.get(0).getCreationTime().before(calendar)) {
            return 0;
        }
        int fullPoint = 0;
        for(int i = 1; i < restorePoints.size(); i++) {
            if(restorePoints.get(i).isFull()) {
                fullPoint = i;
                if(!restorePoints.get(fullPoint).getCreationTime().before(calendar)) {
                    break;
                }
            }
        }
        int res = restorePoints.size() - fullPoint;
        if(restorePoints.get(fullPoint).getCreationTime().before(calendar)) {
            System.out.println("This backup can't have less points than " + res);
        }
       return fullPoint;
    }
}
