#include "ecret.hpp"

float ecret::operator()(float x) const {return (x > seuil) ? seuil : x;}
