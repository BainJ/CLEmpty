//
//  CLTimelineData.h

#import <Foundation/Foundation.h>
#import "CLTimelineEventClip.h"
#import "CLTimelineSectionClip.h"
#import "CLTimelineInData.h"

/*!
 *  @brief CLTimelineData 时间轴的数据模型
 */
@interface CLTimelineData : NSObject

/*! @cond PRIVATE */

///A string that identify a camera.
@property (nonatomic, copy) NSString *deviceUUID;
///A date object that specifies start time. UTC time.
@property (nonatomic, strong) NSDate *startTime;
///A date object that specifies end time. UTC time.
@property (nonatomic, strong) NSDate *endTime;
///A string that specifies the url of this file.
@property (nonatomic, copy) NSString *downloadServer;
///A section array which object is a CLTimelineSectionClip, used to show sections timeline. Section clips have data.
@property (nonatomic, assign) BOOL hasMore;
@property (nonatomic, strong) NSMutableArray *arraySections;
///A enent array which object is a CLTimelineEventClip, used to show events timeline. Event clip means have motion at that time.
@property (nonatomic, strong) NSMutableArray *arrayEvents;
@property (nonatomic, strong) NSDate *sectionStartTime;
@property (nonatomic, strong) NSDate *sectionEndTime;
@property (nonatomic, strong) NSDate *hasMoreSectionEndTime;
@property (nonatomic, strong) NSDate *hasMoreEventEndTime;//To get old event
@property (nonatomic, strong) NSDate *hasMoreEventStartTime;//To get newest event

/*! @endcond */

- (void)insertEventDatas:(NSArray *)events needUpdateWhenSameID:(BOOL)update;
- (void)insertSectionDatas:(NSArray *)sections needUpdateWhenSameID:(BOOL)update;

/*!
 *
 *  @param llTimeInMS 指定时间戳（长整型）. It is in milliseconds since 1970.
 *
 *  @return 返回指定时间戳的缩略图的地址 
 *
 */
- (NSString *)getThumbnailURLAtTime:(long long)llTimeInMS;

@end
