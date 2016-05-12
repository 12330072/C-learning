//
//  vehicle.h
//  Travel
//
//  Created by 邱兆丰 on 16/4/8.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef vehicle_h
#define vehicle_h

#include <cmath>

struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};

class Vehicle {
  public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}
  private:
    double speed;
};

class BicycleStrategy :public Vehicle {
  public:
    BicycleStrategy(double speed) : Vehicle(speed) {
        time = 0;
    }
    virtual void doTravel(const City& src, const City& dest) {
        time = (fabs(src.x - dest.x) + fabs(src.y - dest.y)) / getSpeed();
        std::cout << "It takes " << time << " hours to Travel from " << src.name << " to " << dest.name << " by Bicycle." << std::endl;
    }
  private:
    double time;
};

class TrainStrategy :public Vehicle {
  public:
    TrainStrategy(double speed) : Vehicle(speed) {
        time = 0;
    }
    virtual void doTravel(const City& src, const City& dest) {
        time = sqrt(pow((src.x - dest.x), 2.0) + pow((src.y - dest.y), 2.0)) / getSpeed();
        std::cout << "It takes " << time << " hours to Travel from " << src.name << " to " << dest.name << " by Train." << std::endl;
    }
  private:
    double time;
};

class AirplaneStrategy :public Vehicle {
  public:
    AirplaneStrategy(double speed) : Vehicle(speed) {
        time = 0;
    }
    virtual void doTravel(const City& src, const City& dest) {
        if (fabs(src.x - dest.x) > fabs(src.y - dest.y)) {
            double dis = fabs(src.x - dest.x);
            time = dis / getSpeed();
        } else {
            double dis = fabs(src.y - dest.y);
            time = dis / getSpeed();
        }
        std::cout << "It takes " << time << " hours to Travel from " << src.name << " to " << dest.name << " by Airplane." << std::endl;
    }
  private:
    double time;
};

#endif /* vehicle_h */
