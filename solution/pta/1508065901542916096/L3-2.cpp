#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)
typedef long long ll;

inline std::string indent(int i) {
	return std::string(i * 2, ' ');
}

bool trim(std::string& s){
	if(s.empty()){
		return false;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return !s.empty();
}

inline std::string&& head(const std::string& wd, int take = 1){
	return std::string(wd.cbegin(), wd.cbegin() + take);
}

std::vector<std::string>
stat_parse(const std::string& code){
	std::vector<std::string> result;
	std::size_t start = 0;
	int nest_brackt = 0;
	rep(i, 0, code.size()){
		const char& c = code[i];
		if(nest_brackt == 0 && c == ';'){
			auto str = code.substr(start, i - start + 1);
			if(!trim(str)) continue;
			result.push_back(str);
			start = i + 1;
			test {
				std::cout << "Lex " << str << std::endl;
			}	
		}else if(c == '{'){
			auto str = code.substr(start, i - start+1);
			if(!trim(str)) continue;
			result.push_back(str);
			start = i+1;
			test {
				std::cout << "Lex " << str << std::endl; 
			}
		}else if(c == '}'){
			result.push_back("}");
			start = i + 1;
			test {
				std::cout << "Lex " << "}" << std::endl;
			}
		}else if(c == '('){
			if(nest_brackt == 0){
				auto str = code.substr(start, i - start);
				if(!trim(str)) continue;
				result.push_back(str);
				test std::cout << "Lex " << str << std::endl; 
				start = i;
			}
			nest_brackt++;
		}else if(c == ')'){
			nest_brackt--;
			if(nest_brackt == 0){
				auto str = code.substr(start, i - start+1);
				if(!trim(str)) continue;
				result.push_back(str);
				test std::cout << "Lex |" << str << "|" << std::endl; 
				start = i + 1;
			}
		}
	}
	return result;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string code;
	std::getline(std::cin, code);
	const auto stats = stat_parse(code);
	int tab = 0;
	
	rep(i, 0, stats.size()){
		const auto& wd = stats[i];
		if(wd == "{"){
			std::cout << "{" << std::endl;
			tab++;
		}else if(wd == "}"){
			tab--;
			std::cout << indent(tab) << "}" ;
			if(stats[i + 1] == "else "){
				std::cout << std::endl;
			}
		}else{
			if(wd == ";"){
				std::cout << ";" << std::endl;
			}else if(wd == "int main"){
				std::cout << wd << "()" << std::endl;
				i++;
			}else if(wd == "if"){
				std::cout << indent(tab) << "if " << stats[i+1] << ' ';
				i+=2;
				if(stats[i] != "{") {
					std::cout << "{" << std::endl;
					tab++;
					i++;
					std::cout << indent(tab) << wd[i] << std::endl;
					tab--;
					std::cout << indent(tab) << "}" << std::endl;
				}
			}else if(wd == "for"){
				std::cout << indent(tab) << "for " << stats[i+1] << ' ';
				i+=2;
				if(stats[i] != "{") {
					std::cout << "{" << std::endl;
					tab++;
					i++;
					std::cout << indent(tab) << wd[i] << std::endl;
					tab--;
					std::cout << indent(tab) << "}" << std::endl;
				}
			}else if(wd == "while"){
				std::cout << indent(tab) << "for " << stats[i+1] << ' ';
				i+=2;
				if(stats[i] != "{") {
					std::cout << "{" << std::endl;
					tab++;
					i++;
					std::cout << indent(tab) << wd[i] << std::endl;
					tab--;
					std::cout << indent(tab) << "}" << std::endl;
				}
			}else if(wd[0] == '('){
				std::cout << wd;
			}else{
				std::cout << indent(tab) << wd;
				if(wd[wd.size()-1] == ';') std::cout << std::endl;
			}
		}
	}

	return 0;
}
