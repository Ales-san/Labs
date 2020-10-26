import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ShopNet {
    private Map<Integer, Shop> net = new HashMap<>();

    public ShopNet() {};
    public ShopNet(Shop shop) {
        net.put(shop.get_code(), shop);
    }
    public ShopNet(Shop ... shop) {
        for(int i = 0; i < shop.length; i++) {
            net.put(shop[i].get_code(), shop[i]);
        }
    }

    public void add_shop(Shop shop) {
        net.put(shop.get_code(), shop);
    }
    public Shop get_shop(int code) {
        return net.get(code);
    }
    public int get_cheapest_product(Product product) throws Exception {
        int code = -1;
        int price = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Shop> entry : net.entrySet()) {
            if(entry.getValue().has_product(product) && entry.getValue().get_price(product) < price) {
                price = entry.getValue().get_price(product);
                code = entry.getValue().get_code();
            }
        }
        if(code == -1) {
            throw new Exception("No such product: " + product.get_name());
        }
        return code;
    }

    public int get_cheapest_list(ArrayList<Map.Entry<Product, Integer>> product_list) throws Exception {
        long sum = Long.MAX_VALUE;
        int code = -1;
        for (Map.Entry<Integer, Shop> shop_entry : net.entrySet()) {
            long cost = 0;
            for(Map.Entry<Product, Integer> shipment : product_list) {
                Map.Entry<Boolean, Long> try_cost = shop_entry.getValue().try_shipment(shipment.getKey(), shipment.getValue());
                int c = 8;
                if(!try_cost.getKey()) {
                    cost = Long.MAX_VALUE;
                    break;
                }
                cost += try_cost.getValue();
            }
            if (cost < sum) {
                sum = cost;
                code = shop_entry.getValue().get_code();
            }
        }
        if(code == -1) {
            throw new Exception("No such product list in one shop");
        }
        return code;
    }

    public String get_shop_name(int code) {
        return get_shop(code).get_name();
    }
}
