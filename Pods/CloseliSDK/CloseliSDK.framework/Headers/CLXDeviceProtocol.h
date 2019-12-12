//
//  CLXDeviceProtocol.h

#ifndef CLXDeviceProtocol_h
#define CLXDeviceProtocol_h

#import "CLXHttpClientDefine.h"
#import "CLXDevice.h"
#import "CLXDeviceUpdateInfo.h"
#import "CLXGateWayInfo.h"

@class CLCameraDevice;
/**
 @brief 设备相关API，跟设备相关的一些接口，例如获取设备列表、设备分享、设备更新信息查询等
 */
@protocol CLXDeviceProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configDeviceToken:(nullable NSString *)token;

#pragma mark - Bind
/**
 绑定Account和Mac
 
 @param deviceId 设备ID
 @param account 账户
 @param appShortPK QRCode_Key
 @param appShortToken 用户short token，登录返回
 @param completion Completion Handler
 */
- (void)bindWiredCameraInfo:(nonnull NSString *)deviceId
                    account:(nonnull NSString *)account
                 appShortPK:(nonnull NSString *)appShortPK
              appShortToken:(nonnull NSString *)appShortToken
                     locale:(nullable NSString *)locale
                 completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 设置App信息,给app使用
 
 @param content app上报的信息
 @param completion Completion Handel {id : dic}
 */
- (void)getCheckIdWithContent:(nullable NSString *)content
                   completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - Data
/**
 获取分享Url
 
 @param email Account，是否分享给指定账户
 @param serverUrl Server Url，可不传
 @param fileId 文件ID
 @param passCode passCode，是否设置密码
 @param validation 有效期
 @param completion Completion Handler
 */
- (void)shareFileWithEmail:(nullable NSString *)email
                 serverUrl:(nullable NSString *)serverUrl
                    fileId:(nonnull NSString *)fileId
                  passCode:(nullable NSString *)passCode
                validation:(nullable NSString *)validation
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 重命名图片, 定时截图功能相关文件
 
 @param fileId 文件ID
 @param deviceId 设备ID
 @param name New Image Name
 @param downLoadServer downLoadServer,可不传
 @param completion Completion Handler
 */
- (void)renameImage:(nonnull NSString *)fileId
           deviceId:(nonnull NSString *)deviceId
               name:(nonnull NSString *)name
     downLoadServer:(nullable NSString *)downLoadServer
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除图片，定时截图功能相关文件
 
 @param fileId 文件ID
 @param deviceId 设备ID
 @param downLoadServer downLoadServer,可不传
 @param completion Completion Handler
 */
- (void)deleteImage:(nonnull NSString *)fileId
           deviceId:(nonnull NSString *)deviceId
     downLoadServer:(nullable NSString *)downLoadServer
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 域名列表
 
 @param deviceId 设备ID
 @param token token
 @param completion Completion Handler
 */
- (void)getRegionList:(nonnull NSString *)deviceId
                token:(nullable NSString *)token
           completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - Info

/**
 @remark 获取设备的错过告警数

 @param deviceId 设备ID
 @param completion Completion Handler
 */
- (void)getMissedEventCount:(nonnull NSString *)deviceId
                 completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取xmpp Server地址

 @param completion Completion Handler
 */
- (void)getXmppServerAddress:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取老p2p相关信息

 @param completion Completion Handler
 */
- (void)getPrivsInfo:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取relay通道信息

 @param deviceId 设备ID
 @param deviceType 设备类型
 @param region region
 @param channelName 通道名字 720p、qvga
 @param channelNo 通道号
 @param completion Completion Handler
 */
- (void)getAssignRelayIpInfo:(nonnull NSString *)deviceId
                  deviceType:(nullable NSString *)deviceType
                      region:(nullable NSString *)region
                 channelName:(nullable NSString *)channelName
                   channelNo:(nullable NSString *)channelNo
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取设备所有Relay流信息

 @param shareId 分享ID
 @param deviceId 设备ID
 @param region region
 @param channelName 通道名字 720p、qvga
 @param channelNo 通道号
 @param completion Completion Handler
 */
