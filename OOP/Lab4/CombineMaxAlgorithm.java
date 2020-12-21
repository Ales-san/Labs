import java.util.ArrayList;

public class CombineMaxAlgorithm implements ICombineAlgorithm {

    public IPointController getHybrid(ArrayList<RestorePoint> restorePoints, IPointController a, IPointController b) {
        if(a.countRedundant(restorePoints) < b.countRedundant(restorePoints)) {
            return a;
        }
        return b;
    }
}
