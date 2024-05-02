#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Base class: Job
class Job {
public:
    virtual void action1() = 0;
    virtual void action2() = 0;
    virtual void action3() = 0;
    virtual void action4() = 0;
};

// Subclass: Programmer
class Programmer : public Job {
public:
    void action1() override { std::cout << "Programmer: Writing code\n"; }
    void action2() override { std::cout << "Programmer: Debugging\n"; }
    void action3() override { std::cout << "Programmer: Testing\n"; }
    void action4() override { std::cout << "Programmer: Deploying\n"; }
};

// Subclass: Pilot
class Pilot : public Job {
public:
    void action1() override { std::cout << "Pilot: Pre-flight checks\n"; }
    void action2() override { std::cout << "Pilot: Takeoff\n"; }
    void action3() override { std::cout << "Pilot: In-flight navigation\n"; }
    void action4() override { std::cout << "Pilot: Landing\n"; }
};

// Template function to check if a value is within a range
template <typename T>
bool IsInBounds(T value, T lower, T upper) {
    return (value >= lower) && (value <= upper);
}

// Function to count how many items in a collection match a test function
template <typename Container, typename Predicate>
size_t ContainsTheString(const Container& collection, Predicate testFunc) {
    size_t count = 0;
    for (const auto& item : collection) {
        if (testFunc(item)) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Dynamically allocate instances of Job subclasses
    std::vector<std::unique_ptr<Job>> jobs;
    jobs.push_back(std::make_unique<Programmer>());
    jobs.push_back(std::make_unique<Pilot>());

    // Iterate over the collection and call interface functions
    for (const auto& job : jobs) {
        job->action1();
        job->action2();
        job->action3();
        job->action4();
    }

    // Test IsInBounds function
    uint32_t httpResponseCode = 503;
    std::cout << "Is HTTP response in bounds? "
              << (IsInBounds<uint32_t>(httpResponseCode, 500, 599) ? "Yes" : "No") << "\n";

    // Test ContainsTheString function
    std::vector<std::string> theStrings = {"one", "two", "test"};
    auto count = ContainsTheString(theStrings,  {
        return tested == "test";
    });
    std::cout << "Number of strings matching 'test': " << count << "\n";

    // Write CSV file
    std::ofstream outFile("example.csv");
    outFile << "id,type,name\n"
            << "0,bird,blue\n"
            << "1,cat,felix\n"
            << "2,dog,toto\n";
    outFile.close();

    // Read and transpose CSV data
    std::ifstream inFile("example.csv");
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n";
    }
    inFile.close();

    return 0;
}
