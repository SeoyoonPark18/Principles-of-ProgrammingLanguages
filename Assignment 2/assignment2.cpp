#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<string, int>&a, pair<string, int>&b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int N = 12;
	float numbers[N] = { 645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25 };
	vector<pair<string, int>> people;
	people.push_back({ "Hal", 20 }); people.push_back({ "Susann", 31 }); people.push_back({ "Dwight", 19 }); people.push_back({ "Kassandra", 21 }); people.push_back({ "Lawrence", 25 });
	people.push_back({ "Cindy", 22 }); people.push_back({ "Cory", 27 }); people.push_back({ "Mac", 19 }); people.push_back({ "Romana", 27 });
	people.push_back({ "Doretha", 32 }); people.push_back({ "Danna", 20 }); people.push_back({ "Zara", 23 }); people.push_back({ "Rosalyn", 26 });
	people.push_back({ "Risa", 24 }); people.push_back({ "Benny", 28 }); people.push_back({ "Juan", 33 }); people.push_back({ "Natalie", 25 });

	//numbers acending numerically
	sort(numbers, numbers + N);
	for (int i = 0; i < N; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\n" << "\n";

	//people alphabetically by name
	sort(people.begin(), people.end());
	for (int i = 0; i < people.size(); i++) {
		cout << people[i].first << ", " << people[i].second << "; ";
	}
	cout << "\n" << "\n";

	//people decending by age, same age sorted alphabetically
	sort(people.begin(), people.end(), compare);
	for (int i = 0; i < people.size(); i++) {
		cout << people[i].first << ", " << people[i].second << "; ";
	}

	return 0;
}