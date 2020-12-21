import java.io.File;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        try {
            FileInfo A = new FileInfo(0, 110, CurrentDate.getDate(), "C:/test/A");
            FileInfo B = new FileInfo(1, 100, CurrentDate.getDate(), "C:/test/B");

            IPointStore separateStore = new PointStoreSeparate("C:/test/backups");
            IPointStore unionStore = new PointStoreUnion("C:/test/backups");
            IPointCreate fullCreate = new PointCreateFull();
            IPointCreate incCreate = new PointCreateInc();

            Backup backup = new Backup(0, separateStore,  new NumberController(1));
            backup.addFile(A);
            backup.addFile(B);
            backup.createPoint(fullCreate);
            System.out.println(backup.getGeneralSize() + " - size, files: " + backup.getFileNumber());
            A.setSize(100);
            B.updateCreationTime();
            backup.createPoint(fullCreate);
            System.out.println(backup.getGeneralSize() + " - size, points: " + backup.getRestorePointsNumber());
            backup.setController(new NumberController(3));
            backup.createPoint(fullCreate);
            System.out.println(backup.getGeneralSize() + " - size, points: " + backup.getRestorePointsNumber());
            backup.setController(new SizeController(150));
            System.out.println(backup.getGeneralSize() + " - size, points: " + backup.getRestorePointsNumber());

            FileInfo C = new FileInfo(2, 100, CurrentDate.getDate(), "C:/test/C");
            FileInfo D = new FileInfo(3, 60, CurrentDate.getDate(), "C:/test/D");
            Backup backup1 = new Backup(1, unionStore, new NumberController(4));
            backup1.addFile(C);
            backup1.addFile(D);
            backup1.createPoint(fullCreate);
            //C.setSize(300);
            D.updateCreationTime();
            ArrayList<FileInfo> infos = backup1.getLastInfos();
            System.out.println("C path is: " + infos.get(0).getFilePath());
            System.out.println("D path is: " + infos.get(1).getFilePath());
            backup1.createPoint(incCreate);
            D.setSize(100);
            infos = backup1.getLastInfos();
            System.out.println("C path is: " + infos.get(0).getFilePath());
            System.out.println("D path is: " + infos.get(1).getFilePath());

            FileInfo E = new FileInfo(4, 120, CurrentDate.getDate(), "C:/test/E");
            FileInfo F = new FileInfo(5, 80, CurrentDate.getDate(), "C:/test/F");

            CurrentDate.setCalendar(new GregorianCalendar(2020, Calendar.OCTOBER, 30, 1, 1, 0));

            IPointController controller = new Hybrid(new CombineMinAlgorithm(), new DateController(CurrentDate.getDate()), new NumberController(3));
            CurrentDate.setCalendar(new GregorianCalendar(2020, Calendar.OCTOBER, 1, 1, 1, 0));
            Backup backup2 = new Backup(2, unionStore, new NumberController(4));
            backup2.addFile(E);
            backup2.addFile(F);
            backup2.createPoint(fullCreate);
            backup2.createPoint(fullCreate);
            CurrentDate.setCalendar(new GregorianCalendar(2020, Calendar.NOVEMBER, 30, 1, 1, 0));
            backup2.createPoint(fullCreate);
            backup2.createPoint(fullCreate);
            backup2.setController(controller);
            System.out.println("Points number: " + backup2.getRestorePointsNumber());

            //DateFormat df = new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss");
            //System.out.println("/Point_from_" + df.format(Calendar.getInstance().getTime()));

        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}

