#pragma once

#include <unistd.h>

using doses_t=unsigned int;
using pourcent_t=unsigned int;

// Réservoir d'eau
const doses_t CAPA_EAU = 10;
const useconds_t SLEEP_REMPL_EAU = 2000000;
const useconds_t SLEEP_PRELE_EAU = 200000;

// Réservoir de café soluble
const doses_t CAPA_SOLUBLE = 10;
const useconds_t SLEEP_REMPL_SOLUBLE = 3000000;
const useconds_t SLEEP_PRELE_SOLUBLE = 300000;

// Réservoir de café en poudre
const doses_t CAPA_POUDRE = 10;
const useconds_t SLEEP_REMPL_POUDRE = 3000000;
const useconds_t SLEEP_PRELE_POUDRE = 300000;
const useconds_t SLEEP_TASSE_POUDRE = 100000;






