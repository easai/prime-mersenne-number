// mersenne.cpp  -- Calculate Mersenne prime number

// Copyright (c) 2016, 2017 easai

// Compile as (requires gmp library):
// g++ mersenne.cpp -lgmpxx -lgmp
//

// Code:

#include <unistd.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;

mpz_class mersenne(int p) {
	mpz_class mp;
	mpz_ui_pow_ui(mp.get_mpz_t(), 2, p);
	mp--;
	return mp;
}

int main(int argc, char* argv[]) {
	int nopt = 0;
	char *nparam = NULL;
	int opt;
	while ((opt = getopt(argc, argv, "h")) != -1) {
		switch (opt) {
		case 'h':
			printf("Usage: mersenne n\n");
			break;
		}
	}

	int n;
	if (optind < argc) {
		n = atoi(argv[optind]);

		mpz_class mp = mersenne(n);
		cout << mp;
	}

	return 0;
}

// mersenne.cpp ends here
