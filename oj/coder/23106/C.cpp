#include <iostream>
#include <vector>

int n;
int nop = 0;
int main() {
  int st[3];
  std::cin >> n;
  std::vector<int> record(n * 5, 0);
  std::vector<int> lineNo(n);

  int currentLine = 0, nop = 0;

  for (int sent = 0; sent < n; sent++) {
    std::cin >> st[0] >> st[1] >> st[2];

    for (int i = 1; i <= 3; i++) {
      if(sent - i < 0) break;
      if (st[i-1] && currentLine - lineNo[sent - i] < 4) {
        // std::cout << "(Line " << currentLine << ") sentence " << sent << " conflict with a head of last " << i <<" , which is in line " << lineNo[sent-i] << std::endl;
        int insert = 4 - (currentLine - lineNo[sent - i]);
        // std::cout << "insert " << insert << " nop" << std::endl;
        nop += insert;
        currentLine += insert;
      }
    }

    lineNo[sent] = currentLine;
    currentLine++;
  }
  std::cout << nop;

  return 0;
}
