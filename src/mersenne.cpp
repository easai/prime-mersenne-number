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

void _f(mpz_t r, int p) {
	if (p == 0) {
		mpz_set_ui(r, 4);
	} else {
		mpz_t t;
		mpz_init(t);
		_f(t, p - 1);
		mpz_mul(r, t, t);
		mpz_clear(t);
		mpz_sub_ui(r, r, 2);
	}
}

void lucus_lehmer_test(int p) {
	mpz_t f, mod;
	mpz_init(f);
	mpz_init(mod);
	mpz_class mpc = mersenne(p);

	_f(f, p - 2);
	mpz_mod(mod, f, mpc.get_mpz_t());

	if (mpz_cmp_ui(mod, 0) == 0)
		cout << mpc << " is a prime" << endl;
	else
		cout << mpc << " is not a prime" << endl;

	mpz_clear(f);
	mpz_clear(mod);
}

int main(int argc, char* argv[]) {
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
