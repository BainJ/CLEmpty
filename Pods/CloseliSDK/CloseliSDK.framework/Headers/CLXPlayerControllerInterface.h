//
//  CLXPlayerControllerInterface.h

#ifndef CLXPlayerControllerInterface_h
#define CLXPlayerControllerInterface_h
#import <Foundation/Foundation.h>
#import "amconstant.h"

/**
 播放器状态回调

 - CLXCameraPlayerStateInitial: 播放初始化播放未开始
 - CLXCameraPlayerStatePrepared: 播放准备就绪
 - CLXCameraPlayerStatePlaying: 播放状态
 - CLXCameraPlayerStateRenderingStart: 开始图像渲染
 - CLXCameraPlayerStatePaused: 暂停状态
 - CLXCameraPlayerStateBuffingStart: 缓冲状态开始
 - CLXCameraPlayerStateBuffingEnd: 缓冲状态结束
 - CLXCameraPlayerStatePlaybackCompleted:
 - CLXCameraPlayerStateStopped: 播放停止
 - CLXCameraPlayerStateError: 播放错误
 */
typedef NS_ENUM(NSInteger, CLXCameraPlayerState) {
    CLXCameraPlayerStateInitial = -1,
    CLXCameraPlayerStatePrepared = 0,
    CLXCameraPlayerStatePlaying,
    CLXCameraPlayerStateRenderingStart,
    CLXCameraPlayerStatePaused,
    CLXCameraPlayerStateBuffingStart,
    CLXCameraPlayerStateBuffingEnd,
    CLXCameraPlayerStatePlaybackCompleted,
    CLXCameraPlayerStateStopped,
    CLXCameraPlayerStateError
};

/**
 cloud 回放模式

 - CLXPlayerHttpTypeNormal: 正常模式
 - CLXPlayerHttpTypeAI: AI模式
 - CLXPlayerHttpTypeFast: 快速模式
 - CLXPlayerHttpTypeKey: 抽帧模式
 */
typedef NS_ENUM(NSInteger, CLXPlayerHttpType) {
    CLXPlayerHttpTypeNormal,
    CLXPlayerHttpTypeAI,
    CLXPlayerHttpTypeFast,
    CLXPlayerHttpTypeKey,
};

@class CLXPlayerParam;

/**
 @brief CLXPlayerControllerInterface, 播放相关接口
 */
@protocol CLXPlayerControllerInterface <NSObject>

/**
 @remark 初始化player view

 @param playerView 传入加载player的容器
 @return CLXPlayerController
 */
- (id)initPlayerController:(UIView *)playerView;

/**
 @brief 设置player相关初始化参数

 @param param 参数model，具体见CLXPlayerParam
 */
- (void)setPlayerParam:(CLXPlayerParam *)param;

/**
 @brief 获取当前player相关初始化参数

 @return CLXPlayerParam
 */
- (CLXPlayerParam *)getPlayerParam;

/**
 @remark 直播播放调用
 */
- (void)preparePlayer;

/**
 @remark 通过路径播放调用，例如本地下载文件
 
 @param pathUrl 本地下载文件路径或者网络连接URL
 */
- (void)preparePlayer:(NSString *)pathUrl;

/**
 @remark 回放播放调用，例如云端回放、SD Card回放
 
 @param regionUrl 指定播放文件的域名 downloadServer
 @param timelineList 起始时间和结束时间的数组, 例如@[@(start), @(end)], start = end时一直播下去
 @param playbackType 云端回放Type，正常状态请输入CLXPlayerHttpTypeNormal。
 */
- (void)preparePlayer:(NSString *)regionUrl :(NSMutableArray <NSNumber *> *)timelineList :(CLXPlayerHttpType)playbackType;

/**
 @remark 播放clip视频，seek到指定位置
 
 @param timeStamp 指定播放时间戳，单位毫秒
 */
- (void)seek:(NSTimeInterval)timeStamp;

/**
 @remark 设置播放器放大倍数
 
 @param scale 原始放大倍数，初始化为1.0
 */
- (void)setOpenGLFullView:(float)scale;
 
/**
 @remark 播放云端回放、SDCard时，不同时间点的切换
 
 @param timelineList 起始时间和结束时间的数组, 例如@[@(start), @(end)], start = end时一直播下去
 @param regionUrl 指定播放文件的域名 downloadServer
 */
- (void)seek:(NSMutableArray <NSNumber *> *)timelineList regionUrl:(NSString *)regionUrl playbackType:(CLXPlayerHttpType)playbackType;

/**
 @remark 释放player
 */
- (void)releasePlayer;

/**
 @remark player当前的状态
 
 @return CLXCameraPlayerState 当前player状态
 */
- (CLXCameraPlayerState)getPlayerState;

/**
 @remark 获取回放云端视频类型
 
 @return CLXPlayerHttpType
 */
- (CLXPlayerHttpType)getPlaybackType;

/**
 @remark 获取当前播放状态，是否是回放
 
 @return YES 是回放、NO 是直播
 */
- (BOOL)isPlayBack;
@end

#endif /* CLXPlayerControllerInterface_h */
