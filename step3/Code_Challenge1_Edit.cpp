#include <iostream>

// SampleObject1: Represents an integer-based result
struct SampleObject1 {
    int getResult(const int& param1, const int& param2, const int& param3) const {
        return (param1 + param2 + param3 > 0) ? 1 : 0;
    }
};

// SampleObject2: Represents a string-based result
struct SampleObject2 {
    std::string getResult(const int& param1, const int& param2, const int& param3) const {
        return (param1 + param2 + param3 > 0) ? "true" : "false";
    }
};

// Template function to check if the sum of parameters is positive
template <typename T, typename U>
T checkIfPositive(const U& u, const int& param1, const int& param2, int param3 = 0) {
    // Existing irrelevant code (not relevant to this exercise)

    // Call the getResult function from the provided object
    return u.getResult(param1, param2, param3);
}

int main() {
    // Calls to checkIfPositive with different parameters
    int iResult = checkIfPositive<bool, SampleObject1>(SampleObject1{}, 1, 2);
    std::cout << iResult << std::endl;
    iResult = checkIfPositive<bool, SampleObject1>(SampleObject1{}, 1, -2);
    std::cout << iResult << std::endl;
    iResult = checkIfPositive<bool, SampleObject1>(SampleObject1{}, 1, -2, 3);
    std::cout << iResult << std::endl;

    std::string sResult = checkIfPositive<std::string, SampleObject2>(SampleObject2{}, 1, 2);
    std::cout << sResult << std::endl;

    return 0;
}
