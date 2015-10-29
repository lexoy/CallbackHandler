#include "Callback_Handler.h"
#include "Callback_Handler.h" // Precompiler test! if "#pragma once" have no effect on some compiler.

#include <iostream> // For test only !

class A {
public:
	int func(int);
};

int A::func(int i) { return i + 1; }

double square(float f) { return f * f; }

int main() {
	A a;
	callback_handler<A, int, int> callbackhandler_01(&a, &A::func);
	int result = callbackhandler_01(1);
	std::cout << result << std::endl;

	callback_handler<A, int, int> callbackhandler_02;
	callbackhandler_02.register_callback(&a, &A::func);
	result = callbackhandler_02(2);
	std::cout << result << std::endl;

	callback_handler<NO_CLASS_TYPE, double, float> callbackhandler_03(&square);
	result = callbackhandler_03(5);
	std::cout << result << std::endl;

	callback_handler<NO_CLASS_TYPE, double, float> callbackhandler_04;
	callbackhandler_04.register_callback(&square);
	result = callbackhandler_04(8);
	std::cout << result << std::endl;

	return 0;
}