#import <Foundation/Foundation.h>
#import "CLXSmartLinkOpt.h"

/**
 @brief 有线添加设备
 */
@interface CLXSmartLinkWR : CLXSmartLinkOpt <CLXSmartLinkOpt>

/**
 @remark 构造函数
 
 @param userName 用户名account
 @param shortToken 短token
 @param qrKey qrKey，平台提供
 @param macAddress 设备mac
 @return 当前实例
 */
+ (instancetype)newSmartLinkWRWithUserName:(NSString *)userName
                                shortToken:(NSString *)shortToken
                                     qrKey:(NSString *)qrKey
                                macAddress:(NSString *)macAddress;


@end
