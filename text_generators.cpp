#include "text_generators.h"

/**
 * @brief MT::trademark_calculation_EN
 * @param trademark_name
 * @param calculation
 * @return String to be pasted to email
 */
std::string MT::trademark_calculation_EN(const std::string &trademark_name, const std::vector<int> &calculation)
{
    std::string result;
    if (trademark_name.empty()){
        result = "Registration of mentioned trademark will cost:\n\n";
    }
    else{
        result = "Registration of trademark \"" + trademark_name + "\" will cost\n\n";
    }
    result += "Filing procedure:\n";
    result += "Office fee - " + std::to_string(calculation[0]) + " Euro\n";
    result += "Service fee - " + std::to_string(calculation[1]) + " Euro\n\n";

    result += "Granting procedure:\n";
    result += "Office granting fee - " + std::to_string(calculation[2]) + " Euro\n";
    result += "Office publication fee - " + std::to_string(calculation[3]) + " Euro\n";
    result += "Service fee - " + std::to_string(calculation[4]) + " Euro";

    if (calculation[5] != 0){
        result += "\n\nAcceleration:\n";
        result += "Office fee - " + std::to_string(calculation[5]) + " Euro\n";
        result += "Service fee - " + std::to_string(calculation[6]) + " Euro";
    }

    return result;
}
