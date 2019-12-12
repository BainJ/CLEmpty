//
//  CLMotionRegion.h

#import <Foundation/Foundation.h>

/**
 @brief region信息模型
 */
@interface CLMotionRegion : NSObject <NSCopying, NSCoding>

/*! @cond PRIVATE */

///Index for this region
@property (nonatomic) int32_t region_id;
///Left postion for this region 0-5
@property (nonatomic) int32_t iLeft;
///Top postion for this region 0-5
@property (nonatomic) int32_t iTop;
///Right postion for this region 0-5
@property (nonatomic) int32_t iRight;
///Bottom postion for this region 0-5
@property (nonatomic) int32_t iBottom;
///Sensitivity to motion detection in this region, 0-100
@property (nonatomic) int32_t iSensitivity;
///INVALID!!! If enable or reverse this region for motion detection, please use same enable for all regions
@property (nonatomic) BOOL enable;

/*! @endcond */
- (BOOL)isEqualMotionRegion:(id)anObject;

@end
