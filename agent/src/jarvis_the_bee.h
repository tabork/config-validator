
/**
 * @file jarvis_the_bee.h
 * This file name will change.
 * Contains the main function for comparing the functions
 */

#ifndef CONFIG_COMPARE_JARVIS_THE_BEE_H
#define CONFIG_COMPARE_JARVIS_THE_BEE_H

#include <unordered_set>

#include "common.h"

/**
 * @brief Compares two sets of strings using the Jaccard similarity
 * @details \f[
 *              J = \frac{M_{11}}{M_{10} + M_{01} + M_{11}},
 *          \f]
 *              where \f$ M_{11} \f$ is the number of elements in both sets,
 *              \f$ M_{10} \f$ is the number of elements in the first set only,
 *              and \f$ M_{01} \f$ is the number of elements in the second set only.
 *
 * @param baseline_set      The baseline comparison
 * @param compare_set       The set of strings being compared
 * @return                  The Jaccard similarity between the sets of strings
 */
double compare_configs(ConfigSet baseline_set, ConfigSet compare_set);


#endif //CONFIG_COMPARE_JARVIS_THE_BEE_H
