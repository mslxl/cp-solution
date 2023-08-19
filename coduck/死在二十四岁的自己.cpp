#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<ll>> v(1000006);
vector<bool> vis(1000006);
vector<ll> dep(1000006);
vector<ll> num(1000006);

bool cmp(ll a, ll b) { return a > b; }

int main() {
  ll n, q;
  ll maxn = 0;
  cin >> n;
  vector<ll> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    maxn = max(arr[i], maxn);
    //   cout<<i<<" "<<arr[i]<<endl;
  }
  ll ans = 0;
  ll num = 0;
  vector<ll> v(n + 1);
  vector<ll> vis(n + 1);
  int bo = 0;
  ll M = 0;
  // cout<<maxn<<endl;
  for (int i = 1; i <= n; i++) {
    //  cout<<i<<" "<<arr[i]<<endl;;
    v[i] = maxn - arr[i] - 1;
    //  cout<<v[i]<<" ";
    ans += v[i];
    // cout<<ans<<" ";
    if (ans < 0) {
      ans = 0;
      bo = 0;
      continue;
    }
    if (arr[i] == maxn || bo) {
      bo = 1;
      M = max(ans, M);
    }
    // cout<<ans<<endl;
    // num=max(ans,num);
  }
  M = max(ans - 1, M);
  cout << M << endl;
}
