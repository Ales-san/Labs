import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Shop {
    private String name = "";
    private int code = 0;
    private Map<Integer, Shipment> assortiment = new HashMap<>();

    public Shop() {};
    public Shop(String _name, int _code) {
        name = _name;
        code = _code;
    }

    public void add_shipment(Product product, int price, int number) throws Exception {
        if(number == 0) {
            return;
        }
        if(number < 0) {
            throw new Exception("Shipment can't have a negative number of products!");
        }
        Shipment shipment = assortiment.getOrDefault(product.get_code(), new Shipment());
        assortiment.put(product.get_code(), new Shipment(product, price, shipment.get_number() + number));
    }
    public void set_price(Product product, int price) throws Exception {
        if(assortiment.containsKey(product.get_code())) {
            assortiment.get(product.get_code()).set_price(price);
        } else {
            throw new Exception("No such product: " + product.get_name());
        }
    }
    public int get_price(Product product) throws Exception {
        if(assortiment.containsKey(product.get_code())) {
            return assortiment.get(product.get_code()).get_price();
        } else {
            throw new Exception("No such product: " + product.get_name());
        }
    }
    public boolean has_product(Product product) {
        if(assortiment.containsKey(product.get_code())) {
            return true;
        }
        return false;
    }
    private void set_number(Product product, int number) throws Exception {
        if(assortiment.containsKey(product.get_code())) {
            if(number == 0) {
                assortiment.remove(product.get_code());
            } else {
                assortiment.get(product.get_code()).set_number(number);
            }
        } else {
            throw new Exception("There is no such product: " + product.get_name());
        }
    }

    public Map.Entry<Boolean, Long> try_shipment(Product product, int number) {
        if(number == 0) {
            return Map.entry(true, 0L);
        }
        if(number < 0 || assortiment.getOrDefault(product.get_code(), new Shipment()).get_number() < number) {
            return Map.entry(false, 0L);
        }
        return Map.entry(true, (long) (assortiment.get(product.get_code()).get_price() * number));
    }

    public void buy_shipment(Product product, int number) throws Exception {
        if(number < 0) {
            throw new Exception("Was an attempt to buy a negative number of products");
        }
        set_number(product, -number);
    }
    public ArrayList<Map.Entry<Product, Integer>> get_limit_buy(int limit) {
        ArrayList<Map.Entry<Product, Integer>> res = new ArrayList<>();
        for (Map.Entry<Integer, Shipment> entry : assortiment.entrySet()) {
            int price = entry.getValue().get_price();
            if(price > 0) {
                    //&& limit / price > 0 && (limit / price) <= entry.getValue().get_number()) {
                //res.add(Map.entry(entry.getValue().get_product(), limit / price));
                res.add(Map.entry(entry.getValue().get_product(), Integer.min(limit / price, entry.getValue().get_number())));
            } else if (price == 0) {
                res.add(Map.entry(entry.getValue().get_product(), entry.getValue().get_number()));
            }
        }
        return res;
    }
    public String get_name() {
        return name;
    }
    public int get_code() {
        return code;
    }

    public String get_name(Product product) {
        return assortiment.get(product.get_code()).get_product().get_name();
    }
    public int get_number(Product product) {
        return assortiment.get(product.get_code()).get_number();
    }
}
