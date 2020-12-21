import java.util.ArrayList;
import java.util.Map;

public abstract class IPointStore {

    abstract Map.Entry<Integer, ArrayList<FileInfo>> store(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, boolean incremental);

    public int getSizeDelta(FileInfo newFileInfo, FileInfo oldFileInfo) {
        return newFileInfo.getSize() - oldFileInfo.getSize();
    }

    public int getFile(int id, ArrayList<FileInfo> fileList) {
        for (int i = 0; i < fileList.size(); i++) {
            if (fileList.get(i).getId() == id) {
                return i;
            }
        }
        return -1;
    }

    protected Map.Entry<Integer, ArrayList<FileInfo>> getData(ArrayList<FileInfo> fileList, ArrayList<RestorePoint> restorePoints, String directoryPath, boolean incremental) {
        int fullPoint = 0;
        for (int i = restorePoints.size() - 1; i > 0; i--) {
            if (restorePoints.get(i).isFull()) {
                fullPoint = i;
                break;
            }
        }

        int generalSize = 0;
        ArrayList<FileInfo> newFileDataList = new ArrayList<>();
        ArrayList<FileInfo> oldFileDataList;
        if(restorePoints.size() != 0) {
            oldFileDataList = restorePoints.get(fullPoint).getFileDataList();
        } else {
            oldFileDataList = new ArrayList<>();
        }
        for (FileInfo fileInfo : fileList) {
            String filePath = directoryPath + "/R_" + fileInfo.getFileName();
            int index = getFile(fileInfo.getId(), oldFileDataList);
            FileInfo delta;
            if (!incremental || index == -1) {
                delta = new FileInfo(fileInfo.getId(), fileInfo.getSize(), fileInfo.getCreationTime(), filePath);
                newFileDataList.add(delta);
                //writeDown(delta, fileInfo.getFilePath());
                generalSize += fileInfo.getSize();
            } else {
                if (fileInfo.getCreationTime() == oldFileDataList.get(index).getCreationTime()) {
                    continue;
                }
                int sizeDelta = getSizeDelta(fileInfo, oldFileDataList.get(index));

                delta = new FileInfo(fileInfo.getId(), sizeDelta, fileInfo.getCreationTime(), filePath);
                newFileDataList.add(delta);
                //writeDownDelta(delta, oldFileInfo.getFilePath(), fileInfo.getFilePath());
                generalSize += sizeDelta;
            }
        }
        return Map.entry(generalSize, newFileDataList);
    }
}
