#import <Foundation/Foundation.h>
#import "CLXSmartLinkOpt.h"

/**
 @brief AP添加设备
 */
@interface CLXSmartLinkAP : CLXSmartLinkOpt <CLXSmartLinkOpt>

/**
 @remark 构造函数
 
 @param userName 用户名account
 @param shortToken 短token
 @param qrKey qrKey，平台提供
 @param regType 注册方式 0:无线 1:有线
 @return 当前实例
 */
+ (instancetype)newSmartLinkAPWithUserName:(NSString *)userName
                                shortToken:(NSString *)shortToken
                                     qrKey:(NSString *)qrKey
                                   regType:(NSInteger)regType;

/**
 @remark 重新设置regType
 
 @param regType 注册方式 0:无线 1:有线
 */
- (void)resetRegType:(NSInteger)regType;

/**
 @remark 获取到WiFi信息后，设置wifi

 @param ssid Wi-Fi Wi-Fi SSID名
 @param wifiPwd Wi-Fi密码
 @param wifiMode Wi-Fi加密类型 @see CLXSmartLinkWifiType
 */
- (void)setWifiSSID:(NSString *)ssid wifiPwd:(NSString *)wifiPwd wifiMode:(CLXSmartLinkWifiType)wifiMode;

/**
 @remark 第一步获取Wi-Fi列表

 @param completion 返回Wi-Fi列表
 */
- (void)getWifiList:(CLXSmartLinkCompletionBlock)completion;

@end
