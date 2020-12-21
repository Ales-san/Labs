import java.util.ArrayList;

public class SizeController extends IPointController {
    private int size;
    public SizeController(int size) {
        this.size = size;
    }
    public int countRedundant(ArrayList<RestorePoint> restorePoints) {

        int fullPoint = 0;
        int generalSize = 0;
        for(int i = 0; i < restorePoints.size(); i++) {
            generalSize += restorePoints.get(i).getGeneralSize();
        }
        if(generalSize <= size) {
            return 0;
        }
        int uselessSize = 0;
        int currentSize = 0;
        for(int i = 0; i < restorePoints.size() && generalSize - uselessSize > size; i++) {
            if(restorePoints.get(i).isFull())  {
                fullPoint = i;
                uselessSize += currentSize;
                currentSize = 0;
            }
            currentSize += restorePoints.get(i).getGeneralSize();
        }
        int res = restorePoints.size() - fullPoint;
        if(generalSize - uselessSize > size) {
            System.out.println("This backup can't have less points than " + res);
        }
        return fullPoint;
    }
}
