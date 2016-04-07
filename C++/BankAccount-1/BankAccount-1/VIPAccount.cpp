#include "VIPAccount.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12050000;

VIPAccount::VIPAccount() {
    _id = VIPAccount::_acc_id_ptr++;
    _total_vip_account++;
    _balance = 10.0;
    _loan = 0.0;
    _loan_limit = 1000.0;
}

VIPAccount::~VIPAccount() {
    _total_vip_account--;
}

bool VIPAccount::loan(const double &num) {
    if (_loan + num < 1000 && num > 0) {
        _loan += num;
        deposit(num);
        return true;
    }
    return false;
}

bool VIPAccount::repay(const double &num) {
    if (_balance - num < 0.01 || num <= 0) {
        return false;
    } else {
        if (num > _loan) {
            draw(_loan);
            _loan = 0.0;
        } else {
            draw(num);
            _loan -= num;
        }
        return true;
    }
}

std::string VIPAccount::profile() const {
    ostringstream out;
    out << "ID:" << _id << endl;
    out << "BALANCE:" << setprecision(6) << fixed << _balance << endl;
    out << "VALID:Y" << endl;
    out << "TYPE:VIP" << endl;
    out << "LOAN:" << setprecision(6) << fixed << _loan << ',';
    out << "LIMIT:" << setprecision(6) << fixed << _loan_limit << endl;
    return out.str();
}

void VIPAccount::reset() {
    _loan = 0.0;
    _loan_limit = 1000;
    _balance = 10.0;
}

int VIPAccount::get_total_vip_account() {
    return _total_vip_account;
}
