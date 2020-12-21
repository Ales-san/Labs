import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Map;

public class PointStoreUnion extends IPointStore {
    String directoryPath;

    //IPointCreate createAlgorithm;
    public PointStoreUnion(String directoryPath) {//, IPointCreate createAlgorithm) {
        this.directoryPath = directoryPath;
        //this.createAlgorithm = createAlgorithm;
        //createDirectory(directoryPath);
    }

    public Map.Entry<Integer, ArrayList<FileInfo>> store(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, boolean incremental) {
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss");
        //createDirectory(directoryPath);
        //openDirectory(directoryPath);
        Map.Entry<Integer, ArrayList<FileInfo>> delta = getData(fileList, restorePoints, directoryPath, incremental);
        return delta;
    }


}

