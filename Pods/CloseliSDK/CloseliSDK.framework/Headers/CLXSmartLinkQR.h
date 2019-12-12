#import <Foundation/Foundation.h>
#import "CLXSmartLinkOpt.h"

/**
 @brief 二维码添加设备
 */
@interface CLXSmartLinkQR : CLXSmartLinkOpt <CLXSmartLinkOpt>

/**
 @remark 构造函数

 @param userName 用户名account
 @param password 密码
 @param shortToken 短token
 @param qrKey qrKey，平台提供
 @param appId 产品ID
 @param ssid Wi-Fi
 @param wifiPwd Wi-Fi密码
 @param mode Wi-Fi加密模式
 @return 当前实例
 */
+ (instancetype)newSmartLinkQRWithUserName:(NSString *)userName
                                  password:(NSString *)password
                                shortToken:(NSString *)shortToken
                                     qrKey:(NSString *)qrKey
                                     appId:(NSString *)appId
                                      ssid:(NSString *)ssid
                                   wifiPwd:(NSString *)wifiPwd
                                      mode:(CLXSmartLinkWifiType)mode;

@end
