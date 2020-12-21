import java.util.ArrayList;
import java.util.List;

public class Hybrid extends IPointController {
    IPointController[] controllers;
    ICombineAlgorithm combineAlgorithm;
    IPointController chosenController;

    public Hybrid(ICombineAlgorithm combineAlgorithm, IPointController ... controllers) throws Exception {
        if(controllers.length == 0) {
            throw new Exception("No one controller enabled");
        }
        this.controllers = controllers;
        this.combineAlgorithm = combineAlgorithm;
    }

    public int countRedundant(ArrayList<RestorePoint> restorePoints) {
        chosenController = controllers[0];
        for (int i = 1; i < controllers.length; i++) {
            chosenController = combineAlgorithm.getHybrid(restorePoints, chosenController, controllers[i]);
        }
        return chosenController.countRedundant(restorePoints);
    }

    @Override
    public void deleteRedundant(ArrayList<RestorePoint> restorePoints) {
        countRedundant(restorePoints);
        chosenController.deleteRedundant(restorePoints);
    }
}
