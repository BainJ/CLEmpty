//
//  CLSession.h

#import <Foundation/Foundation.h>
#import "SessionConnectModel.h"

#define TIME_BufferMessage_CONNECT_TIMEOUT 20000
#define TIME_XMPP_SEND_TIMEOUT          30000

// Timer intervals
#define TIME_WAIT_DELETE_CAMERA_P2P_TIMEOUT 60000
#define TIME_SHOW_REAL_DISCONNECT       6.0
#define TIME_SHOW_REAL_DISCONNECT_LONG  15.0

/**
 @remark 设置PTZ类型枚举
 
 - CLXPTZTypeUnKnow: CLXPTZTypeUnKnow
 - CLXPTZTypeDoOnce: 设置 一次PTZ，需要direction，上下左右
 - CLXPTZTypeDoContinuos: 设置 持续PTZ，需要direction，上下左右
 - CLXPTZTypeStopContinuos: 设置 停止持续PTZ direction = CLXPTZControlReset
 - CLXPTZTypeResetPosition: 设置 重置PTZ direction = CLXPTZControlReset
 - CLXPTZTypeSetPosition: 设置 指定PTZ，需要location
 */
typedef NS_ENUM(NSInteger, CLXPTZType) {
    CLXPTZTypeUnKnow          = -1,
    CLXPTZTypeDoOnce          = 0,
    CLXPTZTypeDoContinuos     = 1,
    CLXPTZTypeStopContinuos   = 2,
    CLXPTZTypeResetPosition   = 3,
    CLXPTZTypeSetPosition     = 4
};


/**
 @remark 唤醒设备传入的设备类型
 - CLXSubDeviceMode_None: 门铃
 - CLXSubDeviceMode_Relay: 中继设备
 - CLXSubDeviceMode_NVR: NVR设备
 */
typedef NS_ENUM(NSInteger, CLXSubDeviceMode) {
    CLXSubDeviceMode_None  = 0,
    CLXSubDeviceMode_Relay  = 31,
    CLXSubDeviceMode_NVR    = 32,
};

/**
 @remark 指定PTZ（摄像头摇头）的方向
 
 - CLXPTZControlReset: 重置ptz\停止摇头
 - CLXPTZControlLeft: 左
 - CLXPTZControlRight: 右
 - CLXPTZControlUp: 上
 - CLXPTZControlDown: 下
 */
typedef NS_ENUM(NSInteger, CLXPTZControlMode) {
    CLXPTZControlUnKnow = -1,
    CLXPTZControlReset  = 0,
    CLXPTZControlLeft   = 1,
    CLXPTZControlRight  = 2,
    CLXPTZControlUp     = 3,
    CLXPTZControlDown   = 4,
};

/**
 @remark cmd相应结果返回
 
 @param response 响应参数
 */
typedef void (^CLXCmdSessionCallback)(NSDictionary *response);

@protocol CLSession <NSObject>

- (NSInteger)connect:(SessionConnectModel *)connectModel deviceUUID:(NSString *)deviceUUID deviceModelId:(NSString *)deviceModelId;

- (void)disConnect;

- (void)tryreconnect;

/**
 状态、消息回调

 @param callback 回调
 */
- (void)stateCallBack:(void(^)(NSDictionary *dicMessage))callback;


/**
 发送信令通用接口，根据入参规则自己进行拼入
 
 @param deviceId 设备Id
 @param CMD 信令主CMD, 详细参数见文档
 @param subCMD 信令子CMD, 详细参数见文档
 @param param 信令额外参数, 详细参数见文档
 */
- (NSInteger)sendMessageTo:(NSString *)deviceId withCMD:(long)CMD subCMD:(NSNumber *)subCMD param:(NSObject *)param;

/**
 @remark 设置PTZ相关接口
 
 @param deviceId 设备ID
 @param ptzType 设置PTZ类型，@see CLXPTZType
 @param direction 如果 PTZType == CLXPTZTypeDoOnce || CLXPTZTypeDoContinuos 需要指定此参数，上下左右
 如果 PTZType == CLXPTZTypeStopContinuos || CLXPTZTypeResetPosition 需要指定 CLXPTZControlReset
 如果 PTZType == CLXPTZTypeSetPosition 需要指定 CLXPTZControlUnKnow
 @param location 如果（PTZType == CLXPTZTypeSetPosition）时，需要指定此参数，其它传nil。参数类型如@{@"pan": @(0), @"tilt" :@(-10203)}
 @return 错误码
 */
- (NSInteger)setPtzPosition:(NSString *)deviceId
                    ptzType:(CLXPTZType)ptzType
                  direction:(CLXPTZControlMode)direction
                   location:(NSDictionary *)location;

/**
 @remark 获取PTZ当前位置信息
 
 @param deviceId 设备ID
 @return 错误码
 */
- (NSInteger)getPtzPosition:(NSString *)deviceId;

/**
 获取SD卡存储信息
 
 @param deviceId 设备
 @param callbackHandle 回调
 @return 发送消息 成功失败
 */
- (NSInteger)getSDCardStoregeInfo:(NSString *)deviceId callbackHandle:(CLXCmdSessionCallback)callbackHandle;

@end
