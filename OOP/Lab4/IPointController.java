import java.util.ArrayList;
import java.util.List;

public abstract class IPointController {
     abstract int countRedundant(ArrayList<RestorePoint> restorePoints);
     public void deleteRedundant(ArrayList<RestorePoint> restorePoints) {
          int number = countRedundant(restorePoints);
          for(int i = 0; i < number; i++) {
               restorePoints.remove(0);
          }
     }
}
