#include <iostream>
#include <vector>
#include <cmath>

//This is simple mathematical problem solving exercise


//Code Function & Descripton:
// - A Fictional power plant containing K number of reactors is being injected with A number of particles in stages
//Each of the reactors are connected in chain (not-realistic) and once one reactor is filled to it's max capacity N,
// the particles in said reactor annihilate/burn off, emptying the contents of that reactor
// This results in a single residual particle passing into the next reactor along the chain,
// Following this, particles are once again injected into the first reactor in the chain

//The purpose of this code is to simply calculate the remaining number of particles in each core once all the particles been injected

//Rules & Parameters:
// Each reactor has the same capacity
// The User is asked to define the maximum capacity of the cores N;
// The total number of particles being injected into the cores A;
// And number of cores being used K;



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
        while(Particles > std::pow(N, i)) {
            ++num;
            array[i] = num;
            Particles -= std::pow(N, i);
        }
        if(array[i] > N) array[i] = 0;
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

