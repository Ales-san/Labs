import java.util.ArrayList;

public interface ICombineAlgorithm {
    IPointController getHybrid(ArrayList<RestorePoint> restorePoints, IPointController a, IPointController b);
    //int getStartValue();
}
