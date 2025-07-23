#include <assert.h>
#include <iostream>
using namespace std;

bool isTemperatureOk(float temp) {
  if (temp < 0 || temp > 45) {
    cout << "Temperature out of range! Value: " << temp << "\n";
    return false;
  }
  return true;
}

bool isSocOk(float soc) {
  if (soc < 20 || soc > 80) {
    cout << "State of Charge out of range! Value: " << soc << "\n";
    return false;
  }
  return true;
}

bool isChargeRateOk(float rate) {
  if (rate > 0.8) {
    cout << "Charge Rate out of range! Value: " << rate << "\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temp, float soc, float rate) {
  bool tempStatus = isTemperatureOk(temp);
  bool socStatus = isSocOk(soc);
  bool rateStatus = isChargeRateOk(rate);

  return tempStatus && socStatus && rateStatus;
}
int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(-1, 50, 0.5) == false);
  assert(batteryIsOk(30, 60, 0.9) == false);
  assert(batteryIsOk(0, 20, 0.0) == true);

}