- (void)getRelayIPListInfo:(nullable NSString *)shareId
                  deviceId:(nonnull NSString *)deviceId
                    region:(nullable NSString *)region
               channelName:(nullable NSString *)channelName
                 channelNo:(nullable NSString *)channelNo
                completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - Option
/**
 获取设备列表 (返回老的CLCameraDevice)， 为了数据兼容暂时提供
 
 @param deviceId deviceId - Optional, if specified only return single device information
 @param did cloudid - Optional
 @param completion Completion Handler
 */
- (void)getDeviceList:(nullable NSString *)deviceId
                  did:(nullable NSString *)did
           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取设备列表 (返回老的CLCameraDevice)
 settingPathArray 与 supportPathArray 如果使用自定义设置，则必须同时设置。
 如果不设置，传nil使用默认的配置项，见 CLXDeviceSettingDefine 中 GENERAL_SUPPORTVALUES、GENERAL_SETTINGVALUES
 
 @param settingPathArray 设备设置项 已设置的值 相关， 通过settingValue属性返回
 @param supportPathArray 设备设置项 ifSupport 相关， 通过supportValue属性返回
 @param settingCodes 设备配置项 新的配置方案 相关 通过settingExtends属性返回 设置参数eg:SETTINGCODE_BITRATE
 @param completion Completion Handler
 */
- (void)getDeviceList:(nullable NSArray *)settingPathArray
         supportPaths:(nullable NSArray *)supportPathArray
         settingCodes:(nullable NSArray *)settingCodes
           completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除设备

 @param deviceId 设备ID
 @param did 设备did
 @param channelNo 子设备编号 删除主设备可传nil
 @param completion Completion Handler
 */
- (void)unregisterDevice:(nonnull NSString *)deviceId
                     did:(nullable NSString *)did
               channelNo:(nullable NSString *)channelNo
              completion:(CLXHttpTaskCompletionHandler)completion;

/**
 设备批量分享

 @param deviceId 设备ID
 @param shareInfos [
 {
 "mobile": "1909888",
 "privView": "1"
 },
 {
 "mobile": "1909889",
 "privView": "2"
 },
 {
 "mobile": "1909887",
 "privView": "3"
 }]
 其中privView表示回放、直播权限，1表示直播，2表示回放，3表示直播回放都有
 @param completion Completion Handler
 */
- (void)shareDeviceByBatch:(nonnull NSString *)deviceId
                shareInfos:(nonnull NSArray *)shareInfos
                completion:(CLXHttpTaskCompletionHandler)completion;
/**
 设备分享

 @param deviceId 设备ID
 @param userEmail 要分享的目标用户名
 @param completion Completion Handler
 */
- (void)shareDevice:(nonnull NSString *)deviceId
          userEmail:(nonnull NSString *)userEmail
         completion:(CLXHttpTaskCompletionHandler)completion;
/**
 设备取消分享

 @param deviceId 设备ID
 @param shareId 分享ID
 @param cancelType 1:取消公开分享; 2:取消不指定用户的私密分享; 3:包含1和2; 4:取消指定用户的私密分享; 5: 被分享者取消分享; 6:取消设备所有分享
 @param completion completion Completion Handler
 */
- (void)cancelDeviceShare:(nonnull NSString *)deviceId
                  shareId:(nonnull NSString *)shareId
               cancelType:(nonnull NSString *)cancelType
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取分享用户列表
 
 @param deviceId 设备ID
 @param completion Completion Handler
 */
- (void)getPrivateShareList:(nonnull NSString *)deviceId
                 completion:(CLXHttpTaskCompletionHandler)completion;

