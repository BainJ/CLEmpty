//
//  CLXOperationHelperProtocol.h

#ifndef CLXOperationHelperProtocol_h
#define CLXOperationHelperProtocol_h

#import "CLXHttpClientDefine.h"
/*!
 @brief Operation - H5页面扩展等相关API
 */
@protocol CLXOperationHelperProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configOperationHelperToken:(nullable NSString *)token;

/**
 获取用户全部的App广告
 
 @param account 用户账号
 @param bundleId Bundle Id for App
 @param extra 请求第三方的额外信息
 @param completion Completion Handler
 */
- (void)getStartPageWithAccount:(nonnull NSString *)account
                       bundleId:(nonnull NSString *)bundleId
                          extra:(nullable NSDictionary *)extra
                     completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取用户全部的App广告
 
 @param account 用户账号
 @param bundleId Bundle Id for App
 @param extra 请求第三方的额外信息
 @param supportDuiba 是否支持兑吧
 @param completion Completion Handler
 */
- (void)getStartPageWithAccount:(nonnull NSString *)account
                       bundleId:(nonnull NSString *)bundleId
                          extra:(nullable NSDictionary *)extra
                   supportDuiba:(BOOL)supportDuiba
                     completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取TimeLine上的广告页面
 
 @param deviceId 设备ID
 @param function Function Type - 1.全遮 2.云存储在期 3.云存储即将到期 4.有录像10秒体验 5.无录像10秒体验
 @param completion Completion Handler
 */
- (void)getAdsWithDeviceId:(nonnull NSString *)deviceId
                  function:(nonnull NSString *)function
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取H5活动列表
 
 @param completion Completion Handler
 */
- (void)getH5ActivityList:(CLXHttpTaskCompletionHandler)completion;

/**
 获取当前设备的服务活动信息
 
 @param deviceId 设备ID
 @param completion Completion Handler
 */
- (void)getDeviceActivityListWithDeviceId:(nonnull NSString *)deviceId
                               completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXOperationHelperProtocol_h */
