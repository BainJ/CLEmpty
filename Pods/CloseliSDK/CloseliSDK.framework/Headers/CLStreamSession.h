//
//  CLStreamSession.h

#import <Foundation/Foundation.h>
#import "CLSession.h"
#import "CLTimelineData.h"
#import "CLTimelineInData.h"

/**
 @remark 设置PTZ类型枚举
 
 - CLXFaceRegisterStepNULL: null
 - CLXFaceRegisterStepStart: 开始人脸注册
 - CLXFaceRegisterStepStop: 结束人脸注册
 - CLXFaceRegisterStepCancel: 取消人脸注册
 - CLXFaceRegisterStepPrepare: 开始人脸探测
 - CLXFaceRegisterStepSaveVideo: 保存人脸视频
 */
typedef NS_ENUM(NSInteger, CLXFaceRegisterStep) {
    CLXFaceRegisterStepNULL          = 0,
    CLXFaceRegisterStepStart         = 9,
    CLXFaceRegisterStepStop          = 10,
    CLXFaceRegisterStepCancel        = 11,
    CLXFaceRegisterStepPrepare       = 12,
    CLXFaceRegisterStepSaveVideo     = 13
};

@protocol CLStreamSession <CLSession>

- (void)dataCallBack:(void(^)(NSDictionary *dicMessage))callback;
- (void)startStreamingConnectWithChannelMode:(NSInteger)mode withllipcamtime:(long long)llipcamtime message:( NSDictionary *)message requestId:(NSString *)requestId stateCallBack:(void(^)(NSString * type,BOOL repeat))callBack;
- (void)stopStreaming;
- (BOOL)updateRelayAddress:(NSString *)mstrip :(int)port;
- (int)playerPreSetupP2PChannel:(NSString *)requestId;
- (BOOL)isUsePriorityAccess;
- (BOOL)isNewP2PChannel;
- (NSInteger)getRttInfo;
- (NSString *)streamSrcId;
- (long long)getCameraRealTime;

#pragma mark - AudioTalk
/**
 初始化audiotalk buffer

 @param samplingrate 频率
 @param encodertype 编码
 @param audioOutputHandle 消回声指针，from player controller
 */
- (void)initAudioBuffer:(int)samplingrate encodertype:(long)encodertype audioOutputHandle:(void *)audioOutputHandle;

/**
 销毁audiotalk buffer

 @return yes or no
 */
- (BOOL)uninitAudioTalk;

/**
 开始语音

 @param isSupportFullDuplexTalk 是否是全双工
 @param p2pID from device model
 @return 成功
 */
- (BOOL)beginAudioTalking:(BOOL)isSupportFullDuplexTalk p2pID:(NSString *)p2pID;

/**
 结束语音

 @return 成功
 */
- (BOOL)endAudioTalking;

/**
 音量

 @return 当前值
 */
- (long)audioTalkDevibelValue;


/**
 获取设备最大播放数
 
 @param deviceId 设备Id
 */
- (NSInteger)getMaxRelayCount:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 获取句柄
 
 @return 指针地址
 */
- (long)getHandle;

/**
 设置图像旋转角度
 
 @param deviceId 设备
 @param rotate 旋转角度，0 、180
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setImageRotate:(NSString *)deviceId rotate:(NSString *)rotate callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置SD卡录制时长
 
 @param deviceId 设备
 @param duration 录制时长，15，30，45，-1(永久)
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setSDCardRecordDuration:(NSString *)deviceId duration:(NSString *)duration callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置SD卡录制模式
 
 @param deviceId 设备
 @param mode 模式， 1，2，3 （1，表示什么都不录制，2，表示事件录制，3表示全天录制）
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setSDCardRecordMode:(NSString *)deviceId mode:(NSString *)mode callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置pir灵敏度
 
 @param deviceId 设备
 @param sensitivity 0-100
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setPirSensitivity:(NSString *)deviceId sensitivity:(NSString *)sensitivity callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置motion灵敏度
 
 @param deviceId 设备
 @param sensitivity 30、50、80、90、100
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setMotionSensitivity:(NSString *)deviceId sensitivity:(NSString *)sensitivity callbackHandle:(CLXCmdSessionCallback)callbackHandle;

/**
 设置防闪烁频率

 @param deviceId 设备id
 @param frequency 频率，50、60 HZ
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)setAntiflickerFrequency:(NSString *)deviceId
                           frequency:(NSString *)frequency
                      callbackHandle:(CLXCmdSessionCallback)callbackHandle;

@end
