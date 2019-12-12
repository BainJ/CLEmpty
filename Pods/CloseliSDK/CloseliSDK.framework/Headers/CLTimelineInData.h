//
//  CLTimelineInData.h


#import <Foundation/Foundation.h>

/*!
 *  @brief CLTimelineData 获取SDCard的数据模型
 */
@interface CLTimelineInData : NSObject

///A string that identify a camera.
@property (nonatomic, copy) NSString *deviceUUID;

// 1:qvga; 2:720p
@property (nonatomic, assign) NSInteger channelId;

///A date object that specifies start time. UTC time.
@property (nonatomic, strong) NSDate *startTime;

///A date object that specifies end time. UTC time.
@property (nonatomic, strong) NSDate *endTime;

// the number of sections displayed in a page. optional default is 1000;
@property (nonatomic, assign) NSInteger pageSize;

// the last id in the file list from last enquiry. optional, 0 means empty
@property (nonatomic, assign) NSUInteger lastId;

// the last start time in the file list from last enquiry. optional, -1 means empty
@property (nonatomic, strong) NSDate *lastTime;

- (NSValue *)transfromToInTimeLineParams;

@end

