#import <Foundation/Foundation.h>
#import "CLXSmartLinkOpt.h"

/**
 @brief 无线添加设备
 */
@interface CLXSmartLinkSL : CLXSmartLinkOpt <CLXSmartLinkOpt>

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
 @param sendDataEncryptType CLXSendDataEncryptType 发送数据加密方式
 @param sendCastDataType CLXSendCastDataType 发送数据消息格式
 @param sendCastType CLXSendCastType 发送数据方式
 @param sendContent 是否自定义包信息，没有则传nil
 @param sendTimeout 是否自定义超时时间，没有则传 <0，默认180S
 @return 当前实例
 */
+ (instancetype)newSmartLinkSLWithUserName:(NSString *)userName
                                  password:(NSString *)password
                                shortToken:(NSString *)shortToken
                                     qrKey:(NSString *)qrKey
                                     appId:(NSString *)appId
                                      ssid:(NSString *)ssid
                                   wifiPwd:(NSString *)wifiPwd
                                      mode:(CLXSmartLinkWifiType)mode
                       sendDataEncryptType:(CLXSendDataEncryptType)sendDataEncryptType
                          sendCastDataType:(CLXSendCastDataType)sendCastDataType
                              sendCastType:(CLXSendCastType)sendCastType
                               sendContent:(NSString *)sendContent
                               sendTimeout:(NSInteger)sendTimeout;

@end
