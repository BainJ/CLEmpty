//
//  CLTimelineEventClip.h

#import <Foundation/Foundation.h>
#import "CLTimelineConst.h"

/*!
 *  @brief CLTimelineEventClip 表示一个事件剪辑.它拥有一些事件视频的属性，还包括一些方法获取视频缩略图、时间轴的事件类型等.
 */
@interface CLTimelineEventClip : NSObject<NSCopying>

/*! @cond PRIVATE */
/*！视频的eventID */
@property (nonatomic, copy) NSString *eventID;
///Specifies a events type, by motion, by sound, or by face detection.
@property (nonatomic, copy) NSString *eventType;
///a tag string that specifies a event tag.
@property (nonatomic, copy) NSString *eventTag;
///A string that specifies a event name.
@property (nonatomic, copy) NSString *eventName;
///A url string that specifies the download address.
@property (nonatomic, copy) NSString *downloadURL;
///A date that indicates the start time. UTC time.
@property (nonatomic, strong) NSDate *startTime;
///A date that indicates the end time. UTC time.
@property (nonatomic, strong) NSDate *endTime;
@property (nonatomic, assign) NSInteger eventStatus;
@property (nonatomic, copy) NSString *personID;
@property (nonatomic, assign) NSInteger eventFrom;
@property (nonatomic, copy) NSString *shareToken;
/*! @endcond */

- (NSString *)getThumbnailURL:(NSString *)deviceUUID;
- (NSString *)getFisheyeThumbnailURL:(NSString *)deviceUUID;
- (CLXEventMode)getEventType;
- (bool)isNoDataEvent;
- (bool)hasEventData;
- (NSMutableArray *)getPersonIDArray;

@end
