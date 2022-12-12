import <iostream>;
import <optional>;

enum class Play {Rock = 1, Paper = 2, Scissors = 3};
enum class Outcome {Loss = 0, Draw = 3, Win = 6};

Play reverseRPS(Outcome result, Play opponent) {
    if (result == Outcome::Draw) {
        return opponent;
    }
    int ourplay = static_cast<int>(opponent);
    if (result == Outcome::Win) {
        ourplay++;
        if (ourplay > 3) {
            ourplay = 1;
        }
    } else {
        ourplay--;
        if (ourplay < 1) {
            ourplay = 3;
        }
    }
    return Play{ourplay};
}

std::optional<int> score_next_hand(std::istream& stream)
{
    std::string line;
    std::getline(stream, line);
    if (line.empty()) {
        return {};
    }
    Play opponent{1+(line[0]-'A')};
    Outcome result{3*(line[2]-'X')};
    auto me = reverseRPS(result, opponent);
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
