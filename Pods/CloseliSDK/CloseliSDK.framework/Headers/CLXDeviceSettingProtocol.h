//
//  CLXDeviceSettingProtocol.h

#ifndef CLXDeviceSettingProtocol_h
#define CLXDeviceSettingProtocol_h

#import "CLXHttpClientDefine.h"
#import "CLCameraDevice.h"
#import "CLSDKHeader.h"
#import "CLXDeviceSetting.h"
#import "CLXDeviceSettingDefine.h"
#import "CLXDeviceSetingTextDefine.h"

/**
 @brief 设备设置相关API，功能列表，例如声音检测、运动检测开关，设备名字修改、静音开关等
 */
@protocol CLXDeviceSettingProtocol <NSObject>
/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configDeviceSettingToken:(nullable NSString *)token;

/**
 reboot

 @param deviceId 设备ID
 @param completion Completion Handle
 */
- (void)rebootDevice:(nonnull NSString *)deviceId
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取设备配置信息，此接口扩展性强，接入使用此接口

 @param deviceId 设备ID
 @param channelNo 子设备通道号
 @param cloudDid 设备Cloud did，@see CLXDevice
 @param callbackModel 基础传参[CLXDeviceSetting class]，如果需要扩展请继承BaseModel
 @param completion id 基于callbackModel传参返回，如果是基础传参则是 CLXDeviceSetting
 */
- (void)getDeviceSettings:(NSString *)deviceId
                channelNo:(NSString *)channelNo
                 cloudDid:(NSString *)cloudDid
            callbackModel:(nonnull Class)callbackModel
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 保存设备配置信息，此接口扩展性强，接入使用此接口

 @param deviceId 设备ID
 @param channelNo 子设备的编号 没有子设备可传nil
 @param path 需要设置的path，@see CLXDeviceSettingDefine，例如设置名字传 GENERAL_TITLE
 @param element 需要设置的元素，@see CLXDeviceSetting 例如设置名字如下
 -> CLXTitle *title = [[CLXTitle alloc] init];
 -> title.text = @"测试";
 -> [sdk saveDeviceSettings:@"xxxx" path:GENERAL_TITLE element:title completion:{ ... }];
 @param completion id 设置是否成功字典
 */
- (void)saveDeviceSettings:(nonnull NSString *)deviceId
                 channelNo:(nullable NSString *)channelNo
                      path:(nonnull NSString *)path
                   element:(nonnull NSObject *)element
                completion:(CLXHttpTaskCompletionHandler)completion;

// --- Old 废弃

/**
 获取设备配置信息

 @param cameraDevice CLCameraDevice
 @param completion Completion Handle {XML String}
 */
- (void)getCameraSettings:(nonnull CLCameraDevice *)cameraDevice
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 将xml转化为CLCameraExtraSettings

 @param xmlString xmlString
 @param device device
 @return CLCameraExtraSettings
 */
- (CLCameraExtraSettings *_Nullable)generateCameraSetting:(nonnull NSString *)xmlString device:(nonnull CLCameraDevice *)device;

/**
 保存设备配置信息

 @param cameraDevice CLCameraDevice
 @param nSettingType CLCameraSetting_E
 @param cameraSettings CLCameraExtraSettings
 @param completion Completion Handle
 */
- (void)setCameraSettingsWithCamera:(nonnull CLCameraDevice *)cameraDevice
                          toSetting:(CLCameraSetting_E)nSettingType
                       withSettings:(nonnull CLCameraExtraSettings *)cameraSettings
                         completion:(CLXHttpTaskCompletionHandler)completion;
@end

#endif /* CLXDeviceSettingProtocol_h */
