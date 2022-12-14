import <iostream>;
import <optional>;
import <string>;

std::optional<int> get_next_elf(std::istream& stream)
{
    int calories = 0;
    std::string line;
    while (std::getline(stream, line)) {
        if (line.empty()) {
            return {calories};
        }
        calories += std::stoi(line);
    }
    return {};
}

int main()
{
    int most_calories = 0;
    while (auto calories = get_next_elf(std::cin)) {
        most_calories = std::max(*calories, most_calories);
    }
    std::cout << most_calories << std::endl;
    return 0;
}
