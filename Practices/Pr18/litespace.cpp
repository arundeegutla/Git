#include <bits/stdc++.h>
using namespace std;

int convert(string s) {
	int retval = 0;

	int pow = 1;
	for (int i = s.size() - 1; i >= 1; i--) {
		if (s[i] == 'T') {
			retval += pow;
		}
		pow *= 2;
	}

	if (s[0] == 'T')
		retval *= -1;

	return retval;
}

int main() {
	string s; cin >> s;
	deque<int> stck;
	for (int i = 0; i < s.size(); i++) {
		int a = 0, b = 0, num = 0;
		string binNum = "";
		switch (s[i]) {
			case 'S':
				i++;
				switch (s[i]) {
					case 'S':
						i++;
						binNum = "";
						while (s[i] != 'N')
							binNum += s[i++];
						num = convert(binNum);
						stck.push_back(num);
						break;
					case 'N':
						i++;
						switch (s[i]) {
							case 'S':
								if (stck.size() < 1) {
									cout << "Invalid copy operation\n";
									break;
								}
								stck.emplace_back(stck.back());
								break;
							case 'T':
								if (stck.size() < 2) {
									cout << "Invalid swap operation\n";
									break;
								}
								a = stck.back(); stck.pop_back();
								b = stck.back(); stck.pop_back();
								stck.push_back(a);
								stck.push_back(b);
								break;
							case 'N':
								if (stck.size() < 1) {
									cout << "Invalid remove operation\n";
									break;
								}
								stck.pop_back();
								break;
						}
						break;
				}
				break;
			case 'T':
				i++;
				switch (s[i]) {
					case 'S':
						i++;
						switch (s[i]) {
							case 'S':
								i++;
								switch (s[i]) {
									case 'S':
										if (stck.size() < 2) {
											cout << "Invalid addition operation\n";
											break;
										}
										a = stck.back(); stck.pop_back();
										b = stck.back(); stck.pop_back();
										stck.push_back(a + b);
										break;
									case 'T':
										if (stck.size() < 2) {
											cout << "Invalid subtraction operation\n";
											break;
										}
										a = stck.back(); stck.pop_back();
										b = stck.back(); stck.pop_back();
										stck.push_back(b - a);
										break;
									case 'N':
										if (stck.size() < 2) {
											cout << "Invalid multiplication operation\n";
											break;
										}
										a = stck.back(); stck.pop_back();
										b = stck.back(); stck.pop_back();
										stck.push_back(a * b);
										break;
								}
								break;
							case 'T':
								i++;
								if (stck.size() < 2) {
									cout << "Invalid division operation\n";
									break;
								}
								a = stck.back();
								if (a == 0) {
									cout << "Division by zero\n";
									break;
								}
								stck.pop_back();
								b = stck.back(); stck.pop_back();
								stck.push_back(b / a);
								break;
						}
						break;
					case 'N':
						i += 2;
						if (stck.size() < 1) {
							cout << "Invalid print operation\n";
							break;
						}
						a = stck.back(); stck.pop_back();
						cout << a << endl;
						break;
				}
				break;
		}
	}
	return 0;
}
						
