import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;

public class PointStoreSeparate implements IPointStore{
    String directoryPath;
    IPointCreate createAlgorithm;
    public PointStoreSeparate(String directoryPath, IPointCreate createAlgorithm) {
        this.directoryPath = directoryPath;
        this.createAlgorithm = createAlgorithm;
        //createDirectory(directoryPath);
    }
    public ArrayList<FileInfo> store(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints) {
        ArrayList<FileInfo> fileCopyList = new ArrayList<>();
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss");
        String pointPath = directoryPath + "/Point_from_" + df.format(Calendar.getInstance().getTime());
        //createDirectory(pointPath);
        int generalSize = 0;
        for(FileInfo info : fileList) {
            String filePath = pointPath + "/R_" + info.getFileName();
            //createFileCopy(filePath);
            FileInfo copyFile = new FileInfo((int) (info.getSize() * 0.1 + 1), Calendar.getInstance(), filePath);
            fileCopyList.add(copyFile);
            generalSize +=
        }
        return fileCopyList;
    }
}
