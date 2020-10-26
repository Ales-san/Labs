import java.util.ArrayList;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        try {
            //filling the shops
            Product chocolate = new Product("Chocolate", 1);
            Product melon = new Product("Melon", 2);
            Product bread = new Product("White bread", 3);
            Product butter = new Product("Butter", 4);
            Product cereal = new Product("Cereal", 5);
            Product apple = new Product("Apple", 6);
            Product orange = new Product("Orange", 7);
            Product table = new Product("table", 8);
            Product cup = new Product("Cup", 9);
            Product milk = new Product("Milk", 10);
            Product sugar = new Product("White sugar", 11);
            Product flour = new Product("Flour", 12);
            Product flour1 = new Product("Flour", 13);


            Shop A = new Shop("Shop A", 1);
            Shop B = new Shop("Shop B", 2);
            Shop C = new Shop("Shop C", 3);

            A.add_shipment(chocolate, 10, 5);
            B.add_shipment(chocolate, 50, 10);
            C.add_shipment(chocolate, 100, 100);

            A.add_shipment(melon, 100, 15);
            B.add_shipment(melon, 150, 20);

            A.add_shipment(bread, 70, 100);
            B.add_shipment(bread, 80, 20);

            C.add_shipment(butter, 98, 50);
            A.add_shipment(cereal, 100, 30);
            B.add_shipment(apple, 80, 90);
            C.add_shipment(orange, 150, 25);
            A.add_shipment(table, 100000, 100000);
            B.add_shipment(cup, 50, 15);
            C.add_shipment(milk, 67, 250);

            ShopNet net = new ShopNet(A, B, C);
            //try to get the number of shop with the cheapest chocolate
            System.out.println(net.get_shop_name(net.get_cheapest_product(chocolate)) +
                    " : " + chocolate.get_name() +
                    " : " + net.get_shop(net.get_cheapest_product(chocolate)).get_price(chocolate));

            //try to find the cheapest list with right number of products
            //choco: A - 5; B - 10; C - 100
            ArrayList<Map.Entry<Product, Integer>> product_list = new ArrayList<>();
            product_list.add(Map.entry(chocolate, 10));
            product_list.add(Map.entry(melon, 1));
            System.out.println(net.get_shop_name(net.get_cheapest_list(product_list)) +
                    " : " + net.get_shop(net.get_cheapest_list(product_list)).try_shipment(
                    product_list.get(0).getKey(), product_list.get(0).getValue()).getValue());

            //try to find the cheapest list in the right shop
            //all products are the most cheapest in the shop A
            ArrayList<Map.Entry<Product, Integer>> product_list1 = new ArrayList<>();
            product_list1.add(Map.entry(chocolate, 5));
            product_list1.add(Map.entry(melon, 1));
            product_list1.add(Map.entry(bread, 20));
            System.out.println(net.get_shop_name(net.get_cheapest_list(product_list1)));

            //is all right with int/long
            product_list1.add(Map.entry(table, 100000));
            System.out.println(net.get_shop_name(net.get_cheapest_list(product_list1)));

            //is all right with set price
            Shop D = new Shop("Shop D", 4);
            D.add_shipment(flour, 1, 15);
            System.out.println(D.get_price(flour));
            D.set_price(flour, 10);
            System.out.println(D.get_price(flour));

            //is all right with different products with the same name
            D.add_shipment(flour1, 100, 100);
            System.out.println(D.get_price(flour1));
            System.out.println(D.get_price(flour));

            //get the list of products that cost less or equal to the limit
            ArrayList<Map.Entry<Product, Integer>> list = A.get_limit_buy(100);
            for(Map.Entry<Product, Integer> entry : list) {
                System.out.print(entry.getKey().get_name() + " : " + entry.getValue() + "|");
            }

            //price = 0
            D.add_shipment(sugar, 0, 10);
            System.out.println("\n" + D.try_shipment(sugar, 10).getKey() + " " + D.try_shipment(sugar, 10).getValue());
            System.out.println(D.try_shipment(sugar, 100).getKey());

            //exceptions
            //D.set_price(sugar, -10);
            //D.add_shipment(sugar, -15, 1);
            //D.add_shipment(sugar, 15, -1);
            //D.set_price(apple, 5);
            //D.set_number(apple, 3);
            //System.out.println(net.get_cheapest_product(sugar));
            //product_list1.add(Map.entry(sugar, 5));
            //System.out.println(net.get_cheapest_list(product_list1));

        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}

