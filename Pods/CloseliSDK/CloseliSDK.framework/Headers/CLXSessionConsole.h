//
//  CLXSessionConsole.h

#import <Foundation/Foundation.h>
#import "CLCmdSession.h"
#import "CLStreamSession.h"
#import "CLTimelineData.h"

@interface CLXSessionConsole : NSObject

+ (void)connect;
+ (void)disconnect;
- (void)sendPlayBackDeviceId:(NSString *)deviceId;
- (id<CLStreamSession>)getStreamSession:(BOOL)isMultiPlay isPlayBack:(BOOL)isPlayBack isPlaySDCard:(BOOL)isPlaySDCard;
- (id<CLCmdSession>)getCMDSession;
- (id<CLStreamSession>)getTcpSession;
- (id<CLStreamSession>)getDownloadSession;

#pragma mark - Interface
/**
 @remark 获取缩略图

 @param size size
 @return 返回NSData
 */
- (NSData *)getThumbnail:(CGSize)size requestId:(NSString *)requestId;

/**
 @remark 获取SDCard当前状态

 @return 字典
 */
- (NSDictionary *)getSDCardInfo:(NSString *)requestId;

/**
 @remark 兼容第三方设备获取
 
 @return 错误码
 */
- (NSInteger)getSDCardInfo:(NSString *)requestId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 @remark 人脸注册
 
 @return YES or NO
 */
- (BOOL)faceRegisterWithStep:(CLXFaceRegisterStep)step;


/**
 获取SD卡timeline

 @param timelinInData 入参，详细见model说明
 @param pptimelineData 出参，详细见model说明
 @param requestId 事件ID，没有传nil
 @return 错误码
 */
- (long)getTimelineFromSDCard:(CLTimelineInData *)timelinInData
                       toData:(CLTimelineData *__autoreleasing *)pptimelineData
                    requestId:(NSString *)requestId;

/**
 @remark 手动停止SD卡timeline获取，防止SD卡timeline获取没有结束再次请求busy
 */
- (void)stopGetSDCardTimeline;

/**
 @remark 更新AP模式相关参数
 */
- (void)updateAPMode:(SessionConnectModel *)connectModel;

/**
 设置AP设备清晰度
 
 @param deviceId 设备Id
 @param isHD 是否是HD
 */
- (NSInteger)setAPCameraHD:(NSString *)deviceId isHd:(BOOL)isHD;

/**
 获取设备当前播放流数量
 
 @param deviceId 设备Id
 @param callbackHandle 返回数据
 @return 错误码
 */
- (NSInteger)getDeviceLiveCount:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 更新网络状态变化
 
 @param bConnected YES or NO
 @return 错误码
 */
+ (NSInteger)setNetworkStatus:(BOOL)bConnected;

/**
 获取logon在线的设备
 
 @return 设备array
 */
+ (NSArray *)getP2POnlineDevice;

/**
 获取logon p2p服务
 
 @return 服务名
 */
+ (NSString *)getSoftwareID;

/**
 获取p2p连接type
 
 @param fullPeerId 链路ID
 @return type
 */
+ (int)getP2PConnectType:(NSString *)fullPeerId;

/**
 更新使用优先级

 @param param 参数
 @return YES or NO
 */
- (BOOL)updatePriorityAccess:(NSArray *)param;

/**
 删除优先级
 */
- (void)removePriorityAccess;
#pragma mark - Subclass Override
///=============================================================================
/// @name Subclass Override
///=============================================================================

/**
 @remark 设置产品秘钥

 @return 产品秘钥
 */
- (NSString *)productKey;

/**
 @remark 设置用户信息

 @return 用户账户，email or mobile
 */
- (NSString *)account;

/**
 @remark 设置用户信息

 @return 用户虚拟账户，unifiledId
 */
- (NSString *)unifiledId;

/**
 @remark 设置用户信息

 @return 用户token，登录之后返回token
 */
- (NSString *)token;

/**
 @remark 设置设备信息

 @return 设备svr状态
 */
- (NSInteger)svrStatus;

/**
 @remark 设置设备信息

 @return 设备shareID
 */
- (NSString *)shareId;

/**
 @remark 设置设备信息

 @return 设备是否支持websocket
 */
- (BOOL)isSupportWebsocket;

/**
 @remark 设置设备信息

 @return 设备是否支持newP2P
 */
- (BOOL)isSupportNewP2P;

/**
 @remark 设置设备信息
 
 @return 设备是否支持fullRelay
 */
- (BOOL)isSupportFullRelay;

/**
 @remark 设置设备信息

 @return 设备ID
 */
- (NSString *)deviceId;

/**
 @remark 设置设备信息

 @return 设备model
 */
- (NSString *)deviceModel;

/**
 @remark 设置设备信息

 @return Host
 */
- (NSString *)relayHost;

/**
 @remark 设置设备信息

 @return Port
 */
- (NSInteger)relayPort;

/**
 获取通道

 @return 通道index
 */
- (int)getLiveChannel;

/**
 重试通道

 @return 重试通道index
 */
- (int)retry;

/**
 @remark 设备信息
 
 @return 是否是国标设备
 */
- (BOOL)isGbDevice;

/**
 @remark 设备信息
 
 @return 是否是三方设备
 */
- (BOOL)isThirdPartyDevice;

/**
 子设备通道号

 @return 通道号
 */
- (NSString *)channelNo;

/**
 获取ap模式IV
 
 @return IV
 */
- (NSString *)getAPIV;

/**
 获取ap模式key1
 
 @return key1
 */
- (NSString *)getAPKey;

/**
 获取ap模式key2
 
 @return key2
 */
- (NSString *)getAPDesKey;

@end
