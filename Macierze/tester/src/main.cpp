#include "pamsi_tester/Tester.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <numeric>
#include <vector>

class SumTester : public Tester<int, std::vector<int>>
{
  protected:
    std::vector<int> runAlgorithm(const std::vector<int>& inputData) override;
    std::vector<int> readSingleInput(std::istream& inputStream) override;
};


// override of the ostream << operator
std::ostream& operator<<(std::ostream& output, std::vector<int> finalSum)
{
    for(auto i: finalSum)
    {
        output << i << " ";
    };
    return output;
}

// summing the elements of the two matrices
std::vector<int> SumTester::runAlgorithm(const std::vector<int>& inputData)
{
    int matrixSize = inputData[0]*inputData[1];
    std::vector<int> sumOfMAtrices;

    for(auto i = 2; i < 2+matrixSize; i++)
    {
       sumOfMAtrices.push_back(inputData[i]+inputData[i+matrixSize]) ;
    }

    return sumOfMAtrices;
}

// taking in the size and values of both matrices into a vector
std::vector<int> SumTester::readSingleInput(std::istream& inputStream)
{

    int n = 0;  //number of rows
    int m = 0;  //number of columns

    inputStream >> n;
    inputStream >> m;

    std::vector<int> result;

    result.push_back(n);
    result.push_back(m);

    for(auto i = 0; i < 2*n*m; i++)
    {
        int dataElement;
        inputStream >> dataElement;

        result.push_back(dataElement);
    }

    return result;

}

int main(int /*argc*/, char* /*argv*/[])
{
    std::ifstream inputFile{"input.txt"};
    std::ofstream dataOutputFile{"output.txt"}, timeOutputFile{"times.csv"};

    SumTester tester;

    if(!inputFile)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }

    tester.runAllTests(inputFile, dataOutputFile, timeOutputFile);
}
