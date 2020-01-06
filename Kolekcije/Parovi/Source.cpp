#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

struct pairhash {
public:
	template <typename T, typename U>
	size_t operator()(const pair<T, U> &x) const
	{
		size_t p = 0;
		p += (19 * p + hash<T>()(x.first));
		p += (19 * p + hash<U>()(x.second));
		return p;
	}
};

int main() {

	set<pair<int, int>> s;
	unordered_set<pair<int, int>, pairhash> us;
	int m;
	int a, b;

	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		pair<int, int> p = make_pair(a, b);
		if (s.find(p) != s.end()) break;
		s.insert(p);
	}

	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << "(" << it->first << "," << it->second << ")" << endl;
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		pair<int, int> p = make_pair(a, b);
		if (us.find(p) != us.end()) break;
		us.insert(p);
	}

	for (auto it = us.begin(); it != us.end(); ++it) {
		cout << "(" << it->first << "," << it->second << ")" << endl;
	}


	return 0;
}