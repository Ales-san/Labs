import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Map;

public class PointStoreSeparate extends IPointStore{
    String directoryPath;
    //IPointCreate createAlgorithm;
    public PointStoreSeparate(String directoryPath){//, IPointCreate createAlgorithm) {
        this.directoryPath = directoryPath;
        //this.createAlgorithm = createAlgorithm;
        //createDirectory(directoryPath);
        //openDirectory(directoryPath);
    }
    public Map.Entry<Integer, ArrayList<FileInfo>> store(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, boolean incremental) {
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss");
        String pointPath = directoryPath + "/Point_from_" + df.format(CurrentDate.getDate().getTime());
        //createDirectory(pointPath);
        //openDirectory(pointPath);
        Map.Entry<Integer, ArrayList<FileInfo>> delta = getData(fileList, restorePoints, pointPath, incremental);
        return delta;
    }
}

