#include<iostream>
#include<map>
#include<cctype>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

std::map<std::string, std::string> map;
void stdrandize(std::string& str) {
	for (auto& c : str) {
		c = tolower(c);
	}
	std::sort(str.begin(), str.end());
}
int main() {
	std::string wd;
	while (std::cin >> wd && wd != "#") {
		std::string cpy(wd);
		stdrandize(cpy);
		if (!map.count(cpy)) {
			map[cpy] = wd;
		}
		else {
			map[cpy] = "";
		}
	}
	
	std::set<std::string> buf;
	for (auto s : map) {
		if (s.second != "") {
			buf.insert(s.second);
		}
	}
	for (auto s : buf) {
		std::cout << s << std::endl;
	}
}