#ifndef CALCULATION_H
#define CALCULATION_H
#include <vector>
namespace MT {

std::vector<int> calculateTrademark(int number_of_classes, double currency_rate,
                                    bool colored, bool more_then_one_applicant, bool accelerated, bool combined);
void round(int &value);

} // namespace MT

#endif // CALCULATION_H
