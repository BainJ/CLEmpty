//
//  CLXMsgParam.h

#import <Foundation/Foundation.h>


@interface CLXMsgParam : NSObject
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *channelNo;                // -> 子设备必传
@property (nonatomic, assign) NSInteger deviceType;             // -> 1 、普通Ipc 2、中继或NVR (也包含子设备)

- (instancetype)initWithJsonString:(NSString *)jsonString;

- (NSString *)toJsonString;

+ (CLXMsgParam *)buildMsgParam:(NSString *)deviceId;
@end

