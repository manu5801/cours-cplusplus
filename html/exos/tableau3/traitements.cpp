#include "traitements.hpp"

	float homo::operator()(float x) const {return facteur*x;};
	float ecret::operator()(float x) const {return (x > seuil) ? seuil : x;};
