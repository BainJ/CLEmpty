//
//  CLXAPDirectConnectWrapper.h

#import <Foundation/Foundation.h>
#import "CLXApGetDeviceInfoResult.h"
#import "CLXApVerifyResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^CLXAPDirectLinkCompletionBlock)(BOOL result, id response, NSError * _Nullable error);

@interface CLXAPDirectConnectWrapper : NSObject

/**
 获取局域网内设备列表

 @param callback response为CLXApGetDeviceInfoResult @see CLXApGetDeviceInfoResult
 */
- (void)getAPDeviceList:(CLXAPDirectLinkCompletionBlock)callback;


/**
 获取局域网内设备列表 并传入设备的时区信息

 @param offset 时区偏移量,秒
 @param callback response为CLXApGetDeviceInfoResult @see CLXApGetDeviceInfoResult
 */
- (void)getAPDeviceListWithTimeOffset:(NSNumber  * _Nullable)offset callback:(CLXAPDirectLinkCompletionBlock)callback;


/**
 停止获取局域网内设备列表
 */
- (void)stopGetAPDeviceList;

/**
 校验用户名密码

 @param userId 用户名
 @param password 密码
 @param getDeviceInfoResult 设备列表返回 CLXApGetDeviceInfoResult
 @param callback response为CLXApVerifyResult @see CLXApVerifyResult
 */
- (void)verifyUserId:(NSString *)userId
            password:(NSString *)password
 getDeviceInfoResult:(CLXApGetDeviceInfoResult *)getDeviceInfoResult
            callback:(CLXAPDirectLinkCompletionBlock)callback;

/**
 修改用户名密码

 @param newPassword 新的密码
 @param oldPassword 旧的密码
 @param getDeviceInfoResult 设备列表返回 CLXApGetDeviceInfoResult
 @param callback response为CLXApVerifyResult @see CLXApVerifyResult
 */
- (void)changePassword:(NSString *)newPassword
           oldPassword:(NSString *)oldPassword
   getDeviceInfoResult:(CLXApGetDeviceInfoResult *)getDeviceInfoResult
              callback:(CLXAPDirectLinkCompletionBlock)callback;

/**
 设置Wi-Fi连接密码

 @param newPassword 新密码
 @param getDeviceInfoResult 设备列表返回 CLXApGetDeviceInfoResult
 @param callback response为CLXApVerifyResult @see CLXApVerifyResult
 */
- (void)setPassword:(NSString *)newPassword
getDeviceInfoResult:(CLXApGetDeviceInfoResult *)getDeviceInfoResult                                                                          callback:(CLXAPDirectLinkCompletionBlock)callback;

// 设置电池电量回调block
- (void)setBatteryChanageBlock:(CLXAPDirectLinkCompletionBlock)batteryChanageBlock;

@end

NS_ASSUME_NONNULL_END
