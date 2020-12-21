import java.util.Calendar;

public class FileInfo {
    private int id;
    private int size;
    private Calendar creationTime;
    private String filePath;
    private String fileName;

    public FileInfo(int id, int size, Calendar creationTime, String filePath) {
        this.id = id;
        this.size = size;
        this.creationTime = creationTime;
        this.filePath = filePath;
        setFileName(filePath);
    }

    public FileInfo(FileInfo fileInfo) {
        this.size = fileInfo.size;
        this.creationTime = fileInfo.creationTime;
        this.filePath = fileInfo.filePath;
        setFileName(filePath);
    }

    public int getId() {
        return id;
    }

    public int getSize() {
        return size;
    }

    public Calendar getCreationTime() {
        return creationTime;
    }

    public String getFilePath() {
        return filePath;
    }

    public void setSize(int size) {
        this.size = size;
        updateCreationTime();
    }

    //public void setCreationTime(Calendar creationTime) {
    //    this.creationTime = creationTime;
    //}

    public void updateCreationTime() {
        this.creationTime = CurrentDate.getDate();
    }

    /*public void setFilePath(String filePath) {
        this.filePath = filePath;
        setFileName(filePath);
    }*/

    public String getFileName() {
        return fileName;
    }

    private void setFileName(String filePath) {
        this.fileName = filePath.substring(filePath.lastIndexOf('/') + 1);
        updateCreationTime();
    }
}
