#include "feescalculation.h"

using namespace std;

int main(int argc, char** argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {return std::make_unique<MT::FeesCalculation>(env);});
}