/**
 更新分组信息

 @param groupName 分组名称(传入就会更新名称)
 @param groupId 分组id（传入表示更新，不传入表示新增）
 @param details json串，表示分组下面的摄像头排序信息，全量保存或更新（传入就更新，不传入不变。详见下面说明）
 details的内容，deviceId表示设备mac地址，orders表示在分组中的顺序
 [{
 "deviceId": "xxxxS_aaaaaa1",
 "orders": 1
 },
 {
 "deviceId": "xxxxS_aaaaaa2",
 "orders": 2
 },
 {
 "deviceId": "xxxxS_aaaaaa3",
 "orders": 3
 }]
 @param completion Completion Handler
 */
- (void)updateGroupWithGroupName:(nonnull NSString *)groupName
                         groupId:(nullable NSString *)groupId
                         details:(nullable NSArray *)details
                      completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取分组列表

 @param completion Completion Handler @see CLXHttpTaskCompletionHandler
 */
- (void)getGroupList:(CLXHttpTaskCompletionHandler)completion;

/**
 删除分组信息

 @param groupId 分组ID
 @param completion Completion Handler
 */
- (void)deleteGroupWithGroupId:(nonnull NSString *)groupId
                    completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取分享token

 @param shareId 分享ID
 @param completion Completion Handler
 */
- (void)getSharedCameraTokenWithShareId:(nonnull NSString *)shareId
                             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取分享者手机号

 @param shareId 分享ID
 @param completion Completion {id : NSString}
 */
- (void)getShareInfoWithShareId:(nonnull NSString *)shareId
                     completion:(CLXHttpTaskCompletionHandler)completion;
#pragma mark - Update
/**
 激活摄像头更新，更新camera的status字段，该字段用于控制某个产品版本号低于特定版本的设备来服务器检测更新的时候是否有权限检测到更新， 0 没有权限， 1 有权限
 
 @param status 状态：0或1
 @param cameraId 设备ID
 @param accessToken accessToken
 @param completion Completion Handler
 */
- (void)updateCameraStatus:(NSInteger)status
                  cameraId:(nonnull NSString *)cameraId
               accessToken:(nonnull NSString *)accessToken
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 检测设备更新信息接口
 
 @param deviceIds 设备ID Array @[@"1", @"2"]
 @param serviceTypes 需要检测的服务, 格式数组拼接字符串，例如@"[1,2,3,4]"
 @param callbackModel 基础类[CLXDeviceUpdateInfo class]，也可以继承扩展
 @param completion Completion Handle
 */
- (void)getDevicesUpdateInfo:(nonnull NSArray <NSString *>*)deviceIds
                serviceTypes:(nonnull NSString *)serviceTypes
               callbackModel:(nonnull Class<CLXDeviceUpdateInfo>)callbackModel
                  completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - IOT
/**
 添加门锁设备

 @param mac mac地址
 @param deviceTypeCode 智能设备类型编码
 @param imei 设备序列号
 @param password 密码
 @param modelId 设备信息
 @param name 设备名字
 @param remark 备注信息
 @param deviceUnitType 设备型号
 1、温湿度传感器 2、水浸传感器 3、门窗传感器 4、人体传感器
 5、烟雾传感器 6、智能灯泡 7、无线开关 8、插座
 9、一氧化碳传感器 10、可燃气传感器 11、SOS传感器 12、门锁传感器
 13、遥控器 1000、网关 1001、摄像头（IPC）
 
 @param deviceSerial 序列号
 @param deviceVersion 硬件版本号
 @param deviceFirmwareVersion 固件版本号
 @param nbIotVersion NB-IOT版本
 @param bluetoothVersion 蓝牙版本号
 @param fingerprintVersion 指纹版本号
 @param completion completion {id : dic}
 */
