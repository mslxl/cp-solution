#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)

struct Num {
    std::deque<int> bits;
    Num(const std::string& number) {
        for (int i = number.size() - 1; i >= 0; i--)
            bits.push_back(number[i] - '0');
    }
    Num(int number) {
        while (number > 0) {
            bits.push_back(number % 10);
            number /= 10;
        }
    }

    Num(std::deque<int> data) : bits(data) {}
    Num operator+(int rhs) const { return (*this) + Num(rhs); }
    Num operator+(const Num& rhs) const {
        auto& r = rhs.bits;
        auto& l = this->bits;
        auto& maxBits = r.size() > l.size() ? r : l;
        auto& minBits = r.size() <= l.size() ? r : l;
        int forwardNumber = 0;
        std::deque<int>::const_iterator minBegin = minBits.cbegin();
        std::deque<int>::const_iterator maxBegin = maxBits.cbegin();
        std::deque<int> result;
        while (minBegin != minBits.cend()) {
            int resultB = *minBegin + *maxBegin + forwardNumber;
            forwardNumber = resultB / 10;
            result.push_back(resultB % 10);
            minBegin++;
            maxBegin++;
        }
        while (maxBegin != maxBits.cend()) {
            int resultB = *maxBegin + forwardNumber;
            forwardNumber = resultB / 10;
            result.push_back(resultB % 10);
            maxBegin++;
        }
        if (forwardNumber != 0) {
            result.push_back(forwardNumber);
        }
        Num ret(result);
        return ret;
    }
    Num operator*(const Num& rhs) const {
        auto& maxBits =
            rhs.bits.size() > this->bits.size() ? rhs.bits : this->bits;
        auto& minBits =
            rhs.bits.size() <= this->bits.size() ? rhs.bits : this->bits;
        auto calcPerBit = [maxBits](int minBit) -> Num {
            assert(minBit < 10);
            std::deque<int> ret;
            int forward = 0;
            for (auto b : maxBits) {
                int result = b * minBit + forward;
                forward = result / 10;
                ret.push_back(result % 10);
            }
            if (forward != 0)
                ret.push_back(forward);

            return Num(ret);
        };
        Num sum(0);
        for (int i = 0; i < minBits.size(); i++) {
            auto tmp = calcPerBit(minBits[i]);
            _for(cnt, 0, i) { tmp.bits.push_front(0); }
            sum = sum + tmp;
        }
        return sum;
    }
    Num operator*(int rhs) const { return (*this) * Num(rhs); }
    std::size_t len() const { return bits.size(); }
    bool operator==(const Num& rhs) const {
        if (this->len() != rhs.len())
            return false;
        for (auto cBegin = this->bits.cbegin(), rBegin = rhs.bits.cbegin();
             cBegin != this->bits.cend(); cBegin++, rBegin++) {
            if (*cBegin != *rBegin)
                return false;
        }
        return true;
    }
    bool operator!=(const Num& rhs) const { return !((*this) == rhs); }
    Num operator-(const Num& rhs) const {
        if (rhs == *this)
            return Num(0);
        assert(rhs < *this);
        auto result = this->bits;
        for (std::size_t i = 0; i < rhs.len(); i++) {
            int tmp = result[i] - rhs.bits[i];
            if (tmp < 0) {
                result[i + 1]--;
                result[i] = (10 + result[i]) - rhs.bits[i];
            } else {
                result[i] = tmp;
            }
        }
        return Num(result);
    }

    bool operator<(const Num& rhs) const {
        if (this->len() < rhs.len())
            return true;
        else if (this->len() > rhs.len())
            return false;

        for (auto i = this->len() - 1; i > 0; i--) {
            if (this->bits[i] < rhs.bits[i])
                return true;
            else if (this->bits[i] > rhs.bits[i])
                return false;
        }
        std::size_t i = 0;
        if (this->bits[i] < rhs.bits[i])
            return true;
        else if (this->bits[i] > rhs.bits[i])
            return false;
        return false;
    }
    bool operator>(const Num& rhs) const {
        return !(*this < rhs || *this == rhs);
    }
    Num pow(const Num& times) const {
        Num cur(this->bits);
        Num curTimes(1);
        while (curTimes < times) {
            cur = cur * (*this);
            curTimes = curTimes + 1;
        }
        return cur;
    }
    Num sp(std::size_t han) const {
        auto result = std::deque<int>(this->bits);
        result.resize(han);
        return Num(result);
    }
    bool operator<=(const Num& rhs) const {
        return *this < rhs || *this == rhs;
    }
};

std::ostream& operator<<(std::ostream& os, const Num& num) {
    for (int i = num.bits.size() - 1; i >= 0; i--)
        os << num.bits[i];
    return os;
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string n;
    std::cin >> n;
    Num numN(n);
    Num sum(0);
    Num i(1);
    while (i <= numN) {
        sum = sum + (i.pow(i + 1));
        i = i + 1;
    }
    std::cout << sum << std::endl;

    return 0;
}