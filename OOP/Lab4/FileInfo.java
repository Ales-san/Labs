import java.util.Calendar;

public class FileInfo {
    private int size;
    private Calendar creationTime;
    private String filePath;
    private String fileName;

    public FileInfo(int size, Calendar creationTime, String filePath) {
        this.size = size;
        this.creationTime = creationTime;
        this.filePath = filePath;
        setFileName(filePath);
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
    }

    public void setCreationTime(Calendar creationTime) {
        this.creationTime = creationTime;
    }

    public void setFilePath(String filePath) {
        this.filePath = filePath;
        setFileName(filePath);
    }

    public String getFileName() {
        return fileName;
    }

    private void setFileName(String filePath) {
        this.fileName = filePath.substring(filePath.lastIndexOf('/'));
    }
}
