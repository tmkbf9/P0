#include <ctype.h>
#include <string>

#include "validation.h"

bool isValid(const std::string & input) {
    if (input.empty() ) return true;

    for (unsigned i = 0; i < input.length(); ++i) {
      if (!isalpha(input.at(i)) || !islower(input.at(i))) {
	return false;
      }
    }

    return true;
}

