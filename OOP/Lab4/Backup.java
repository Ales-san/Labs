import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Backup {
    private int id;
    private Calendar creationTime;
    private int backupSize;
//    IPointCreate createAlgorithm;
    private IPointStore storeAlgorithm;
    private IPointController controller;
    private ArrayList<RestorePoint> restorePoints;
    private ArrayList<FileInfo> fileList;

    public void createPoint(IPointCreate createAlgorithm) {
        createAlgorithm.createPoint(fileList, restorePoints);
    }
    public void setController(IPointController controller) {
        this.controller = controller;
        controller.deleteRedundant(restorePoints);
    }

    public void setCreationTime(Calendar creationTime) {
        this.creationTime = creationTime;
    }

    public void setBackupSize(int backupSize) {
        this.backupSize = backupSize;
    }

    public void addFile(FileInfo fileInfo) {
        fileList.add(fileInfo);
    }

    public void deleteFile(String filePath) {
        for(int i = 0; i < fileList.size(); i++) {
            if(fileList.get(i).getFilePath().equals(filePath)) {
                fileList.remove(i);
                break;
            }
        }
    }
}
