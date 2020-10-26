public class Shipment {
    private Product product;
    private int price = 0;
    private int number = 0;

    public Shipment() {};
    public Shipment(Product _product, int _price, int _number) throws Exception {
        product = _product;
        set_price(_price);
        set_number(_number);
    }

    public int get_number() {
        return number;
    }
    public int get_price() {
        return price;
    }
    public Product get_product() {
        return product;
    }
    public void set_price(int _price) throws Exception {
        if(_price < 0) {
            throw new Exception("Shipment can't have a negative price of products!");
        }
        price = _price;
    }
    public void set_number(int _number) throws Exception {
        if(_number >= 0) {
            number = _number;
        } else if(number >= -_number) {
            number += _number;
        } else {
            throw new Exception("Not enough products of type: " + product.get_name());
        }
    }
}
