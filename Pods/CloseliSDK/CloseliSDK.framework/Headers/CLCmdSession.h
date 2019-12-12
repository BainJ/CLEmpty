//
//  CLCmdSession.h

#import <Foundation/Foundation.h>
#import "CLSession.h"
#import "CLXDeviceWifiInfo.h"
#import "CLXMsgParam.h"

/*!
 camera升级回调，当camera升级时需要设置这个回调，则camera在下载固件的过程中会不断发送进度给APP，下载完成后APP需要等待camera上线
 */
typedef void (^AutoUpdateProgressBlock)(NSString *camerap2pID, unsigned long long size, unsigned long long total, NSString *channelNo);
/*!
 camera升级状态回调
 */
typedef void (^AutoUpdateStateBlock)(NSString *camerap2pID ,NSInteger nRet, BOOL refresh, NSString *channelNo);

@protocol CLCmdSession <CLSession>

/**
 设置网络状态
 
 @param bConnected 有网YES、无网NO
 @return 错误码
 */
- (NSInteger)setNetworkStatus:(BOOL)bConnected;

/**
 @remark 设置Wi-Fi

 @param deviceId 设备ID
 @param wifiInfo Wi-Fi信息模型
 @see CLXDeviceWifiInfo
 @return 错误码
 */
- (NSInteger)setCameraWiFiInfo:(NSString *)deviceId wifiInfo:(CLXDeviceWifiInfo *)wifiInfo;

/**
 @remark 获取设备Wi-Fi列表

 @param deviceId 设备ID
 */
- (void)getCameraWiFiList:(NSString *)deviceId;

/**
 @remark 格式化sd卡

 @param deviceId 设备ID
 @return 错误码
 */
- (NSInteger)formatSDCard:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 发送开始更新

 @param deviceId 设备ID
 @param url 更新URL
 @param serviceType 更新服务类型
 @param newServiceVersion 更新版本号
 @param checkSum checkSum
 @param timeout 超时
 @param downloadProcessBlock 进度回调
 @param stateBlock 状态回调
 @return 错误码
 */
- (NSInteger)startCameraUpdate:(NSString *)deviceId
                           url:(NSString *)url
                   serviceType:(NSInteger)serviceType
             newServiceVersion:(NSString *)newServiceVersion
                      checkSum:(NSString *)checkSum
                       timeout:(NSInteger)timeout
                 progressBlock:(AutoUpdateProgressBlock)downloadProcessBlock
                    stateBlock:(AutoUpdateStateBlock)stateBlock;

/**
 @remark 获取4G SIM卡本月消耗的流量统计

 @param deviceId 设备ID
 @param callbackHandle response
 @return 发送错误码
 */
- (NSInteger)get4GSIMFlowBytesCurMonth:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 获取4G信号强弱

 @param deviceId 设备ID
 @param callbackHandle response
 @return 发送错误码
 */
- (NSInteger)get4GSignalStrength:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 设备播放告警音频
 
 @param deviceId 设备ID
 @param alarmType 默认传：1
 @param callbackHandle response
 @return 发送错误码
 */
- (NSInteger)setDeviceAlarmDeviceId:(NSString *)deviceId alarmType:(NSInteger)alarmType callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 透传数据
 
 @param data 数据流
 @param requestId 外部请求ID
 @return 错误码
 */
- (NSInteger)sendBufferMessageToServer:(NSData *)data requestId:(NSString *)requestId;

/**
 @remark 国标设备回放
 
 @param deviceId 设备ID
 */
- (void)sendPlayBackDeviceId:(NSString *)deviceId;

/**
 @remark 国标设备PTZ操作
 
 @param deviceId 设备ID
 @param direction 外部请求ID
        0：停止,1：向上转动,2：向下转动,3：向左转动,4：向右转动,5：向左上转动,6：向左下转动,7：向右上转动,8：向右下转动
 @param speed ptz速度
 */
- (void)sendPtzMessageWithGbDevice:(NSString *)deviceId ptzDirection:(NSInteger)direction speed:(NSInteger)speed;


/**
 @remark 国标设备发送scale
 
 @param deviceId 设备ID
 @param scale 播放速度
 */
- (void)sendScaleMessageWithGbDevice:(NSString *)deviceId scale:(float)scale;

/**
 @remark 唤醒设备
 
 @param deviceId 设备ID
 @param subDeviceMode 子设备模式
 @param callbackHandle callbackHandle response
 @return 发送错误码
 */
- (NSInteger)wakeUpDevice:(NSString *)deviceId subDeviceMode:(CLXSubDeviceMode)subDeviceMode callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 设置自定义配置
 
 @param deviceId 设备信息
 @param defContent 自定义内容
 @param callbackHandle response
 @return 发送错误码
 */
- (NSInteger)setDeviceSelfDefDeviceid:(NSString *)deviceId
                           defContent:(NSObject *)defContent
                       callbackHandle:(CLXCmdSessionCallback)callbackHandle;


/**
 获取ptz全景拼接图片
 
 @param deviceId 设备
 @param angle 每次旋转角度
 @param isPortration 是否是正装
 @param callbackHandle 回调
 
 @return 发送消息 成功失败
 */
- (NSInteger)getPTZPanorama:(NSString *)deviceId isTurnOn:(BOOL)turnOn angle:(int)angle isOrientationPortration:(BOOL)isPortration callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 获取设备WIFI强度
 
 @param deviceId 设备
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)getWifiSignal:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 获取门铃设备电量
 
 @param deviceId 设备
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)getDeviceBattery:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 获取在线人数
 
 @param deviceId 设备
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)getDeviceLiveCount:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;


/**
 设置声光参数
 
 @param deviceId 设备
 @param value 0：关 1：开 2：自动
 @param callbackHandle 回调
 @return 发送消息 0成功 else失败
 */
- (NSInteger)setDeviceAcoustoOptic:(NSString *)deviceId value:(NSString *)value callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 定时点检截图
 
 @param deviceId 设备
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setDeviceSnapShot:(NSString *)deviceId bid:(NSString *)bid location:(NSDictionary *)location callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 获取设备铃声

 @param deviceId 设备ID
 @param callbackHandle response
 @return 发送错误码
 */
- (NSInteger)getDeviceRingInfo:(NSString *)deviceId
                callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置当前设备铃声

 @param deviceId 设备ID
 @param downloadUrl 下载铃声的URL
 @param ringId 铃声编号ID
 @param volume 铃声声音大小0-100
 @param deviceType 设备标识，0是主设备，1是子设备（如果有子设备，例如中继）
 @param callbackHandle respons
 @return 发送错误码
 */
- (NSInteger)setDeviceRing:(NSString *)deviceId
               downloadUrl:(NSString *)downloadUrl
                    ringId:(NSString *)ringId
                    volume:(int)volume
                deviceType:(int)deviceType
            callbackHandle:(CLXCmdSessionCallback)callbackHandle;
@end

