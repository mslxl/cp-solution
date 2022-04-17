#include<bits/stdc++.h>
int main(){
	double mass_ratio, dis_ratio;
	int attr;
	std::cin >> mass_ratio >> attr >>dis_ratio;
	double constant = attr == 0? 2.455 : 1.26;
	
	double xiuu = mass_ratio * constant;
	printf("%.2f ",xiuu);
	if(xiuu * (1.0 / dis_ratio) > 1){
		printf("T_T");
	}else{
		printf("^_^");
	}
	
}
