# Clothing Store Management System

## About
The Clothing Store Management System is a C++ console-based application designed to help manage product inventory, facilitate customer purchases, and provide administrative functionalities such as adding, modifying, and deleting products. This system utilizes file handling to store and retrieve product information efficiently.

## Features
### Customer Module
- View product catalog
- Place an order by selecting products and quantities
- View order summary and total price

### Admin Module
- Add new products with details such as product number, name, price, and discount
- Modify existing product details
- Delete products from the inventory
- View all products in the inventory
- Search for specific products

## Installation
1. Clone the repository or download the source files.
2. Compile the `main.cpp` file using a C++ compiler:
   ```sh
   g++ main.cpp -o clothing_store
   ```
3. Run the compiled program:
   ```sh
   ./clothing_store
   ```

## Usage
1. Upon running the program, select either Customer or Administrator mode.
2. In customer mode, browse products and place orders.
3. In admin mode, manage the product catalog using various available options.

## File Handling
The system uses a binary file (`Shop.dat`) to store product details persistently. Temporary files are used when modifying or deleting records.

## Future Enhancements
- Implement a graphical user interface (GUI)
- Add user authentication for administrators
- Enable database integration for better data management

## License
This project is open-source and available under the MIT License.

## Author
Akash Sureshbhai Khanpara
