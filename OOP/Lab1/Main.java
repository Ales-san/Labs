
public class Main {
    public static void main(String[] args) {

        Parser parser = new Parser();
       try {
            Data data = parser.parse("input.txt");
            System.out.println(data.tryGetDouble("Common", "StatisterTimeMs"));
            //System.out.println(data.tryGetInt("ADC_DEV", "BufferLenSeconds"));
            System.out.println(data.tryGetString("ADC_DEV", "Driver"));
            System.out.println(data.tryGetInt("LEGACY_XML", "ListenTcpPort"));
            System.out.println(data.tryGetDouble("LEGACY_XML", "ListenTcpPort"));
            System.out.println(data.tryGetString("DEBUG", "PlentySockMaxQSize"));
            //System.out.println(data.tryGetString("SMTH", "IDK"));
            System.out.println(data.tryGetString("LEGACY_XML", "Port"));
            System.out.println(data.tryGetString("NEW0", "Smth"));

        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
