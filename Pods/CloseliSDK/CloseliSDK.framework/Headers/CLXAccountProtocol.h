//
//  CLXAccountProtocol.h

#ifndef CLXAccountProtocol_h
#define CLXAccountProtocol_h

#import "CLCloudUserInfo.h"
#import "CLXAccountInfo.h"
#import "CLXHttpClientDefine.h"
#import "CLXUserLoginLog.h"

/*!
 @brief 账户相关API接口，包括登录，注册，修改密码等
 */
@protocol CLXAccountProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.

 @param token Token---用户token or 分享token
 */
- (void)configAccountToken:(nullable NSString *)token;

/**
 通过账户及密码登录
 
 @param account account
 @param password password
 @param loginType 登陆类型，无特殊要求默认传nil
 @param countryCode 国际手机区号。海外手机号登录必填项，例如中国“86”
 @param callbackModel 返回数据model class，可以传基类[CLXAccountInfo class], 亦可继承 CLXAccountInfo（NSObject）增加相应属性
 @param completion Completion Handler, {CLXAccountInfo}
 */
- (void)loginWithAccount:(nonnull NSString *)account
                password:(nonnull NSString *)password
               loginType:(nullable NSString *)loginType
             countryCode:(nullable NSString *)countryCode
           callbackModel:(nonnull Class<CLXAccountInfo>)callbackModel
              completion:(CLXHttpTaskCompletionHandler)completion;

/**
 通过Token登录帐号
 
 @param token token
 @param thirdToken 如果有平台对接thirdToken，可传此参数绑定
 @param callbackModel 返回数据model class，可以传基类[CLXAccountInfo class], 亦可继承 CLXAccountInfo（NSObject）增加相应属性
 @param completion Completion Handler, {CLXAccountInfo}
 */
- (void)loginWithToken:(nonnull NSString *)token
            thirdToken:(nullable NSString *)thirdToken
         callbackModel:(nonnull Class<CLXAccountInfo>)callbackModel
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 手机注册账号
 
 @param phoneNumber Phone Number
 @param password Password
 @param authCode 验证码
 @param countryCode 国际手机区号。海外手机号注册必填项，例如中国“86”
 @param callbackModel 返回数据model class，可以传基类[CLXAccountInfo class], 亦可继承 CLXAccountInfo（NSObject）增加相应属性
 @param completion Completion Handler, {CLXAccountInfo}
 */
- (void)registerWithPhoneNumber:(nonnull NSString *)phoneNumber
                       password:(nonnull NSString *)password
                       authCode:(nonnull NSString *)authCode
                    countryCode:(nonnull NSString *)countryCode
                  callbackModel:(nonnull Class<CLXAccountInfo>)callbackModel
                     completion:(CLXHttpTaskCompletionHandler)completion;

/**
 邮箱注册账号
 
 @param eMail eMail
 @param password Password
 @param callbackModel 返回数据model class，可以传基类[CLXAccountInfo class], 亦可继承 CLXAccountInfo（NSObject）增加相应属性
 @param completion Completion Handler, {CLXAccountInfo}
 */
- (void)registerWithEmail:(nonnull NSString *)eMail
              andPassword:(nonnull NSString *)password
            callbackModel:(nonnull Class<CLXAccountInfo>)callbackModel
               completion:(CLXHttpTaskCompletionHandler)completion;


/**
 通过第三方facebook token登录
 
 @param token Facebook Token
 @param openId Facebook OpenId
 @param callbackModel 返回数据model class，可以传基类[CLXAccountInfo class], 亦可继承 CLXAccountInfo（NSObject）增加相应属性
 @param completion Completion Handler, {CLXAccountInfo}
 */
- (void)loginWithFBToken:(nonnull NSString *)token
                fbOpenId:(nonnull NSString *)openId
           callbackModel:(nonnull Class<CLXAccountInfo>)callbackModel
              completion:(CLXHttpTaskCompletionHandler)completion;

/**
 邮箱重置密码
 
 @param email Email Address
 @param password Password
 @param checkCode CheckCode
 @param completion Completion Handler
 */
- (void)resetPasswordByEmail:(nonnull NSString *)email
                    password:(nonnull NSString *)password
                   checkCode:(nonnull NSString *)checkCode
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 手机重置密码
 
 @param mobile 手机号码，海外需要countryCode
 @param password 密码
 @param checkCode 验证码
 @param countryCode 国际手机区号。海外手机号必填项，例如中国“86”
 @param completion Completion Handler
 */
- (void)resetPasswordByMobile:(nonnull NSString *)mobile
               password:(nonnull NSString *)password
              checkCode:(nonnull NSString *)checkCode
            countryCode:(nullable NSString *)countryCode
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 绑定邮箱/手机，如果已经激活则返回错误
 
 @param email 邮箱账号，如果用邮箱手机相关传nil
 @param mobile 手机账号
 @param checkCode 手机验证码
 @param completion Completion Handler
 */
- (void)bindMobileWithEmail:(nullable NSString *)email
               mobile:(nullable NSString *)mobile
            checkCode:(nullable NSString *)checkCode
           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 设置Vip类型
 
 @param type 1:设置成vip用户
 @param completion Completion Handler
 */
- (void)setVipType:(nonnull NSNumber *)type
        completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除帐号
 
 @param email Account
 @param password Password
 @param completion Completion Handler
 */
- (void)removeAccountWithEmail:(nonnull NSString *)email
                      password:(nonnull NSString *)password
                    completion:(CLXHttpTaskCompletionHandler)completion;

/**
 忘记密码
 
 @param email Account
 @param completion Completion Handler
 */
- (void)forgotPwdWithEmail:(nonnull NSString *)email
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 修改密码
 
 @param email Account
 @param resourceId ResourceId
 @param newPassword NewPassword
 @param oldPassword OldPassword
 @param countryCode 国际手机区号。海外手机号必填项，例如中国“86”
 @param completion Completion Handler
 */
- (void)updatePwdWithEmail:(nonnull NSString *)email
                resourceId:(nonnull NSString *)resourceId
               newPassword:(nonnull NSString *)newPassword
               oldPassword:(nonnull NSString *)oldPassword
               countryCode:(nullable NSString *)countryCode
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 更改用户名
 
 @param password Password
 @param newEmail Email Address
 @param completion Completion Handler
 */
- (void)changeEmailWithPassword:(nonnull NSString *)password
                       newEmail:(nonnull NSString *)newEmail
                     completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取用户最近一次的登陆情况

 @param pageSize 分页大小
 @param pageNum 分页位置
 @param callbackModel 返回数据model class，可以传基类[CLXDeviceLoginLog class], 亦可继承 CLXDeviceLoginLog（NSObject）增加相应属性
 @param completion Completion Handler {model CLXDeviceLoginLog}
 */
- (void)getLoginDetailsWithPageSize:(nullable NSString *)pageSize
                      pageNum:(nullable NSString *)pageNum
                callbackModel:(nonnull Class<CLXUserLoginLog>)callbackModel
                   completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取用户在哪些手机设备上何时登陆过，保留7天的登录记录

 @param pageSize 分页大小
 @param pageNum 分页位置
 @param callbackModel 返回数据model class，可以传基类[CLXUserLoginLog clasa], 亦可继承 CLXUserLoginLog（NSObject）增加相应属性
 @param completion Completion Handler {model CLXUserLoginLog}
 */
- (void)getDeviceLoginDetailsWithPageSize:(nullable NSString *)pageSize
                        pageNum:(nullable NSString *)pageNum
                  callbackModel:(nonnull Class<CLXUserLoginLog>)callbackModel
                     completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXAccountProtocol_h */
