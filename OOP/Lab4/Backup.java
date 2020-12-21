import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Backup {
    private int id;
    private Calendar modificationTime;
    private int backupSize;
//    IPointCreate createAlgorithm;
    private IPointStore storeAlgorithm;
    private IPointController controller;
    private ArrayList<RestorePoint> restorePoints;
    private ArrayList<FileInfo> fileList;
    private int generalSize;

    public Backup(int id, IPointStore storeAlgorithm, IPointController controller) {
        this.id = id;
        updateModificationTime();
        this.backupSize = 0;
        this.storeAlgorithm = storeAlgorithm;
        this.controller = controller;
        this.restorePoints = new ArrayList<>();
        this.fileList = new ArrayList<>();
        this.generalSize = 0;
    }

    private void updateModificationTime() {
        this.modificationTime = CurrentDate.getDate();
    }

    private void updateGeneralSize() {
        generalSize = 0;
        for (RestorePoint restorePoint : restorePoints) {
            generalSize += restorePoint.getGeneralSize();
        }
    }

    private void updateBackup() {
        updateModificationTime();
        int oldSize = restorePoints.size();
        controller.deleteRedundant(restorePoints);
        updateGeneralSize();

    }

    public void createPoint(IPointCreate createAlgorithm) {
        createAlgorithm.createPoint(fileList, restorePoints, storeAlgorithm);
        updateBackup();
    }

    public void setController(IPointController controller) {
        this.controller = controller;
        updateBackup();
    }

    public int getGeneralSize() {
        return generalSize;
    }

    public int getRestorePointsNumber() {
        return restorePoints.size();
    }

    public int getFileNumber() {
        return fileList.size();
    }

    public ArrayList<FileInfo> getLastInfos() {
        int fullPoint = 0;
        if(restorePoints.size() == 0) {
            return new ArrayList<>();
        }
        for (int i = 1; i < restorePoints.size(); i++) {
            if(restorePoints.get(i).isFull()) {
                fullPoint = i;
            }
        }
        ArrayList<FileInfo> res = new ArrayList<>(restorePoints.get(fullPoint).getFileDataList());
        for(int i = fullPoint + 1; i < restorePoints.size(); i++) {
            if(restorePoints.get(i).getFileDataList().size() > 0) {
                for (FileInfo info : restorePoints.get(i).getFileDataList()) {
                    if(getFile(info.getId(), res) == -1) {
                        res.add(new FileInfo(info));
                    } else {
                        res.set(getFile(info.getId(), res), new FileInfo(info));
                    }
                }
            }
        }
        return res;
        //return restorePoints.get(restorePoints.size() - 1).getFileDataList();
    }

    /*public void setCreationTime(Calendar creationTime) {
        this.modificationTime = modificationTime;
    }*/

    /*public void setBackupSize(int backupSize) {
        this.backupSize = backupSize;
    }*/

    public void addFile(FileInfo fileInfo) {
        fileList.add(fileInfo);
    }

    public void deleteFile(int id) throws Exception {
        int index = getFile(id, fileList);
        if(index == -1) {
            throw new Exception("No such file: " + id);
        }
        fileList.remove(index);
    }

    public void setFile(FileInfo fileInfo) throws Exception {
        int index = getFile(fileInfo.getId(), fileList);
        if(index == -1) {
            throw new Exception("No such file: " + fileInfo.getFilePath());
        }
        fileList.set(index, fileInfo);
    }


    public int getFile(int id, ArrayList<FileInfo> fileList) {
        for (int i = 0; i < fileList.size(); i++) {
            if (fileList.get(i).getId() == id) {
                return i;
            }
        }
        return -1;
    }
}
