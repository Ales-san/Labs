import java.util.ArrayList;

public class NumberController extends IPointController {
    int number;
    public NumberController(int number) {
        this.number = number;
    }
    public int countRedundant(ArrayList<RestorePoint> restorePoints) {
        if(restorePoints.size() <= number) {
            return 0;
        }
        int fullPoint = 0;
        for(int i = 1; i < restorePoints.size() && restorePoints.size() - fullPoint > number; i++) {
            if(restorePoints.get(i).isFull()) {
                fullPoint = i;
            }
        }
        int res = restorePoints.size() - fullPoint;
        if(res > number) {
            System.out.println("This backup can't have less points than " + res
                    + "because it has too many incremental points");
        }
        return fullPoint;
    }

}






/*import java.util.ArrayList;

public class PointNumberController extends IPointController {
    private int number;

    public PointNumberController(int number) {
        this.number = number;
    }
    public void deleteRedundant(ArrayList <RestorePoint> restorePoints) {
        if(restorePoints.size() < number) {
            return;
        }
        int lastFullPoint = 0;
        ArrayList <RestorePoint> reducedRestorePoints = new ArrayList<>();
        for(int i = 1; i < restorePoints.size(); i++) {
            if (restorePoints.get(i).isFull() && restorePoints.size() - lastFullPoint - 1 > number) {
                lastFullPoint = i;
            }
            if(restorePoints.size() - lastFullPoint - 1 <= number) {
                reducedRestorePoints.add(restorePoints.get(i));
            }
        }
        restorePoints.clear();
        restorePoints.addAll(reducedRestorePoints);
    }
}
*/