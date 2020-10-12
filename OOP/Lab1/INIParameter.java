public class INIParameter {
    private String name = "";
    private String value = "";

    public INIParameter() {};

    public INIParameter(String _name, String _value) {
        name = _name;
        value = _value;
    }

    public String get_name() {
        return name;
    }

    public String get_value() {
        return value;
    }
}
