public class Product {
    private String name = "";
    private int code = 0;

    public Product() {}
    public Product(String _name, int _code) {
        name = _name;
        code = _code;
    }
    public Product(Product other) {
        this(other.get_name(), other.get_code());
    }

    public String get_name() {
        return name;
    }
    public int get_code() {
        return code;
    }
}
