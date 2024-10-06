#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

class Bitset {
public:
	vector<bool> bits;

	Bitset() {}

    Bitset(int length) {
        bits.resize(length, false);
    }

    Bitset AND(const Bitset& other) const {
        if (this->bits.size() != other.bits.size()) {
            throw std::invalid_argument("Bitsets must be of the same size.");
        }

        Bitset result(this->bits.size());
        for (size_t i = 0; i < this->bits.size(); ++i) {
            result.bits[i] = this->bits[i] && other.bits[i];
        }

        return result;
    }


    Bitset OR(const Bitset& other) const {
        if (this->bits.size() != other.bits.size()) {
            throw std::invalid_argument("Bitsets must be of the same size.");
        }

        Bitset result(this->bits.size());
        for (size_t i = 0; i < this->bits.size(); ++i) {
            result.bits[i] = this->bits[i] || other.bits[i];
        }

        return result;
    }

 
    Bitset XOR(const Bitset& other) const {
        if (this->bits.size() != other.bits.size()) {
            throw std::invalid_argument("Bitsets must be of the same size.");
        }

        Bitset result(this->bits.size());
        for (size_t i = 0; i < this->bits.size(); ++i) {
            result.bits[i] = this->bits[i] ^ other.bits[i];
        }

        return result;
    }


    void print() const {
        for (bool bit : bits) {
            cout << bit << ' ';
        }
        cout << endl;
    }
};


int main() {
    Bitset a(4);
    Bitset b(4);

	std::array<bool, 4> a{ 1, 0, 1, 1 };
	std::array<bool, 4> b{ 1, 1, 0, 0 };

    Bitset andResult = a.AND(b);
    Bitset orResult = a.OR(b);
    Bitset xorResult = a.XOR(b);

    cout << "A: "; a.print();
    cout << "B: "; b.print();
    cout << "A AND B: "; andResult.print();
    cout << "A OR B: "; orResult.print();
    cout << "A XOR B: "; xorResult.print();

    return 0;
}