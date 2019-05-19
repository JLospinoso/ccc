#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <functional>

using namespace std;

struct SpeedUpdate {
  double velocity_mps;
};

struct CarDetected {
  double distance_m;
  double velocity_mps;
};

struct BreakCommand {
  double time_to_collision_s;
};

using SpeedUpdateCallback = function<void(const SpeedUpdate&)>;
using CarDetectedCallback = function<void(const CarDetected&)>;

struct IServiceBus {
  virtual ~IServiceBus() = default;
  virtual void publish(const BreakCommand&) = 0;
  virtual void subscribe(SpeedUpdateCallback) = 0;
  virtual void subscribe(CarDetectedCallback) = 0;
};

struct MockServiceBus : IServiceBus {
  void publish(const BreakCommand& cmd) override {
    commands_published++;
    last_command = cmd;
  };
  void subscribe(SpeedUpdateCallback callback) override {
    speed_update_callback = callback;
  };
  void subscribe(CarDetectedCallback callback) override {
    car_detected_callback = callback;
  };
  BreakCommand last_command{};
  int commands_published{};
  SpeedUpdateCallback speed_update_callback{};
  CarDetectedCallback car_detected_callback{};
};

struct AutoBrake {
  AutoBrake(IServiceBus& bus)
      : collision_threshold_s{ 5 } /*,
    speed_mps{} */
  {
    bus.subscribe([this](const SpeedUpdate& update) { speed_mps = update.velocity_mps; });
    bus.subscribe([this, &bus](const CarDetected& cd) {
      auto relative_velocity_mps = speed_mps - cd.velocity_mps;
      auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
      if(time_to_collision_s > 0 && time_to_collision_s <= collision_threshold_s) {
        bus.publish(BreakCommand{ time_to_collision_s });
      }
    });
  }
  void set_collision_threshold_s(double x) {
    if(x < 1)
      throw runtime_error{ "Collision less than 1." };
    collision_threshold_s = x;
  }
  double get_collision_threshold_s() const {
    return collision_threshold_s;
  }
  double get_speed_mps() const {
    return speed_mps;
  }

  private:
  double collision_threshold_s;
  double speed_mps;
};

TEST_CASE("AutoBrake") {
  MockServiceBus bus{};
  AutoBrake auto_break{ bus };

  REQUIRE(auto_break.get_speed_mps() == 0);
}
