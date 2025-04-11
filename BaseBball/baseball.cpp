#include <stdexcept>
using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) { }

	GuessResult guess(const string& guessNumber) {
		GuessResult result = { false, 0, 0 };

		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3 , 0 };
		}
		
		result.strikes = getStrikes(guessNumber);
		result.balls = getBalls(guessNumber);
		return result;
	}

	int getStrikes(const string guessNumber)
	{
		int strikeCnt = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				strikeCnt++;
			}
		}
		return strikeCnt;
	}

	int getBalls(const string guessNumber)
	{
		int ballCnt = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) continue;

			int ret = question.find(guessNumber[i]);
			if (ret != std::string::npos)
				ballCnt++;
		}
		return ballCnt;
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
private:
	string question;	
};