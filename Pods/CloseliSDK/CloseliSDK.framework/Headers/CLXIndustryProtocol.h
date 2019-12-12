//
//  CLXIndustryProtocal.h
//  CLSDK


#ifndef CLXIndustryProtocal
#define CLXIndustryProtocal

#import "CLXHttpClientDefine.h"
#import "CLXSMBLoginInfo.h"
#import "CLXSMBStoreList.h"
#import "CLXSMBDeviceList.h"
#import "CLXDevice.h"
@protocol CLXIndustryProtocol <NSObject>


/**
 获取组织结构接口
 
 @param storeId 店铺的唯一标示
 @param token 用户登录token
 @param uid 登录用户ID
 @param channelType 可选 渠道类型： 全部：0或空     1:自有渠道  3：社会渠道
 @param storeName 店铺名称，可选，模糊匹配
 @param isHasVirtualUser 可选 是否需要虚拟用户的信息  true:需要虚拟用户的信息（店铺首页展示店铺树需要传true），false:不与需要虚拟用户的信息（营业厅管理店铺搜索传false），默认false
 @param completion CLXSMBStoreInfo
 */
- (void)industryGetOrganizationListWithStoreId:(nonnull NSString *)storeId
                                      token:(nonnull NSString *)token
                                        uid:(nonnull NSString *)uid
                                channelType:(nullable NSString *)channelType
                                  storeName:(nullable NSString *)storeName
                           isHasVirtualUser:(nullable NSString *)isHasVirtualUser
                                 completion:(CLXHttpTaskCompletionHandler)completion;

/**
 国标获取某个店铺下的设备树列表接口
 
 @param storeId required，店铺的唯一标示（注明：第一次查询的是采用登录后返回的storeId）
 @param token   required，用户的token
 @param uid     required，用户的id
 @param entryId     接入ID storeId和entryId不能同时为null
 @param channelParentId     是GB接入设备中的channelId, 获取设备树下级数据(获取某个节点的子设备时，取当前节点的channelId或者id 作为channelParentId)
 @param callbackModel required，返回集合中元素的类型，可以传CLXSMBDeviceList或其子类。例如：[CLXSMBDeviceList class]
 @param completion optional，Completion Handler: {CLXSMBDeviceList类或子类的集合}
 */
- (void)industryGetDeviceListWithStoreId:(nonnull NSString *)storeId
                                token:(nonnull NSString *)token
                                  uid:(nonnull NSString *)uid
                              entryId:(nullable NSString *)entryId
                      channelParentId:(nullable NSString *)channelParentId
                        callbackModel:(nonnull Class<CLXSMBDeviceList>)callbackModel
                           completion:(CLXHttpTaskCompletionHandler)completion;


-(void)industrySetMediaControlWithDeviceId:(nonnull NSString *)deviceId
                                      type:(nonnull NSString *)type
                                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 行业获取关注分组列表

 @param token required，用户的token
 @param userId required，用户的id
 */
- (void)industryGetGroupListWithToken:(nonnull NSString *)token
                            userId:(nonnull NSString *)userId
                        completion:(CLXHttpTaskCompletionHandler)completion;

/**
 行业获取关注设备列表
 @param groupId 分组ID
 */
- (void)industryGetStarDeviceList:(nonnull NSString *)groupId
                         token:(nonnull NSString *)token
                        userId:(nonnull NSString *)userId
                    completion:(CLXHttpTaskCompletionHandler)completion;

/**
 行业添加关注分组
 @param groupName 分组名  分组名为nil 会创建默认分组
 */

- (void)industryAddGroupWithGroupName:(nullable NSString *)groupName
                                token:(nonnull NSString *)token
                               userId:(nonnull NSString *)userId
                           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 行业取消关注分组
 @param groupId 分组Id
 */
- (void)industryDelGroupWithGroupId:(nonnull NSString *)groupId
                           token:(nonnull NSString *)token
                          userId:(nonnull NSString *)userId
                      completion:(CLXHttpTaskCompletionHandler)completion;

/**
 行业添加关注
 @param groupId 目标分组ID
 @param deviceId 设备ID
 */
- (void)industryAddStarWithGroupId:(nonnull NSString *)groupId
                       deviceId:(nonnull NSString *)deviceId
                          token:(nonnull NSString *)token
                         userId:(nonnull NSString *)userId
                        storeId:(nonnull NSString *)storeId
                     completion:(CLXHttpTaskCompletionHandler)completion;
/**
 行业取消关注
 @param groupId 目标分组ID
 @param deviceId 设备ID
 */
- (void)industryDelStarWithGroupId:(nonnull NSString *)groupId
                          deviceId:(nonnull NSString *)deviceId
                             token:(nonnull NSString *)token
                            userId:(nonnull NSString *)userId
                        completion:(CLXHttpTaskCompletionHandler)completion;


/**
 根据id获取设备列表信息
 
 @param deviceIds id数组
 @param token 用户token
 */
- (void)industryGetDeviceList:(nonnull NSArray *)deviceIds
                     token:(nonnull NSString *)token
                    userId:(nonnull NSString *)userId
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
修改用户密码

@param sessionid required，用户的sessionid
@param newPassword required，用户新密码
@param oldPassword required，用户原始密码
@param completion Completion Handler: {}
*/
- (void)industryChangePasswordWithSessionID:(nonnull NSString *)sessionid
                           newPassword:(nonnull NSString *)newPassword
                           oldPassword:(nonnull NSString *)oldPassword
                                 token:(nonnull NSString *)token
                                   uid:(NSString *)uid
                            completion:(CLXHttpTaskCompletionHandler)completion;

@end
#endif /* CLXIndustryProtocal */
