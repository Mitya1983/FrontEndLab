#ifndef FEES_H
#define FEES_H

namespace MT {

namespace Trademark {

namespace Office {

const int filing = 4000;
const int filing_color = 1000;
const float additional_applicants = 1.3;
const int granting = 200;
const int publication = 600;
const int publication_color = 200;
const int acceleration_non_combined_one_class = 5220;
const int acceleration_non_combined_additional_class = 612;
const int acceleration_combined_one_class = 9396;
const int acceleration_combined_additional_class = 960;

} // namespace Office

namespace Service {
const int filing = 200;
const int additional_classes = 20;
const int granting = 150;
const int acceleration = 150;

} // namespace Service

} // namespace Trademark

namespace Invention {

namespace Office {

const int filing = 1600;
const int additional_claims = 160;
const int substantive_examination = 6000;
const int granting = 100;
const int publication = 400;
const int additional_pages = 20;

} // namespace Service

namespace Service {

const int translation = 8;
const int filing = 400;
const int substantive_examination = 150;
const int granting = 150;

} // namespace Service

} // namespace Invention

namespace UtilityModel {

namespace Office {

const int filing = 2400;
const int additional_claims = 240;
const int granting = 100;
const int publication = 600;
const int additional_pages = 30;

} // namespace Service

namespace Service {

const int translation = 8;
const int filing = 350;
const int granting = 150;

} // namespace Service

} // namespace UtilityModel

namespace IndustrialDesign {

namespace Office {

const int filing = 1600;
const int additional_designs_till_ten = 200;
const int additional_designs_after_ten = 700;
const int granting = 100;
const int publication = 300;
const int publication_color = 200;

} // namespace Office

namespace Service {

const int filing = 300;
const int additional_designs_till_ten = 50;
const int additional_designs_after_ten = 100;
const int granting = 150;

} // namespace Service

} // namespace IndustrialDesign

namespace General {

const int bank_commission = 25;
const int hour_rate = 100;

} // namespace General

} // namespace MT

#endif // FEES_H
