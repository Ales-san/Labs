import java.util.HashMap;
import java.util.Map;

public class INISection {
    private String name = "";
    private Map<String, INIParameter> parameters = new HashMap<>();

    public INISection() {};

    public INISection(String _name) {
        name = _name;
    }

    public INISection(String _name, INIParameter _parameter) {
        name = _name;
        parameters.put(_parameter.get_name(), _parameter);
    }

    public String get_name() {
        return name;
    }

    public INIParameter get_parameter(String _name) throws Exception {
        if(parameters.containsKey(_name)) {
            return parameters.get(_name);
        } else {
            throw new Exception("There is no such parameter: " + _name);
        }
    }

    public void put_parameter(INIParameter _parameter) {
        parameters.put(_parameter.get_name(), _parameter);
    }

    public void put_parameter(String _name, String _value) {
        parameters.put(_name, new INIParameter(_name, _value));
    }
}
