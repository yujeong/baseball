#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be 3 letters.");
		}

		for (char ch : guessNumber) {
			if (0 <= ch && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			return true;
		}
		return false;
	}
};