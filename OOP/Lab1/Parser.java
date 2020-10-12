import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Parser {

    public Parser() {};

    public Data parse(String name) throws Exception {
        File file = new File(name);
        Scanner scanner = null;
        Data data = new Data();
        try {
            scanner = new Scanner(file);
            String lastSection = "";
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().strip().split(" ");
                String last_param = "";
                boolean flag = false;
                for(String word : line) {
                    if(word.length() == 0 || word.charAt(0) == ';') {
                        break;
                    } else if(word.charAt(0) == '[') {
                        if(check_name(word.substring(1, word.length() - 1)) && word.charAt(word.length() - 1) == ']') {
                            lastSection = word.substring(1, word.length() - 1);
                            data.put_section(lastSection);
                        } else {
                            throw new Exception("Wrong name: " + word);
                        }
                    } else if(!flag && check_name(word)) {
                        last_param = word;
                        flag = true;
                    } else if (flag && word.contentEquals("=")) {
                        continue;
                    } else if(flag && check_value(word) && !last_param.isEmpty()) {
                        data.put_parameter(lastSection, last_param, word);
                        flag = false;
                    } else {
                        throw new Exception("Wrong parameter: " + word);
                    }

                }
            }
        } catch (FileNotFoundException e) {
            throw new Exception("File was not found");
        } catch (Exception e1) {
            throw new Exception(e1.getMessage());
        } finally {
            scanner.close();
        }
        return data;
    }
    private boolean check_name(String _name) {
        if(!_name.matches("(\\d|\\w)+")) {
            return false;
        }
        return true;
    }
    private boolean check_value(String _value) {
        if(!_value.matches("(\\d|\\w|\\.)+")) {
            return false;
        }
        return true;
    }
}
