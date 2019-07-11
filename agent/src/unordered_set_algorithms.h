
/**
 * @file unordered_set_algorithms.h
 * @details Standard C++ doesn't have native support for building
 *          the set intersection and difference between
 *          unordered_sets, so this header file implements that functionality.
 */

#ifndef CONFIG_COMPARE_UNORDERED_SET_ALGORITHMS_H
#define CONFIG_COMPARE_UNORDERED_SET_ALGORITHMS_H

#include <algorithm>

/**
 * @brief Builds an unordered_set of the intersection between two unordered_sets
 *
 * @tparam InputIt1     The type of the first unordered_set's iterator
 * @tparam InputIt2     The type of the second unordered_set's iterator
 * @tparam OutputIt     The type of the output's iterator
 *
 * @param first1        The beginning iterator of the first unordered_set
 * @param first2        The ending iterator of the first unordered_set
 * @param last1         The beginning iterator of the second unordered_set
 * @param last2         The ending iterator of the second unordered_set
 * @param d_first       The output iterator
 * @return              The output iterator
 */
template <class InputIt1, class InputIt2, class OutputIt>
OutputIt unordered_set_intersection(InputIt1 first1, InputIt1 first2, InputIt2 last1, InputIt2 last2, OutputIt d_first)
{

    while (first1 != first2)
    {
        if (!(std::find(last1, last2, *first1) == last2))
        {

            *d_first = *first1;
            ++d_first;

        }

        ++first1;
    }

    return d_first;

}

/**
 * @brief Builds an unordered_set of the difference between two unordered_sets
 *
 * @tparam InputIt1     The type of the first unordered_set's iterator
 * @tparam InputIt2     The type of the second unordered_set's iterator
 * @tparam OutputIt     The type of the output's iterator
 *
 * @param first1        The beginning iterator of the first unordered_set
 * @param first2        The ending iterator of the first unordered_set
 * @param last1         The beginning iterator of the second unordered_set
 * @param last2         The ending iterator of the second unordered_set
 * @param d_first       The output iterator
 * @return              The output iterator
 */
template <class InputIt1, class InputIt2, class OutputIt>
OutputIt unordered_set_difference(InputIt1 first1, InputIt1 first2, InputIt2 last1, InputIt2 last2, OutputIt d_first)
{

    while (first1 != first2)
    {
        if(std::find(last1, last2, *first1) == last2)
        {

            *d_first = *first1;
            ++d_first;

        }

        ++first1;
    }

    return d_first;

}


#endif //CONFIG_COMPARE_UNORDERED_SET_ALGORITHMS_H
