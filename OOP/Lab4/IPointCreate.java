import java.util.ArrayList;

public interface IPointCreate {
    void createPoint(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, IPointStore storeAlgorithm);
}