- (void)addIOTDoorLockWithDeviceMac:(nonnull NSString *)mac
                     deviceTypeCode:(NSInteger)deviceTypeCode
                               imei:(nonnull NSString *)imei
                           password:(nonnull NSString *)password
                            modelId:(nonnull NSString *)modelId
                               name:(nonnull NSString *)name
                             remark:(nullable NSString *)remark
                     deviceUnitType:(nullable NSString *)deviceUnitType
                       deviceSerial:(nullable NSString *)deviceSerial
                      deviceVersion:(nullable NSString *)deviceVersion
              deviceFirmwareVersion:(nullable NSString *)deviceFirmwareVersion
                       nbIotVersion:(nullable NSString *)nbIotVersion
                   bluetoothVersion:(nullable NSString *)bluetoothVersion
                 fingerprintVersion:(nullable NSString *)fingerprintVersion
                         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取门锁详情

 @param mac mac地址
 @param deviceTypeCode 智能设备类型编码
 @param completion completion {id : dic}
 */
- (void)getDoorLockDetailWithDeviceMac:(nonnull NSString *)mac
                        deviceTypeCode:(NSInteger)deviceTypeCode
                            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除门锁

 @param mac mac地址
 @param deviceTypeCode 智能设备类型编码
 @param completion completion {id : dic}
 */
- (void)deleteIOTDoorLockWithDeviceMac:(nonnull NSString *)mac
                        deviceTypeCode:(NSInteger)deviceTypeCode
                            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取设备固件详情

 @param mac mac地址
 @param deviceTypeCode 智能设备类型编码
 @param completion completion {id : dic}
 */
- (void)getFirmwareDetailWithMac:(nonnull NSString *)mac
                  deviceTypeCode:(NSInteger)deviceTypeCode
                      completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取网关服务信息（网关独有）

 @param gwMac mac地址
 @param protoType 协议类型，1、2 （默认为2）
 @param completion completion {id : dic}
 */
- (void)getGatewayServerInfoWithMac:(nonnull NSString *)gwMac
                          protoType:(NSInteger)protoType
                         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 添加门锁密码

 @param mac mac地址
 @param pwdType 1、密码 2、指纹
 @param pwdUid 角色ID
 @param name 角色名
 @param expireType 1、永久 2、一次性 3、有效期
 @param startTime 开始时间
 @param expiredTime 失效时间
 @param completion completion {id : dic}
 */
- (void)addDoorLockPwdWithMac:(nonnull NSString *)mac
                      pwdType:(nonnull NSString *)pwdType
                       pwdUid:(nonnull NSString *)pwdUid
                         name:(nonnull NSString *)name
                   expireType:(nonnull NSString *)expireType
                    startTime:(nullable NSString *)startTime
                  expiredTime:(nullable NSString *)expiredTime
                   completion:(CLXHttpTaskCompletionHandler)completion;
/**
 添加门锁临时密码

 @param mac mac地址
 @param pwdUid 角色ID
 @param pwd pwd
 @param startTime 开始时间
 @param expireTime 过期时间
 @param completion Completion Handel {id : dic}
 */
- (void)addDoorLockTempPwdWithMac:(nonnull NSString *)mac
                           pwdUid:(nonnull NSString *)pwdUid
                              pwd:(nonnull NSString *)pwd
                        startTime:(nullable NSString *)startTime
                       expireTime:(nullable NSString *)expireTime
                       completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取门锁Secert

 @param mac mac地址
 @param completion Completion Handel {id : dic}
 */
- (void)getDoorLockSecertKeyWithMac:(nonnull NSString *)mac
                         completion:(CLXHttpTaskCompletionHandler)completion;
/**
 删除门锁密码

 @param pwdKey 密码keyid
 @param completion Completion Handel {id : dic}
 */
- (void)deleteDoorLockPwdWithPwdKey:(nonnull NSString *)pwdKey
                         completion:(CLXHttpTaskCompletionHandler)completion;
/**
 获取门锁密码列表

 @param mac mac地址
 @param pwdType 1、密码 2、指纹
 @param completion Completion Handel {id : dic}
 */
- (void)getDoorLockPwdListWithMac:(nonnull NSString *)mac
                          pwdType:(nonnull NSString *)pwdType
                       completion:(CLXHttpTaskCompletionHandler)completion;
/**
 重命名门锁密码

 @param pwdKey 密码keyid
 @param name 新名字
 @param completion Completion Handel {id : dic}
 */
