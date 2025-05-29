//#include "../Domain/Product.h"
//#include "../Repository/ProductRepository.h"
//#include <stdexcept>
//#include <gtest/gtest.h>
//
//TEST(ProductTest, ValidProductCreation) {
//    Product p("P100", "Apple", 1.99, 50);
//    EXPECT_EQ(p.getProductId(), "P100");
//    EXPECT_EQ(p.getName(), "Apple");
//    EXPECT_DOUBLE_EQ(p.getPrice(), 1.99);
//    EXPECT_EQ(p.getStock(), 50);
//}
//
//TEST(ProductTest, InvalidProductCreation) {
//    EXPECT_THROW(Product("", "Apple", 1.99, 50), std::invalid_argument);
//    EXPECT_THROW(Product("P100@", "Apple", 1.99, 50), std::invalid_argument);
//    EXPECT_THROW(Product("P100", "", 1.99, 50), std::invalid_argument);
//    EXPECT_THROW(Product("P100", "Apple", -1.99, 50), std::invalid_argument);
//    EXPECT_THROW(Product("P100", "Apple", 1.99, -50), std::invalid_argument);
//}
//
//TEST(ProductRepositoryTest, AddProduct) {
//    ProductRepository repo;
//    Product p1("P100", "Apple", 1.99, 50);
//    repo.addProduct(p1);
//
//    EXPECT_EQ(repo.getAllProducts().size(), 1);
//
//    // Test duplicate product ID
//    Product p2("P100", "Banana", 0.99, 30);
//    EXPECT_THROW(repo.addProduct(p2), std::invalid_argument);
//}
//
//TEST(ProductRepositoryTest, GetAvailableProducts) {
//    ProductRepository repo;
//    repo.addProduct(Product("P100", "Apple", 1.99, 50));
//    repo.addProduct(Product("P101", "Banana", 0.99, 0));  // Out of stock
//    repo.addProduct(Product("P102", "Orange", 1.49, 30));
//
//    auto available = repo.getAvailableProducts();
//    EXPECT_EQ(available.size(), 2);
//    EXPECT_DOUBLE_EQ(available[0].getPrice(), 0.99);  // Should be sorted
//}
//
//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}