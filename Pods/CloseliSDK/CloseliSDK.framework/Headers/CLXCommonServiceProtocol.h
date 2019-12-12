//
//  CLXCommonServiceProtocol.h

#ifndef CLXCommonServiceProtocol_h
#define CLXCommonServiceProtocol_h

#import "CLXHttpClientDefine.h"
/*!
@brief 公共服务相关API，此模块是一些公共服务类接口，例如获取验证码、检查兼容性
*/
@protocol CLXCommonServiceProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configCommonServiceToken:(nullable NSString *)token;

/**
 发送手机验证码
 
 @param phone Phone number
 @param type - 1: Register, 2: Reset, 3: Binding, 5: 登录错误次数达到限制
 @param countryCode 国际手机区号。海外手机号必填项，例如中国“86”
 @param completion Completion Handler
 */
- (void)getAuthCode:(nonnull NSString *)phone
               type:(nonnull NSString *)type
        countryCode:(nullable NSString *)countryCode
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 验证手机验证码
 
 @param authCode AuthCode
 @param phone Phone Number
 @param type - 1:注册 2:找回密码 3.绑定手机
 @param completion Completion Handler
 */
- (void)verifyAuthCode:(nonnull NSString *)authCode
                 phone:(nonnull NSString *)phone
                  type:(nonnull NSString *)type
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 发送激活邮件
 
 @param email 邮箱
 @param completion Completion Handler
 */
- (void)sendActivateEmail:(nonnull NSString *)email
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取全局域名
 
 @param services 类似@[@""]
 @param completion Completion Handler {NSArray}
 */
- (void)getGlobalDomains:(nullable NSArray *)services
              completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取ProductKey信息
 
 @param productKey Product Key
 @param secret Product Secret
 @param modelId ModelId
 @param completion Completion Handler
 */
- (void)getProductKeyInfoWithProductKey:(nonnull NSString *)productKey
                                 secret:(nonnull NSString *)secret
                                modelId:(nonnull NSString *)modelId
                             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 根据产品Key及bundleId获取商城信息
 
 @param bundleId app bundleid
 @param productKey ProductKey
 @param completion Completion Handler
 */
- (void)getBundleIdInfo:(nonnull NSString *)bundleId
             productKey:(nonnull NSString *)productKey
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取当前server UTC 时间，此接口为同步，请不要放到主线程，以免不必要的麻烦
 
 @param error 错误对象
 @return completion 返回数据
 */
- (NSData *)getUTCTimeSync:(NSError **)error;

/**
 获取支持 注册/登录 国家/地区 列表

 @param completion Completion Handler {countrys:[ch_CN,vi_VN]}
 */
- (void)getSupportCountryList:(CLXHttpTaskCompletionHandler)completion;

/**
 获取国际化语言

 @param locale 标准的locale eg:@"zh_CN"
 @param lastUpdateTime 最后获取的时间，utc时间戳:@"1564051154819", nil获取所有
 @param completion 返回数据
 */
- (void)getInternationalizationLocale:(nonnull NSString *)locale
                       lastUpdateTime:(nullable NSString *)lastUpdateTime
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 平台无维度属性获取，如获取人脸标签等
 
 @param keys 获取Keys  eg : @[@"faceTag", @"tzSelect"]
 @param completion 返回数据
 */
- (void)getServiceAttrWithKeys:(nullable NSArray *)keys
                    completion:(CLXHttpTaskCompletionHandler)completion;;

/**
 检查 APP，Camera 兼容性更新接口
 
 @param cameraId JSONArray camera id数组
 @param includeDisabled Include Disabled
 @param signFrom Sign From
 @param bundleId Bundle Id of App
 @param completion Completion Handler
 */
- (void)checkCompatibility:(nonnull NSArray *)cameraId
           includeDisabled:(BOOL)includeDisabled
                  signFrom:(nullable NSString *)signFrom
                  bundleId:(nonnull NSString *)bundleId
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 检查App更新老接口
 
 @param cameraId CameraId
 @param os OS
 @param appVersion Client App Version
 @param includeDisabled Include Disabled
 @param completion Completion Handler
 */
- (void)checkClient:(nonnull NSArray *)cameraId
                 os:(nonnull NSString *)os
         appversion:(nonnull NSString *)appVersion
    includeDisabled:(BOOL)includeDisabled
         completion:(CLXHttpTaskCompletionHandler)completion DEPRECATED_ATTRIBUTE;


/**
 发送ELK LogInfo
 
 @param type Type
 @param appId App Id
 @param multipartFile Multipart File
 @param fileName File存储名
 @param completion Completion Handler
 */
- (void)sendLogWithType:(nonnull NSString *)type
                  appId:(nonnull NSString *)appId
          multipartFile:(nonnull NSData *)multipartFile
               fileName:(nonnull NSString *)fileName
             completion:(CLXHttpTaskCompletionHandler)completion;


/**
 获取注册开关状态

 @param bundleId App的BundleId
 @param appVersion App的版本号
 @param completion Completion Handler
 */
- (void)getRegisterSwitchWithBundleId:(NSString *_Nullable)bundleId
                           appVersion:(NSString *)appVersion
                           completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXCommonServiceProtocol_h */
