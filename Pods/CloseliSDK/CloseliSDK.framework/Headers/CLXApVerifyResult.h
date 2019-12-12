//
//  CLXApVerifyResult.h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 AP模式交互返回的通用model
 */
@interface CLXApVerifyResult : NSObject

@property (nonatomic, assign) NSInteger code;               //-> 错误码
@property (nonatomic, copy) NSString *key3;
@property (nonatomic, assign) NSInteger response;           //-> 对应request，例如7是设置密码
@property (nonatomic, copy) NSString *sessionid;            //-> 每次sessionid唯一，标志是连续一次事件
@property (nonatomic, copy) NSString *time;                 //-> 时间戳

@end

/**
 电池电量上报的model
*/
@interface CLXApBatteryResult : CLXApVerifyResult

@property (nonatomic, assign) NSInteger batteryStatus;          //-> 电池状态
@property (nonatomic, assign) NSInteger batteryPercent;         //-> 电池电量百分比

@end

NS_ASSUME_NONNULL_END
