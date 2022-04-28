#include<bits/stdc++.h>

std::vector<int> prefix_table(const std::string& pattern) {
	std::vector<int> prefix(pattern.size());
	prefix[0] = 0;
	int len = 0;
	std::size_t i = 1;
	while(i < pattern.size()) {
		if(pattern[len] == pattern[i]) {
			len++;
			prefix[i] = len;
			i++;
		} else {
			if(len > 0) {
				len = prefix[len-1];
			} else {
				prefix[i] = 0; //一定匹配失败了，不挣扎了
				i++;
			}
		}
	}
	return prefix;
}
void move_prefix_table(std::vector<int>& prefix) {
	prefix.insert(prefix.begin(), -1);
	prefix.erase(prefix.end()-1);
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern, std::vector<int> prefix) {
	move_prefix_table(prefix);
	std::vector<int> position;
	// text[i]
	// pattern[j]
	std::size_t i = 0, j = 0;
	while(i < text.size()) {
		if(text[i] == pattern[j]) {
			if(j == pattern.size() - 1) {
				// matched completly!
				position.push_back(i-j);
				
				j = prefix[j];
				if(j == -1) {
					i++, j++;
				}
			}else{
				i++, j++;
			}
		} else {
			j = prefix[j];
			if(j == -1) {
				i++, j++;
			}
		}
	}
	return position;
}


int main() {
	std::string pattern;
	std::string text;
	std::cin >> text >> pattern;
	std::vector<int> prefix = prefix_table(pattern);
	std::vector<int> position = kmp_search(text, pattern, prefix);
	
	
	for(const auto& p : position){
		std::cout << (p+1) << std::endl;
	}
	std::cout << prefix[0];
	for(int i = 1; i < prefix.size();i++){
		std::cout << " " << prefix[i];
	}
	return 0;
}
