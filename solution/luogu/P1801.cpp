#include <bits/stdc++.h>

typedef long long ll;

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

inline std::vector<ll> get_line_stream(std::size_t element_len) {
  std::vector<ll> vec(element_len);
  for (int i = 0; i < element_len; i++) {
    std::cin >> vec[i];
  }
  return vec;
}

inline std::priority_queue<ll, std::vector<ll>, std::greater<ll>>
get_line_heap(std::size_t l) {
  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> heap;
  ll input;

  for (int i = 0; i < l; i++) {
    std::cin >> input;
    heap.push(input);
  }
  return heap;
}

int N, M;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N >> M;
  std::string trash;
  std::getline(std::cin, trash);

  auto input_seq = get_line_stream(N);
  std::size_t idx_read = 0;

  #define read() input_seq[idx_read++]

  auto ask = get_line_heap(M);

  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> small;
  std::priority_queue<ll, std::vector<ll>, std::less<ll>> big;

  ll input = read();
  small.push(input);
  if (ask.top() == 1) {
    test {
      std::cout << "The first one was be asked." << std::endl;
    }
    ask.pop();
    std::cout << small.top() << '\n';
    big.push(small.top()), small.pop();
  }

  for (int i = 2; i <= N; i++) {
    input = read();

    test { std::cout << "Input " << input << std::endl; }

    if (!big.empty() && input < big.top()) {
      big.push(input);

      test {
        std::cout << "Push input into big, move " << big.top()
                  << " from big to small heap" << std::endl;
      }
      small.push(big.top()), big.pop();

    } else {
      test { std::cout << "Push input into small heap" << std::endl; }

      small.push(input);
    }

    while (!ask.empty() && ask.top() == i) {
      ask.pop();
      std::cout << small.top() << '\n';
      big.push(small.top()), small.pop();
    }
  }

  return 0;
}
