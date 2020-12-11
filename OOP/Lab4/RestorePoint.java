import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class RestorePoint {
    private ArrayList<FileInfo> fileList;
    private ArrayList<FileInfo> fileCopyList;
    private Calendar creationTime;
    private boolean incremental;



    public boolean isIncremental() {
        return incremental;
    }
}
