import <iostream>;
import <optional>;
import <string>;
import <algorithm>;
import <numeric>;
import <ranges>;
import <vector>;

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
    std::vector<int> carried_calories;
    while (auto calories = get_next_elf(std::cin)) {
        carried_calories.push_back(*calories);
    }
    std::sort(carried_calories.begin(), carried_calories.end(), std::greater<int>());
    auto top_3 = std::views::counted(carried_calories.begin(), 3);
    std::cout << std::accumulate(top_3.begin(), top_3.end(), 0) << std::endl;
    return 0;
}
