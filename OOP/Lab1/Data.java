import java.util.HashMap;
import java.util.Map;

public class Data {
    Map<String, INISection> sections = new HashMap<>();

    public Data() {};

    public void put_section(String _name) {
        sections.put(_name, new INISection(_name));
    }

    public void put_parameter(String _section, String _name, String _value) {
        if(sections.containsKey(_section)) {
            sections.get(_section).put_parameter(_name, _value);
        }
    }


    public double tryGetDouble(String section, String parameter) throws  Exception{
        try {
            if(sections.containsKey(section)) {
                try {
                    return Double.parseDouble(sections.get(section).get_parameter(parameter).get_value());
                } catch (Exception e) {
                    throw new Exception(e.getMessage() + ", section: " + section);
                }
            } else {
                throw new Exception("No such section: " + section);
            }
        } catch (NumberFormatException e1) {
            throw new Exception("Type of " + parameter + " is not double");
        } catch (Exception e) {
            throw new Exception(e.getMessage());
        }
    }

    public int tryGetInt(String section, String parameter) throws  Exception{
        try {
            if(sections.containsKey(section)) {
                try {
                    return Integer.parseInt(sections.get(section).get_parameter(parameter).get_value());
                } catch (Exception e) {
                    throw new Exception(e.getMessage() + ", section: " + section);
                }
            } else {
                throw new Exception("No such section: " + section);
            }
        } catch (NumberFormatException e1) {
            throw new Exception("Type of " + parameter + " is not int");
        } catch (Exception e) {
            throw new Exception(e.getMessage());
        }
    }

    public String tryGetString(String section, String parameter) throws  Exception {
        if (sections.containsKey(section)) {
            try {
                return sections.get(section).get_parameter(parameter).get_value();
            } catch (Exception e) {
                throw new Exception(e.getMessage() + ", section: " + section);
            }
        } else {
            throw new Exception("There is no such section: " + section);
        }
    }
}
