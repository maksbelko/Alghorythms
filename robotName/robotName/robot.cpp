#include "robot.h"
#include <random>
void Robot::reset(std::set<std::string> rn) {

  if (robotName.length() > 0) {
    try {
      auto it = robotNames.find(robotName);
      robotNames.erase(it);
      std::string tempRobotName = generateName();
      // checks if name already exists
      if (robotNames.insert(tempRobotName).second) {
        robotName = tempRobotName;
      } else {
        throw("Name already exists");
      }
    } catch (...) {
      reset(rn);
    }
  }
}
std::string Robot::generateName() {
  std::random_device rd;
  auto gen = std::mt19937(rd());
  ;
  std::uniform_int_distribution<> alpha_distribution('A', 'Z');
  std::uniform_int_distribution<> numeric_distribution(0, 999);

  std::string alpha1 = std::string(1, (char)alpha_distribution(gen));
  std::string alpha2 = std::string(1, (char)alpha_distribution(gen));
  std::string numeric = std::to_string(numeric_distribution(gen));
  // replace needed number of '0'
  numeric = std::string(3 - numeric.length(), '0') + numeric;

  return alpha1 + alpha2 + numeric;
}