import <iostream>;
import <algorithm>;
import <optional>;
import <vector>;
import <iterator>;

class Rucksack
{
    std::vector<char> firstCompartment;
    std::vector<char> secondCompartment;
    std::vector<char> intersection;
public:
    static std::optional<Rucksack> fromStream(std::istream& stream) {
        std::string line;
        std::getline(stream, line);
        if (line.empty()) {
            return {};
        }
        size_t half = line.length()/2;
        std::string_view line_v(line);
        return Rucksack(line_v.substr(0, half), line_v.substr(half));
    }

    template<typename T>Rucksack(T first, T second) {
        for(char c: first) {
            firstCompartment.push_back(c);
        }
        for(char c: second) {
            secondCompartment.push_back(c);
        }
    }

    char getCommonItem() {
        if (intersection.empty()) {
            std::sort(firstCompartment.begin(), firstCompartment.end());
            std::sort(secondCompartment.begin(), secondCompartment.end());
            std::set_intersection(
                firstCompartment.begin(), firstCompartment.end(),
                secondCompartment.begin(), secondCompartment.end(),
                std::back_inserter(intersection));
        }
        return intersection.front();
    }
};

int prioritize(char item)
{
    if (item >= 'a' && item <= 'z') {
        return 1 + (item - 'a');
    }
    if (item >= 'A' && item <= 'Z') {
        return 27 + (item - 'A');
    }
    return 0;
}

int main()
{
    int sum = 0;
    while (auto rucksack = Rucksack::fromStream(std::cin)) {
        sum += prioritize(rucksack->getCommonItem());

    }
    std::cout << sum << std::endl;
    return 0;
}
