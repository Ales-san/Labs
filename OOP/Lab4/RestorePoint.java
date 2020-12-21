import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class RestorePoint {
    private int id;
    private ArrayList<FileInfo> fileList;
    private ArrayList<FileInfo> fileDataList;
    private Calendar creationTime;
    private int generalSize;
    private boolean incremental;

    public RestorePoint(int id, ArrayList<FileInfo> fileList, ArrayList<FileInfo> fileDataList, int generalSize, boolean incremental) {
        this.id = id;
        this.fileList = new ArrayList<FileInfo>(fileList);
        this.creationTime = CurrentDate.getDate();
        this.fileDataList = fileDataList;
        this.generalSize = generalSize;
        this.incremental = incremental;
    }

    public int getGeneralSize() {
        return generalSize;
    }

    public int getId() {
        return id;
    }

    public boolean isFull() {
        return !incremental;
    }

    public Calendar getCreationTime() {
        return (GregorianCalendar) creationTime.clone();
    }

    ArrayList<FileInfo> getFileDataList() {
        return new ArrayList<>(fileDataList);
    }
}
