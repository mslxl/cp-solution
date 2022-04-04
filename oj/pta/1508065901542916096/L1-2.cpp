#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
int main(){
	int price, s;
	scanf("%d%d", &price, &s);
	printf("%.2lf", price * (0.1 * s));
	return 0;
}
