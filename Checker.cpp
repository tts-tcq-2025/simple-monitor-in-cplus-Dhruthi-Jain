#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float x, float y, float z) {

 if (x < 0) {
        cout << "Temperature LOW! Value: " << x << endl;
        return false;
    }

    if (x > 45) {
        cout << "Temperature HIGH! Value: " << x << endl;
        return false;
    }

if (y < 20) {
        cout << "SOC LOW! Value: " << y << endl;
        return false;
    }
    if (y > 80) {
        cout << "SOC HIGH! Value: " << y << endl;
        return false;
    }

 if (z > 0.8) {
        cout << "Charge Rate HIGH! Value: " << z << endl;
        return false;
    }

    return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(-1, 50, 0.5) == false);
  assert(batteryIsOk(30, 60, 0.9) == false);
  assert(batteryIsOk(0, 20, 0.0) == true);

}
