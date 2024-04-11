#include <iostream>
#include <sstream>

using namespace std;

string scramble(string word);

int main() {
	srand(time(0));

	string line;
	line = "I dont give a Holstein for programmers that can only spell a variable one way. ( Dr. Stephany ) ";

	string word;
	bool wordStart = false;
	for (char c : line) {
		if (isalpha(c)) {
			word += c;
			wordStart = true;
		}
		else if (wordStart) {
			cout << scramble(word) << " ";
			word.clear();
			wordStart = false;
		}
		else {
			cout << c;
		}
	}

	if (!word.empty()) {
		cout << scramble(word);
	}
	return 0;
}

string scramble(string word) {
	if (word.length() <= 3) {
		return word;
	}

	string scrambledWord = word;

	int firstIndex = rand() % (word.length() - 2) + 1;
	int secondIndex = rand() % (word.length() - 2) + 1;

	while (secondIndex == firstIndex) {
		secondIndex = rand() % (word.length() - 2) + 1;
	}

	swap(scrambledWord[firstIndex], scrambledWord[secondIndex]);

	return scrambledWord;
}
