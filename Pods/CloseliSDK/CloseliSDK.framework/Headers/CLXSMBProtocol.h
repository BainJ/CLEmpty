//
//  CLXSMBProtocol.h

#import <Foundation/Foundation.h>
#import "CLXHttpClientDefine.h"
#import "CLXSMBLoginInfo.h"
#import "CLXSMBStoreList.h"
#import "CLXSMBDeviceList.h"
#import "CLXDevice.h"

@protocol CLXSMBProtocol <NSObject>
/**
 登录
 
 @param username required，用户名
 @param password required，密码
 @param callbackModel required，返回数据类型，可以传CLXSMBLoginInfo或其子类。例如：[CLXSMBLoginInfo class]
 @param completion optional，Completion Handler: {CLXSMBLoginInfo类或子类}
 */
- (void)smbLoginWithUsername:(nonnull NSString *)username
                    password:(nonnull NSString *)password
                     clentId:(nonnull NSString *)clentId
                   timeStamp:(nullable NSString *)timeStamp
               callbackModel:(nonnull Class<CLXSMBLoginInfo>)callbackModel
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 退出登录
 
 @param username required，用户名
 @param sessionid required，用户的sessionid
 @param completion Completion Handler: {CLXSMBLoginInfo类或子类}
 */
- (void)smbLogoutWithUsername:(nonnull NSString *)username
                    sessionid:(nonnull NSString *)sessionid
                   completion:(CLXHttpTaskCompletionHandler)completion;

/**
 忘记密码获取验证码
 
 @param username required，用户名
 @param completion Completion Handler: {}
 */
- (void)smbForgetPasswordWithUsername:(nonnull NSString *)username
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 忘记密码后重设密码
 
 @param username required，用户名
 @param password required，密码
 @param verifyCode required，验证码，有效期为30分钟
 @param completion Completion Handler: {}
 */
- (void)smbResetPasswordWithUsername:(nonnull NSString *)username
                            password:(nonnull NSString *)password
                          verifyCode:(nonnull NSString *)verifyCode
                          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 修改用户密码
 
 @param sessionid required，用户的sessionid
 @param newPassword required，用户新密码
 @param oldPassword required，用户原始密码
 @param completion Completion Handler: {}
 */
- (void)smbChangePasswordWithSessionID:(nonnull NSString *)sessionid
                           newPassword:(nonnull NSString *)newPassword
                           oldPassword:(nonnull NSString *)oldPassword
                            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取店铺树（列表）
 
 @param sessionid required，用户的sessionid
 @param storeId required，店铺的唯一标示（注明：第一次查询的是采用登录后返回的storeId）
 @param callbackModel required，返回集合中元素的类型，可以传CLXSMBStoreList或其子类。例如：[CLXSMBStoreList class]
 @param completion optional，Completion Handler: {CLXSMBStoreList类或子类的集合}
 */
- (void)smbGetStoreListWithSessionID:(nonnull NSString *)sessionid
                             storeId:(nonnull NSString *)storeId
                             clentId:(nonnull NSString *)clentId
                       callbackModel:(nonnull Class<CLXSMBStoreList>)callbackModel
                          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 根据店铺名查询当前店铺下所有符合条件的店铺信息
 
 @param sessionid required，用户的sessionid
 @param userId required，登陆用户的ID
 @param storeName optional，店铺名称，可选，模糊匹配
 @param callbackModel required，返回集合中元素的类型，可以传CLXSMBStoreList或其子类。例如：[CLXSMBStoreList class]
 @param completion optional，Completion Handler: {CLXSMBStoreList类或子类的集合}
 */
- (void)smbGetQueryStoreWithSessionID:(nonnull NSString *)sessionid
                               userId:(nonnull NSString *)userId
                            storeName:(nullable NSString *)storeName
                        callbackModel:(nonnull Class<CLXSMBStoreList>)callbackModel
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取店铺下面的设备列表
 
 @param sessionid required，用户的sessionid
 @param storeId required，店铺的唯一标示
 @param callbackModel required，返回集合中元素的类型，可以传CLXSMBDeviceList或其子类。例如：[CLXSMBDeviceList class]
 @param completion optional，Completion Handler: {CLXSMBDeviceList类或子类的集合}
 */
- (void)smbGetDeviceListWithSessionID:(nonnull NSString *)sessionid
                              storeId:(nonnull NSString *)storeId
                        callbackModel:(nonnull Class<CLXSMBDeviceList>)callbackModel
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取用户所有关注的设备列表
 
 @param sessionid required，用户的sessionid
 @param callbackModel required，返回集合中元素的类型，可以传CLXSMBDeviceList或其子类。例如：[CLXSMBDeviceList class]
 @param completion optional，Completion Handler: {CLXSMBDeviceList类或子类的集合}
 */
- (void)smbGetFollowListWithSessionID:(nonnull NSString *)sessionid
                        callbackModel:(nonnull Class<CLXSMBDeviceList>)callbackModel
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 添加关注摄像头
 
 @param sessionid required，用户的sessionid
 @param cameraId required，关注的摄像头 ID
 @param storeId required，摄像头所属店铺 ID
 @param completion optional，Completion Handler: {}
 */
- (void)smbAddFollowWithSessionID:(nonnull NSString *)sessionid
                         cameraId:(nonnull NSString *)cameraId
                          storeId:(nonnull NSString *)storeId
                       completion:(CLXHttpTaskCompletionHandler)completion;

/**
 取消关注摄像头
 
 @param sessionid required，用户的sessionid
 @param cameraId required，取消关注的摄像头 ID
 @param completion optional，Completion Handler: {}
 */
- (void)smbRemoveFollowWithSessionID:(nonnull NSString *)sessionid
                            cameraId:(nonnull NSString *)cameraId
                          completion:(CLXHttpTaskCompletionHandler)completion;


/**
 @remark 获取二级设备列表（目前NVR使用）

 @param token token
 @param deviceId deviceId
 @param completion optional，Completion Handler: {CLCameraDevice类或子类的集合}
 */
- (void)smbGetDeviceSecondListWithToken:(nonnull NSString *)token
                               deviceId:(nonnull NSString *)deviceId
                             completion:(CLXHttpTaskCompletionHandler)completion;

@end
