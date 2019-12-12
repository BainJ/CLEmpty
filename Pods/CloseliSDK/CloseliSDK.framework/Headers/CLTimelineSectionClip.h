//
//  CLTimelineSectionClip.h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 *  @brief CLTimelineEventClip 表示一段视频剪辑
 */
@interface CLTimelineSectionClip : NSObject<NSCopying>
/*！视频的sectionID */
@property (nonatomic, copy) NSString *sectionID;
/*！视频开始时间, UTC */
@property (nonatomic, strong) NSDate *startTime;
/*！视频结束时间, UTC */
@property (nonatomic, strong) NSDate *endTime;
/*！section源，有cloud，SD卡 */
@property (nonatomic, assign) NSInteger sectionFrom;
/*！视频下载地址 */
@property (nonatomic, copy) NSString *downloadServer;
/*！来自分享的Token */
@property (nonatomic, copy) NSString *shareToken;

/**
 获取缩略图

 @param deviceUUID deviceid
 @param timeStamp 时间戳
 @param size 例如 CGSizeMake（180，180）
 @return URL字符串
 */
- (NSString *)getThumbnailURL:(NSString *)deviceUUID
                    timeStamp:(NSString *)timeStamp
                         size:(CGSize)size;
@end
