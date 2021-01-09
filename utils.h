#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Utils {
public:

    static bool equals(const std::string& str1, const std::string& str2) {
        return str1.compare(str2) == 0;
    }

    static std::string to_lowercase(const std::string& action) {
        std::string copy = action;
        transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

        return copy;
    }

    static std::string readFile(const std::string& path) {

        std::string retval;
        std::string line;
        std::ifstream file(path);

        while(getline(file, line)) {
            retval += line + "\n";
        }

        return retval;
    }

    static std::vector<std::string> readFileToVector(const std::string& path) {
        std::vector<std::string> retval;

        std::ifstream file(path);
        std::string line;

        while(getline(file, line)) {
            retval.emplace_back(line);
        }

        return retval;
    }

};