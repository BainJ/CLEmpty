//
//  CLXPurchaseProtocol.h

#ifndef CLXPurchaseProtocol_h
#define CLXPurchaseProtocol_h

#import "CLXHttpClientDefine.h"

/**
 @brief 购买云套餐相关API
 */
@protocol CLXPurchaseProtocol<NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configPurchaseToken:(nullable NSString *)token;

/**
 是否支持0元领取功能接口

 @param devices 设备mac地址列表，示例["xxxxS_3c330015116f","xxxxS_3c3300151161","xxxxS_3c3300151162"]
 @param completion Completion Handler
 */
- (void)getCameraTrailAllowWithToken:(nonnull NSString *)token
                             devices:(nonnull NSArray *)devices
                          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取服务购买URL.
 你可以用UIWebView打开. 为了安全以及加速服务考虑，请用post方式加载
 网站默认支持支付宝，微信支付不支持第三方用户，要显示UI，传payType=1.
 当 webView.request.URL.absoluteString 包含 "appPaySuccess",订单成功.

 @param deviceId 设备ID
 @param payType 国内用户设置关闭微信支付，payType=1.
 @param isInternational 是否是国际化URL，国外用的paypal
 @param completion Completion Handler { NSURL }
 */
- (void)getServicePurchaseUrl:(nonnull NSString *)deviceId
                      payType:(nullable NSString *)payType
              isInternational:(BOOL)isInternational
                   completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXPurchaseProtocol_h */
