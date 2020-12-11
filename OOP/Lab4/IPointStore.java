import java.util.ArrayList;

public interface IPointStore {
    ArrayList<FileInfo> store(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints);
}
