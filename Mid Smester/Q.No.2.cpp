#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
};

void displayProducts(const vector<Product>& products) {
    cout << "Product ID | Product Name | Quantity\n";
    cout << "-----------------------------------\n";
    for (const auto& product : products) {
        cout << product.id << " | " << product.name << " | " << product.quantity << "\n";
    }
    cout << "-----------------------------------\n";
}

int partition(vector<Product>& products, int low, int high) {
    int pivot = products[high].quantity;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (products[j].quantity < pivot) {
            i++;
            swap(products[i], products[j]);
        }
    }

    swap(products[i + 1], products[high]);
    return i + 1;
}

void quickSortProducts(vector<Product>& products, int low, int high) {
    if (low < high) {
        int pi = partition(products, low, high);

        quickSortProducts(products, low, pi - 1);
        quickSortProducts(products, pi + 1, high);
    }
}

int main() {
    // Sample product data
    vector<Product> products = {
        {101, "ProductA", 30},
        {102, "ProductB", 15},
        {103, "ProductC", 25},
        {104, "ProductD", 10},
        {105, "Juice", 10},
        {106, "Milk", 20},
        {107, "Bread", 15},
        {108, "Butter", 5},
        {109, "Cheese", 10},
        {110, "Eggs", 20},
    };

    cout << "Unsorted Product Records:\n";
    displayProducts(products);

    // Sort products using quicksort
    quickSortProducts(products, 0, products.size() - 1);

    cout << "\nSorted Product Records (Ascending Order by Quantity):\n";
    displayProducts(products);

    return 0;
}
