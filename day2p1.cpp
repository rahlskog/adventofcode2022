import <iostream>;
import <optional>;

enum class Play {Rock = 1, Paper = 2, Scissors = 3};
enum class Outcome {Loss = 0, Draw = 3, Win = 6};

Outcome RPS(Play player, Play opponent) {
    if (player == opponent) {
        return Outcome::Draw;
    }
    if (player == Play::Rock && opponent == Play::Scissors) {
        return Outcome::Win;
    }
    if (player == Play::Paper && opponent == Play::Rock) {
        return Outcome::Win;
    }
    if (player == Play::Scissors && opponent == Play::Paper) {
        return Outcome::Win;
    }
    return Outcome::Loss;
}

std::optional<int> score_next_hand(std::istream& stream)
{
    std::string line;
    std::getline(stream, line);
    if (line.empty()) {
        return {};
    }
    Play opponent{1+(line[0]-'A')};
    Play me{1+(line[2]-'X')};
    auto result = RPS(me, opponent);
    return {static_cast<int>(me) + static_cast<int>(result)};
}

int main()
{
    int total_score = 0;
    while (auto score = score_next_hand(std::cin)) {
        total_score += *score;
    }
    std::cout << total_score << std::endl;
    return 0;
}
