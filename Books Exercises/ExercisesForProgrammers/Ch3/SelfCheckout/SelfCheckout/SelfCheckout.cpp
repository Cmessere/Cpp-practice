#include <iostream>
#include <vector>

constexpr auto TAX_VALUE = 5.5;

using namespace std;

struct  PRODUCT {
	double quantity;
	double price;
};

double getInput(const string& value, const unsigned short &number) {
	double size;

	cout << "Enter the " << value << " for item " << number << ": " << endl;
	cin >> size;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> size;
	}
	return size;
}

void getProducts(unsigned short size, std::vector<PRODUCT*>& shoppingList);

void getSubtotal(std::vector<PRODUCT*>& shoppingList, double& subtotal);

int main()
{
	unsigned short size;
	double subtotal = 0, tax = 0;

	cout << "How many items do you want to buy? ";
	cin >> size;

	vector<PRODUCT*> shoppingList;

	getProducts(size, shoppingList);
	getSubtotal(shoppingList, subtotal);

	tax = subtotal * TAX_VALUE / 100;

	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << tax + subtotal << endl;
}

void getSubtotal(std::vector<PRODUCT*>& shoppingList, double& subtotal)
{
	for (auto i : shoppingList) {
		subtotal += i->price * i->quantity;
		delete(i);
	}
}

void getProducts(unsigned short size, std::vector<PRODUCT*>& shoppingList)
{
	for (short i = 0; i < size; i++) {
		PRODUCT* newProduct = new PRODUCT();

		newProduct->price = getInput("price", i + 1);
		newProduct->quantity = getInput("quantity", i + 1);
		shoppingList.push_back(newProduct);
	}
}
