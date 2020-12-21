import java.util.ArrayList;
import java.util.Map;

public class PointCreateFull implements IPointCreate {
    public void createPoint(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, IPointStore storeAlgorithm) {

        Map.Entry<Integer, ArrayList<FileInfo>> delta = storeAlgorithm.store(fileList, restorePoints, false);
        restorePoints.add(new RestorePoint(restorePoints.size(), fileList, delta.getValue(), delta.getKey(), false));
    }
}
