#include "calculation.h"
#include <boost/asio.hpp>
#include <sstream>
#include <string>
#include "fees.h"
/**
 * @brief Function for trademark registration costs calculation
 * @param number_of_classes
 * @param currency_rate
 * @param colored
 * @param accelerated
 * @param combined
 * @return std::vector with following values:
 *          std::vector[0] = Filing office fee;
 *          std::vector[1] = Filing service fee;
 *          std::vector[2] = Granting office fee;
 *          std::vector[3] = Publication office fee;
 *          std::vector[4] = Granting service fee;
 *          std::vector[5] = Acceleration office fee;
 *          std::vector[6] = Acceleration service fee;
 */
std::vector<int> MT::calculateTrademark(int number_of_classes, double currency_rate, bool colored,
                                        bool more_then_one_applicant, bool accelerated, bool combined)
{
    int filing_office_fee = 0;
    int filing_service_fee = 0;
    int granting_office_fee = 0;
    int publication_office_fee = 0;
    int acceleration_office_fee = 0;

    filing_office_fee = number_of_classes * MT::Trademark::Office::filing;
    filing_service_fee = MT::Trademark::Service::filing;
    if (number_of_classes > 3){
        filing_service_fee += (number_of_classes - 3) * MT::Trademark::Service::additional_classes;
    }
    granting_office_fee = MT::Trademark::Office::granting;
    publication_office_fee = number_of_classes * MT::Trademark::Office::publication;
    if (colored){
        filing_office_fee += MT::Trademark::Office::filing_color;
        publication_office_fee += MT::Trademark::Office::publication_color;
    }
    if (more_then_one_applicant){
        filing_office_fee *= MT::Trademark::Office::additional_applicants;
    }
    filing_office_fee /= currency_rate;
    MT::round(filing_office_fee);
    publication_office_fee /= currency_rate;
    MT::round(publication_office_fee);
    if (accelerated){
        if (!combined){
            acceleration_office_fee = MT::Trademark::Office::acceleration_non_combined_one_class;
            if (number_of_classes > 1){
                acceleration_office_fee += (number_of_classes - 1) * MT::Trademark::Office::acceleration_non_combined_additional_class;
            }
        }
        else{
            acceleration_office_fee = MT::Trademark::Office::acceleration_combined_one_class;
            if (number_of_classes > 1){
                acceleration_office_fee += (number_of_classes - 1) * MT::Trademark::Office::acceleration_combined_additional_class;
            }
        }
        acceleration_office_fee /= currency_rate;
        MT::round(acceleration_office_fee);
    }
    std::vector<int> result{
            filing_office_fee,
            filing_service_fee,
            granting_office_fee,
            publication_office_fee,
            MT::Trademark::Service::granting,
            acceleration_office_fee,
            MT::Trademark::Service::acceleration};
    result.shrink_to_fit();
    return result;
}

void MT::round(int &value)
{
    int temp = value % 10;
    if (temp < 5){
        value += 5 - temp;
    }
    else if (temp > 5){
        value += 10 - temp;
    }
}
