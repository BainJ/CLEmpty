
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CLXPlayerType) {
    CLXPlayerTypeRelay,
    CLXPlayerTypeHTTP,
    CLXPlayerTypePath,
    CLXPlayerTypeP2P,
};

typedef NS_ENUM(NSUInteger, CLXCameraMode) {
    CLXCameraModeNone,
    CLXCameraModeRelay,
    CLXCameraModeP2P,
    CLXCameraModeNewP2P,
};

/**
 @brief CLXPlayerDataSource
 */
@protocol CLXPlayerDataSource <NSObject>

/**
 是否支持双工
 */
- (BOOL)isSupportfullDuplexAudioTalk;

/**
 CA证书
 */
- (NSString *)serverCAFilePath;

/**
 日志等级

 @return 0 = disable, 1 = simply, 2 = verbose
 */
- (unsigned int)playerLogOutputLevel;

/**
  音量开关

 @return 0～1.0f
 */
- (float)getVolumeVal;

/**
 是否走Return

 @return YES or NO
 */
- (BOOL)isUseReturn;

/**
 全链路日志开关

 @return YES or NO
 */
- (BOOL)enableDataCollect;

/**
 全链路日志ID
 
 @return requestId
 */
- (NSString *)gpRequestId;

/**
 开始读流
 */
- (void)startStreaming:(NSDate *)startTime;

/**
 结束读流
 */
- (void)stopStreaming;

/**
 获取当前Live播放时间
 */
- (double)getCurrentLiveTime;

/**
 获取播放URL
 */
- (NSString *)getPlayUrl;

/**
 分段式timeline播放

 @return url
 */
- (NSString *)getNextPlayUrl:(NSTimeInterval)startTime;

/**
 分段式timeline播放的下一段URL
 
 @return time list
 */
- (NSArray *)getNextTimeList;

/**
 设备播放类型

 @return CLXPlayerType
 */
- (CLXPlayerType)playerType;

/**
 设备播放类型
 */
- (CLXCameraMode)deviceMode;
/**
 不同播放类型Url
 */
- (NSString *)relayUrl;
- (NSString *)p2pUrl;
- (NSString *)newP2PUrl;
- (NSString *)httpUrl:(NSString *)regionUrl;

/**
 @remark 重试

 @return channel
 */
- (int)retry;

#pragma mark - FishEye
/**
 是否鱼眼设备

 @return YES or NO
 */
- (BOOL)isFishEye;

/**
 获取鱼眼模式

 @return type
 */
- (int)getFishEyeMode;

/**
 是否鱼眼巡航模式

 @return YES or NO
 */
- (BOOL)isCruiseMode;

/**
 获取鱼眼巡航速率

 @return velocity
 */
- (NSInteger)getCruiseVelocity;

/**
 设置http network header
 
 @return network type string
 */
- (NSString *)networkType;

/**
 软解/硬解
 
 @return 是否使用硬解
 */
- (BOOL)supportHardwareDecoder;

@end
