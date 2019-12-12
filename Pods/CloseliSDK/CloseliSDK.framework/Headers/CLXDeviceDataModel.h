
#import <Foundation/Foundation.h>
#import "CLXTimelineInterval.h"

@interface CLXDeviceDataModel : NSObject

@end

/*
 用于保存timeLine时间段
 规则：
 1、endTime不能小于startTime，否则构造函数返回nil
 2、endTime如果超出startTime七天，则返回startTime加七天的sectionModel
 3、建议使用startTime和interval方式构造对象
 */
@interface CLXTimeSection: NSObject
@property(nonatomic, strong) NSDate *startTime;
@property(nonatomic, strong) NSDate *endTime;

//根据startTime和timeInterval构造对象
- (instancetype)initWithStartTime:(NSDate *)startTime timeInterval:(CLXTimelineInterval)interval; // 推荐使用

//根据startTime和endTime构造对象，endTime不能小于startTime，否则返回nil
- (instancetype)initWithStartTime:(NSDate *)startTime endTime:(NSDate *)endTime;

@end
