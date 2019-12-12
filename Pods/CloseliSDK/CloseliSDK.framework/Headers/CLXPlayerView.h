
#import <UIKit/UIKit.h>
#import "CLXPlayerController.h"
#import "CLCameraDevice.h"
#import "CLStreamSession.h"

@protocol CLXPlayerViewCallback <NSObject>

@optional
/**
 配置前一段播完会通过此方法获取下一段播放时间戳

 @return timelineList Array 【startTime，endTime】
 */
- (NSArray *)getNextTimeList;

/**
 外部可配置是否硬解

 @return 是否硬解
 */
- (BOOL)isSupportHardwareDecoder;

@end

/**
 @brief CLXPlayerView
 */
@interface CLXPlayerView : UIView
/**
 MuxHandle 用于边播边录功能
 */
@property (nonatomic, assign) void *currentMuxHandle;
@property (nonatomic, copy) NSString *gpRequestId;
@property (nonatomic, copy) NSDictionary *pbParam;
@property (nonatomic, weak) id <CLXPlayerViewCallback> playerViewCallback;
/**
 CLXPlayerController player使用类
 */
@property (nonatomic, strong) CLXPlayerController *playerController;

/**
 初始化View
 @param frame 需要展示视频的frame
 @param device 设备信息
 */
- (id)initWithFrame:(CGRect)frame withDevice:(CLCameraDevice *)device;

/**
 获取player正在使用的视频流
 
 @return CLStreamSession
 */
- (id<CLStreamSession>)getStreamSession;

/**
 获取player正在使用的视频流通道
 
 @return Unknown, Http, Relay, OldReturn, OldP2P, NewP2P
 */
- (NSString *)getStreamChannel;

/**
 Pinch手势

 @param gesture UIPinchGestureRecognizer
 */
- (void)onPinchGesture:(UIPinchGestureRecognizer *)gesture;

/**
 Double Tap手势

 @param gesture UITapGestureRecognizer
 */
- (void)onDoubleTapGesture:(UITapGestureRecognizer *)gesture;

/**
 Touch Move手势

 @param gesture UIPanGestureRecognizer
 */
- (void)onTouchMoveGesture:(UIPanGestureRecognizer *)gesture;

@end