- (void)renameDoorLockPwdWithPwdKey:(nonnull NSString *)pwdKey
                               name:(nonnull NSString *)name
                         completion:(CLXHttpTaskCompletionHandler)completion;
/**
 获取网关列表

 @param account 账户
 @param callbackModel Class<CLXGateWayInfo>
 @param completion completion {id : NSArray<callbackModel>}
 */
- (void)getGatewayListWithAccount:(nonnull NSString *)account
                    callbackModel:(nonnull Class<CLXGateWayInfo>)callbackModel
                       completion:(CLXHttpTaskCompletionHandler)completion;
/**
 查询智能（含网关）设备列表接口
 
 @param completion Completion Handel {id : dic}
 */
- (void)getIOTDeviceListCompletion:(CLXHttpTaskCompletionHandler)completion;
/**
 智能设备（含报警设备）添加接口
 
 @param deviceTypeCode 设备类型
 @param gwMac 网关mac地址
 @param completion Completion Handel {id : dic}
 */
- (void)addIOTSmartDeviceWithTypeCode:(nonnull NSNumber *)deviceTypeCode
                                gwMac:(nonnull NSString *)gwMac
                           completion:(CLXHttpTaskCompletionHandler)completion;
/**
 智能设备删、网关除接口
 
 @param deviceType 类型:0 智能设备， 1 网关
 @param macAddress 设备或网关mac地址
 @param completion Completion Handel {id : dic}
 */
- (void)deleteIOTDeviceWithDeviceType:(nonnull NSNumber *)deviceType
                           macAddress:(nonnull NSString *)macAddress
                           completion:(CLXHttpTaskCompletionHandler)completion;
/**
 查询智能（含报警）设备列表接口
 
 @param userMail 用户账号
 @param macAddress 设备或网关mac地址
 @param completion Completion Handel {id : dic}
 */
- (void)getIOTSmartDeviceListWithUserMail:(nonnull NSString *)userMail
                               macAddress:(nonnull NSString *)macAddress
                               completion:(CLXHttpTaskCompletionHandler)completion;
/**
 智能设备的布撤防
 
 @param deviceType 类型:0 智能设备， 1 网关
 @param macAddress 设备或网关mac地址
 @param defenceStatus 布撤防开关：0 布防 ，1 撤防；布防可以发消息，撤防不可以发消息
 @param completion Completion Handel {id : dic}
 */
- (void)setIOTDeviceDefenceWithDeviceType:(nonnull NSNumber *)deviceType
                               macAddress:(nonnull NSString *)macAddress
                            defenceStatus:(nonnull NSNumber *)defenceStatus
                               completion:(CLXHttpTaskCompletionHandler)completion;
/**
 更新网关类设备

 @param mac mac地址
 @param type 0 智能设备 1 网关
 @param name 设备或者网关名称
 @param status 0 关闭 1 开启
 @param completion Completion Handel {id : dic}
 */
- (void)updateGatewayDeviceWithMac:(nonnull NSString *)mac
                              type:(nonnull NSString *)type
                              name:(nullable NSString *)name
                            status:(nullable NSString *)status
                        completion:(CLXHttpTaskCompletionHandler)completion;
/**
 绑定账户与mac

 @param mac mac地址
 @param appShortPK app的shortpk，如：g21 有必要时填写
 @param type 用于区分门锁和网关，1：代表门锁，网关不用传此字段
 @param completion Completion Handel {id : dic}
 */
- (void)bindWiredGatewayWithMac:(nonnull NSString *)mac
                     appShortPK:(nullable NSString *)appShortPK
                           type:(nullable NSString *)type
                     completion:(CLXHttpTaskCompletionHandler)completion;

/**
 唤醒低功耗设备

 @param deviceid 设备ID
 @param completion Completion Handel {id : dic}
 */
- (void)wakeUpDevice:(nonnull NSString *)deviceid
          completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXDeviceProtocol_h */
