import java.util.ArrayList;
import java.util.List;

public class PointNumberController implements IPointController {
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
            if (!restorePoints.get(i).isIncremental() && restorePoints.size() - lastFullPoint - 1 > number) {
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
