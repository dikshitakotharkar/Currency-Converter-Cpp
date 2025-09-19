#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
// A simple database of exchange rates (relative to 1 USD)
// This is a Data Structure (Map) - great for your resume!
map<string, double> exchangeRates = {
{"USD", 1.0}, // US Dollar (base)
{"EUR", 0.93}, // Euro
{"INR", 83.0}, // Indian Rupee
{"JPY", 150.0}, // Japanese Yen
{"GBP", 0.80} // British Pound
};

string from_currency, to_currency;
double amount;

cout << "=== Simple Currency Converter ===" << endl;
cout << "Supported currencies: USD, EUR, INR, JPY, GBP" << endl << endl;

// Get user input
cout << "Enter source currency (3-letter code): ";
cin >> from_currency;
cout << "Enter target currency (3-letter code): ";
cin >> to_currency;
cout << "Enter amount to convert: ";
cin >> amount;

// Convert input to uppercase to make it case-insensitive
for (auto &c : from_currency) c = toupper(c);
for (auto &c : to_currency) c = toupper(c);

// Check if the currencies are in our database
if (exchangeRates.find(from_currency) == exchangeRates.end()) {
cerr << "Error: Unsupported source currency '" << from_currency << "'." << endl;
return 1;
}
if (exchangeRates.find(to_currency) == exchangeRates.end()) {
cerr << "Error: Unsupported target currency '" << to_currency << "'." << endl;
return 1;
}

// Perform the conversion
// First, convert the amount to USD, then to the target currency.
double amountInUSD = amount / exchangeRates[from_currency];
double convertedAmount = amountInUSD * exchangeRates[to_currency];

// Display the result
cout << fixed << setprecision(2);
cout << "\n---------------------------------" << endl;
cout << amount << " " << from_currency << " = " << convertedAmount << " " << to_currency << endl;
cout << "---------------------------------" << endl;

return 0;
}