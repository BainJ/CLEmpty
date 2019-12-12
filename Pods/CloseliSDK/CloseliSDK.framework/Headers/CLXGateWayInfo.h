//
//  CLXGateWayInfo.h

#import <Foundation/Foundation.h>

/**
 @brief 网关列表返回model
 */
@protocol CLXGateWayInfo <NSObject>

@property (nonatomic, copy) NSString *gatewaymac;
@property (nonatomic, copy) NSString *gatewayname;
@property (nonatomic, copy) NSString *clientid;
@property (nonatomic, copy) NSString *modelid;
@property (nonatomic, copy) NSString *remark;

@end

@interface CLXGateWayInfo : NSObject <CLXGateWayInfo>

@end
