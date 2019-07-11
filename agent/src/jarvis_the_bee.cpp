
/**
 * @file jarvis_the_bee.cpp
 * The filename will change.
 * Contains the implementation for comparing two configs.
 */

#include "jarvis_the_bee.h"

#include "unordered_set_algorithms.h"

#include "common.h"

#include <unordered_set>
#include <iterator>
#include <algorithm>

double compare_configs(ConfigSet baseline_set, ConfigSet compare_set)
{

    // Get the number of elements in both sets
    std::unordered_set<std::string> intersect;
    unordered_set_intersection(baseline_set.begin(), baseline_set.end(),
                               compare_set.begin(), compare_set.end(),
                               std::inserter(intersect, intersect.begin()));
    int M11 = intersect.size();

    // Get the number of elements in baseline_set but not compare_set
    std::unordered_set<std::string> base_diff;
    unordered_set_difference(baseline_set.begin(), baseline_set.end(),
                             intersect.begin(), intersect.end(),
                             std::inserter(base_diff, base_diff.begin()));
    int M10 = base_diff.size();

    // Get the number of elements in compare_set but not baseline_set
    std::unordered_set<std::string> comp_diff;
    unordered_set_difference(compare_set.begin(), compare_set.end(),
                             intersect.begin(), intersect.end(),
                             std::inserter(comp_diff, comp_diff.begin()));
    int M01 = comp_diff.size();

    // Return the Jaccard Index
    return ((double)M11 / ((double)M10 + (double)M01 + (double)M11));

}