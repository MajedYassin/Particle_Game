#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "Hello, Welcome to the nuclear reactor chamber distribution game!" << std::endl;
    unsigned int N= 0;
    int K = 0, A = 0;
    std::cout << "What is the maximum number of bombarding particles per chamber? ";
    std::cin >> N;
    std::cout << std::endl;
    std::cout << "What is the total number of particles involved in these reactions(no more than a million)? ";
    std::cin >> A;
    std::cout << "What is the number of chambers being used? ";
    std::cin >> K;

    std::cout << "Inputs:" << std::endl;
    std::cout << " " << A << " " << N << " " << K << std::endl;

    int &Particles = A;

    std::vector<int> array(K);
    array.assign(K, 0);
    std::vector<int>::size_type i = K-1;

    while(i != 0){
        int num = 0;
        while(Particles > std::pow(i, N)) {
            num++;
            array[i] = num;
            Particles -= std::pow(i, N);
        }
        if(array[i] > 100) array[i] = 0;
        --i;
    }

    std::cout << Particles << std::endl;

    array[0]= Particles;

    std::cout << "Output: " << std::endl;
    for (std::vector<int>::size_type n = 0; n != K; ++n){
        std::cout << array[n] << ' ';
    }
    return 0;
}