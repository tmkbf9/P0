#include <assert.h>
#include <sstream>
#include <iostream>

#include "validation.h"

using namespace std;

void test_validation_empty_input() {
    string input;

    assert(input.empty());
    assert(isValid(input) == true);
}

void test_validation_one_letter_only_returns_valid() {
    string input = "a";

    assert(input.empty() == false);
    assert(isValid(input) == true);
}

void test_validation_one_uppercase_letter_returns_invalid() {
    string input = "A";

    assert(input.empty() == false);
    assert(isValid(input) == false);
}

void test_validation_one_number_returns_invalid() {
    string input = "1";

    assert(input.empty() == false);
    assert(isValid(input) == false);
}

void test_validation_two_lowercase_letters_returns_valid() {
    string input = "ab";

    assert(input.empty() == false);
    assert(isValid(input) == true);
}

void test_validation_one_lowercase_letter_followed_by_an_invalid_char_returns_invalid() {
    string input1 = "a1";
    string input2 = "aA";
    string input3 = "a?";

    assert(isValid(input1) == false);
    assert(isValid(input2) == false);
    assert(isValid(input3) == false);
}



int main(int argc, char** argv) {
    test_validation_empty_input();
    test_validation_one_letter_only_returns_valid();
    test_validation_one_uppercase_letter_returns_invalid();
    test_validation_one_number_returns_invalid();
    test_validation_two_lowercase_letters_returns_valid();
    test_validation_one_lowercase_letter_followed_by_an_invalid_char_returns_invalid();

	exit(0);
}
