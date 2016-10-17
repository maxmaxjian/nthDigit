#include <iostream>
#include <cmath>

class solution {
  public:
    int findNthDigit(int n) {
        int nd = 1;
        while (totalNDgts(nd)<n) {
            // std::cout << totalNDgts(nd) << std::endl;
            nd++;
        }
        if (totalNDgts(nd)==n)
            return 1;
        else {
            // std::cout << "nd = " << nd << std::endl;
            int rest = n-totalNDgts(nd-1);
            // std::cout << "rest = " << rest << std::endl;
            int q = rest/nd, r = rest%nd;
            int num = int(pow(10,nd-1))+q;
            std::cout << num << std::endl;
            while (r < nd-1) {
                num /= 10;
                r++;
            }
            return num%10;
        }
    }

  private:
    int totalNDgts(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n*int(pow(10,n)-1);
            n--;
        }
        return sum;
    }
};


int main() {
    int n = 10089;

    solution soln;
    int ndigit = soln.findNthDigit(n);
    std::cout << "The " << n << "th digit is:\n"
              << ndigit << std::endl;
}
