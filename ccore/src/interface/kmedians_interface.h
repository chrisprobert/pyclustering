/**
*
* Copyright (C) 2014-2018    Andrei Novikov (pyclustering@yandex.ru)
*
* GNU_PUBLIC_LICENSE
*   pyclustering is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   pyclustering is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#pragma once


#include "interface/pyclustering_package.hpp"

#include "definitions.hpp"


/**
 *
 * @brief   K-Medians result is returned by pyclustering_package that consist sub-packages and this enumerator provides
 *           named indexes for sub-packages.
 *
 */
enum kmedians_package_indexer {
    KMEDIANS_PACKAGE_INDEX_CLUSTERS = 0,
    KMEDIANS_PACKAGE_INDEX_MEDIANS,
    KMEDIANS_PACKAGE_SIZE
};


/**
 *
 * @brief   Clustering algorithm K-Medians returns allocated clusters.
 * @details Caller should destroy returned result in 'pyclustering_package'.
 *
 * @param[in] p_sample: input data for clustering.
 * @param[in] p_medians: initial medians of clusters.
 * @param[in] p_tolerance: stop condition - when changes of medians are less then tolerance value.
 * @param[in] p_metric: distance metric for distance calculation between objects.
 *
 * @return  Returns result of clustering - array of allocated clusters.
 *
 */
extern "C" DECLARATION pyclustering_package * kmedians_algorithm(const pyclustering_package * const p_sample, 
                                                                 const pyclustering_package * const p_medians, 
                                                                 const double p_tolerance,
                                                                 const void * const p_metric);
