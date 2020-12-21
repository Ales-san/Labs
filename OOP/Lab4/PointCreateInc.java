import java.util.ArrayList;
import java.util.Map;

public class PointCreateInc implements IPointCreate {
    //private IPointStore storeAlgorithm;

    //public PointCreateInc(IPointStore storeAlgorithm) {
    //    this.storeAlgorithm = storeAlgorithm;
    //}

    public void createPoint(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, IPointStore storeAlgorithm) {
        if(restorePoints.size() == 0) {
            PointCreateFull fullAlgorithm = new PointCreateFull();
            fullAlgorithm.createPoint(fileList, restorePoints, storeAlgorithm);
            return;
        }

        Map.Entry<Integer, ArrayList<FileInfo>> delta = storeAlgorithm.store(fileList, restorePoints, true);
        restorePoints.add(new RestorePoint(restorePoints.size(), fileList, delta.getValue(), delta.getKey(), true));
    }


}
