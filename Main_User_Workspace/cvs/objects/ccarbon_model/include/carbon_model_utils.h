#ifndef _CARBON_MODEL_UTILS_H_
#define _CARBON_MODEL_UTILS_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * All rights to use the Software are granted on condition that such
 * rights are forfeited if User fails to comply with the terms of
 * this Agreement.
 * 
 * User agrees to identify, defend and hold harmless BATTELLE,
 * its officers, agents and employees from all liability involving
 * the violation of such Export Laws, either directly or indirectly,
 * by User.
 */

/*! 
 * \file carbon_model_utils.h
 * \ingroup Objects
 * \brief The CarbonModelUtils class header file.
 * \author Jim Naslund and Ming Chang
 */

#include "util/base/include/time_vector.h"
#include "land_allocator/include/aland_allocator_item.h"

class LandUseHistory;

/*!
* \brief enum denoting types of carbon flows between boxes.
*/
enum FlowType {
    /*!
     * \brief Box flow - carbon flow due to plant growht, decay, etc..
     */
    eBoxFlow,
    /*!
     * \brief Flow due to land-use change
    */
    eLUCFlow,
    /*!
     * \brief Flow of carbon out due to a decrease in land area
    */
    eLUCFlowOut,
    /*!
     * \brief Flow of carbon in due to an increase in land area
    */
    eLUCFlowIn,
    /*!
     * \brief Any type of flow
    */
    eAnyFlow
};

/*!
* \brief enum denoting types of carbon boxes.
*/
enum BoxType {
    /*!
     * \brief Vegetation type.
     */
    eVegetation,
    /*!
     * \brief Soil type.
     */
    eSoil,
    /*!
     * \brief Litter type.
     */
    eLitter,
    /*!
     * \brief NPP type.
     */
     eNPP,
     /*!
      * \brief Atmosphere type.
      */
      eAtmosphere,
     /*!
      * \brief A box should never be assigned type, it is used in the code
      *        to perform operations on any of the above box types.
      */
     eAnyBox
};

/*
 * \brief Class with static helper functions for carbon models.
 * \author Jim Naslund
 */
class CarbonModelUtils {
public:
    CarbonModelUtils();
    ~CarbonModelUtils();

    static double getLandUse( const unsigned int aYear,
                              const LandUseHistory* aLandUseHistory,
                              const double aHistoricalShare,
                              const objects::PeriodVector<double>& aLandUse );

    static double getSoilTimeScale();
    static const int getStartYear();
    static const int getEndYear();

    static const int getConceptualRootKey(const ALandAllocatorItem* const aItem );

    static double interpYearHelper( const objects::PeriodVector<double>& aPeriodVector,
                                    const unsigned int aYear );

    static double interpYearHelper( const objects::YearVector<double>& aYearVector,
                                    const unsigned int aStartYear,
                                    const unsigned int aEndYear,
                                    const unsigned int aYear );
    static std::string flowTypeToString( FlowType aFlow );
    static std::string boxTypeToString( BoxType aBoxType );
    static BoxType stringBoxNameToType( const std::string aBoxName );
};

#endif // _CARBON_MODEL_UTILS_H_