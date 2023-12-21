#ifndef ROBOT_H
#define ROBOT_H
#include <set>
#include <string>

class Robot {
private:
  std::string robotName;
  std::set<std::string> robotNames;

public:
  const std::string name() const { return robotName; }
  Robot(std::set<std::string> rn) {
    robotNames = rn;
    reset(rn);
  };
  void reset(std::set<std::string> rn);
  std::string generateName();
  ~Robot() {
    auto it = robotNames.find(robotName);
    robotNames.erase(it);
  }
};
#endif // !ROBOT_H
