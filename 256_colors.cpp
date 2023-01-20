#include <iostream>
#include <stdio.h>

#define WIDTH 5
#if WIDTH % 2 != 1
#error "WIDTH has to be odd"
#endif

using namespace std;

inline void vonalzo(const size_t &num, const char &c = '-', const bool &b = 1);
inline size_t num_of_digits(int i);

signed main(){

	vonalzo(WIDTH * 8 + WIDTH + 2);
	cout << '|';
	vonalzo(WIDTH, 'H', 0);
	cout << '|';
	for(int h = 0; h < 8; h++){
		cout << '|';
		vonalzo((WIDTH - 3) / 2, ' ', 0);
		cout << h;
		vonalzo((WIDTH - 3) / 2, ' ', 0);
		cout << '|';
	}
	cout << endl;
	vonalzo(WIDTH * 8 + WIDTH + 2);

	for(int i = 0; i < 256; i++){
		if(i % 8 == 0){
			cout << '|';
			vonalzo((WIDTH - 3) / 2 + (3 - num_of_digits(i)), ' ', 0);
			cout << i;
			vonalzo((WIDTH - 3) / 2, ' ', 0);
			cout << '|';
		}
		cout << "\33[48;5;" << i << 'm';
		vonalzo(WIDTH, ' ', 0);
		if(i % 8 == 7){
			cout << "\33[0m" << endl;
		}
	}

	cout << "\33[0m" << endl;

	return 0;
}

inline void vonalzo(const size_t &num, const char &c, const bool &b){
	for(int i = 0; i < num; i++){
		cout << c;
	}
	if(b == 1){
		cout << endl;
	}
}

inline size_t num_of_digits(int i){
	int c = 1;
	if(i < 0){
		c++;
	}
	abs(i);

	while(i >= 10){
		i = i / 10;
		c++;
	}

	return c;
}
