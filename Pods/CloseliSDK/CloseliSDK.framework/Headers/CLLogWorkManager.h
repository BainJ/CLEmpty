//
//  CLLogWorkManager.h
//  CLLogManager日志收拢主管理类，提供ELK和Protobuffer两套基础日志格式化及类型。其中，上传方式均由代理抛出至上层处理

#import <Foundation/Foundation.h>

@class CLLogCommonParam;
@class DeviceActionObj;
@interface CLLogWorkManager : NSObject
@property (nonatomic, assign) BOOL debugLogEnabled;
// 保证生命周期只有一个
@property (nonatomic, copy) NSString *actionId;

+ (instancetype)sharedInstance;
- (int64_t)time;

/**
 CMD全链路日志添加开始
 
 @param deviceId 信令唯一标识
 @param param 请求参数
 @param type 信令通道类型 2：webSocket，0：logon
 */
- (void)addSendCmdSessionDeviceId:(NSString *)deviceId
                             type:(NSInteger)type
                            param:(NSString *)param;

/**
 CMD全链路日志添加结束

 @param deviceId 设备id
 @param type 信令通道类型 2：webSocket，0：logon
 @param param 请求参数
 @param failRes 错误码
 */
- (void)addSendFailCmdSessionDeviceId:(NSString *)deviceId
                                 type:(NSInteger)type
                                param:(NSString *)param
                              failRes:(NSInteger)failRes;

/**
 lib库透传日志上传

 @param type 100、101
 @param message 透传数据
 @param requestId requestId
 */
- (void)addSendGPLibMessage:(int)type
                    message:(NSString *)message
                  requestId:(NSString *)requestId;

#pragma mark - 实时
/**
 获取一个新的requestId

 @return requestId
 */
- (NSString *)gpRequestId;
/**
 埋点数据并发送
 
 @param appActions 行为动作，app的行为，可以批量上报
 @param requestId 传则启用，不传默认
 */
- (void)addLogWithAppActions:(NSArray<DeviceActionObj *> *)appActions requestId:(NSString *)requestId;

/**
 上传日志
 */
- (void)uploadLogToServer;

@end
