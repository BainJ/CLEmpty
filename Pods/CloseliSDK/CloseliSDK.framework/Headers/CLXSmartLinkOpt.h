//
//  CLXSmartLinkOpt.h

#import <Foundation/Foundation.h>
#import "CLXSmartLinkDefine.h"

/**
 @brief 当前添加设备block

 @param response 返回结果
 */
typedef void (^CLXSmartLinkCompletionBlock)(BOOL result, id response, NSError *error);

/**
 @brief SmartLink 添加设备公共协议, 无特殊操作默认Step 1 -> Step 2 -> Step 3
 */
@protocol CLXSmartLinkOpt <NSObject>

/**
 @remark 添加方式, Step 1, 如果失败则无法进行添加
 
 @param completion completion handle
 */
- (void)prepare:(CLXSmartLinkCompletionBlock)completion;

/**
 @remark 添加方式, Step 2

 @param completion completion handle
 */
- (void)start:(CLXSmartLinkCompletionBlock)completion;

/**
 @remark 添加方式, Step 3

 @param completion completion handle
 */
- (void)stop:(CLXSmartLinkCompletionBlock)completion;

@end

/**
 @brief 设备添加
 */
@interface CLXSmartLinkOpt : NSObject

@property (nonatomic, copy, readonly) NSString *checkId;

/**
 @remark 设置passid、passtoken
 
 @param passId passid
 @param passToken passtoken
 */
- (void)setPassIdAndTokenWithPassId:(NSString *)passId passToken:(NSString *)passToken;

/**
 @remark 获取到WiFi信息后，设置wifi
 
 @param ssid Wi-Fi Wi-Fi SSID名
 @param wifiPwd Wi-Fi密码
 @param wifiMode Wi-Fi加密类型 @see CLXSmartLinkWifiType
 */
- (void)setWifiSSID:(NSString *)ssid wifiPwd:(NSString *)wifiPwd wifiMode:(CLXSmartLinkWifiType)wifiMode;

@end
