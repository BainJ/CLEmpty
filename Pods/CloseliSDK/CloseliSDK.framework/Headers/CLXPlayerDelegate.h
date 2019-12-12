

#import <Foundation/Foundation.h>

/**
 @brief CLXPlayerDelegate
 */
@protocol CLXPlayerDelegate <NSObject>

/**
 player状态码回调

 @param playState player状态（CLXCameraPlayerState）
 @param code player错误码
 */
- (void)onPlayStateChanged:(int)playState code:(int)code;

/**
 player播放过程中消息交互回调

 @param code 消息code
 @param extra 消息额外传参
 */
- (void)onPlayMessage:(int)code extra:(int)extra;

/**
 video size 更新回调

 @param size 宽、高
 */
- (void)onPlayFrameChanged:(CGSize)size;

/**
 当打开player全链路日志开关时，数据返回

 @param data 返回的数据
 */
- (void)onPlayerDataCollection:(NSString *)data;

@optional
/**
 player初始化之后，onPath之前，可以在该回调中配置Config。如设置YUV数据流；
 */
- (void)onPlayerConfig;

@end
