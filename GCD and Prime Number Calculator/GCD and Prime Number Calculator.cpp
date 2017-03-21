#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

long long int gcd(long long int x, long long int y) {
	long long int gcd; //greatest common diviser of x and y
	long long int r = 1; //remainder (cant be zero to start)
	long long int m; //modular divisor
	long long int n; //the greater number of the two inputs
	if (x == 0 && y != 0) {
		gcd = y;
	}
	else if (y == 0 && x != 0) {
		gcd = x;
	}
	else {
		if (x > y) { //checking what input is greater
			m = y;
			n = x;
		}
		else {
			m = x;
			n = y;
		}

		while (r != 0) { //euclidean algorithm
			r = n % m;
			n = m;

			if (r != 0) {
				m = r;
			}
			else { //gcd is found!
				gcd = m;
			}

		}
	}

	return gcd;
}


void primeCheck(long long int x) { //assuming x is greater than 1
	vector<long long int> divisorsOfX; //result vector
	vector<long long int> divisors; //vector of prime divisors to check if x is prime
	int long long r; //remainder for mid step calculations

	long long int xSqroot;
	xSqroot = (long long int) sqrt(x);

	//checking for prime numbers less than the square root of the original number
	for (int i = 2; i < xSqroot; i++) { //prime numbers must be greater than one so start at 2
		for (int j = 2; j <= i; j++) {
			r = i % j;
			if ((j < i) && (r == 0)) { 
				j = i + 1; //not prime skip ahead to next number
			}
			else if (j == i) { //if i is prime, then i is a possible divisor of x
				divisors.push_back(i); //all numbers prime less than sqroot of x
			}
		}
	}

	//now checking if x is divisible by any of the prime divisors, if it is then it is not prime, otherwise prime
	for (int i = 0; i < divisors.size(); i++) {
		r = x % divisors.at(i);
		if (r == 0) { //x isnt prime so collecting its divisors
			divisorsOfX.push_back(divisors.at(i));
		}
	}

	if (divisorsOfX.empty()) { //x is prime!
		cout << x << " is a prime number!" << endl;
	}
	else {
		cout << x << " is not a prime number! And some of its divisors are..." << endl;
		for (int i = 0; i < divisorsOfX.size(); i++) {
			cout << divisorsOfX.at(i) << " ";
		}
		cout << endl;
	}

}



int main() {
	long long int x = 0, y = 0;
	bool cont = true;
	string response;
	int answer;
	while (cont == true) {
		cout << "Please choose what you would like to do: \nPress 1 to use GCD calcultor \nPress 2 to check if an integer is prime \n";
		cin >> answer;
		switch (answer) {
			case 1: 
				cout << "Enter 2 numbers you would like to calculate the Gretest Common Divisor for: ";
				cin >> x;
				cin >> y;
				if (x == 0 && y == 0) {
					cout << "You must enter two non-zero integers." << endl;
				}
				else {
					cout << "The greatest common divisor (GCD) of " << x << " and " << y << " is " << gcd(x, y) << endl;
				}

				cout << "Would you like to do another calculation? Yes or No?" << endl;
				cin >> response;
				if (response.at(0) == 'y' || response.at(0) == 'Y') {
					cont = true;
				}
				else {
					cont = false;
				}
				break;
			case 2:
				cout << "Enter an integer greater than 1 to check if its prime: ";
				cin >> x;
				primeCheck(x);
				cout << "Would you like to do another calculation? Yes or No?" << endl;
				cin >> response;
				if (response.at(0) == 'y' || response.at(0) == 'Y') {
					cont = true;
				}
				else {
					cont = false;
				}
				break;
			default:
				cout << answer << " is not a valid choice please try again." << endl;
				break;
		}
		
	}

	return 0;
}