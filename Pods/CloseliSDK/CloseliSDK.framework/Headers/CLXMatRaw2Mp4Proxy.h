//
//  CLXMatRaw2Mp4Proxy.h

#import <Foundation/Foundation.h>
#import "CLCameraDevice.h"

/**
 @brief Mp4Proxy数据源
 */
@protocol CLXMatRaw2Mp4ProxyDataSource <NSObject>

@optional

/**
 @remark 日志开关

 @return 0、1、2
 */
- (unsigned int)logLevel;

/**
 @remark mp4文件长度

 @return 例如1024
 */
- (float)fileLength;

@end

/**
 @brief Mp4Proxy回调
 */
@protocol CLXMatRaw2Mp4ProxyDelegate <NSObject>

/**
 @brief 开始录制后回调

 @param progress 一个字典, 例@{@"Progress" : @[@"12", @"0", @"-123123"]}， 数组第一个是录制的时间进度、第二个是录制是否结束、第三个是当前这个raw2mp4的实例
 */
- (void)downloadProgress:(NSDictionary *)progress;

/**
 @brief 录制后文件路径回调
 
 @param filePath 一个字典, 例@{@"FilePath" : @[@"xxxxx.mp4", @"-2133303616"]}, 数组第一个是文件路径、第二个是当前实例
 */
- (void)downloadFilePath:(NSDictionary *)filePath;

@end

/**
 @brief 下载云存储到本地插件
 */
@interface CLXMatRaw2Mp4Proxy : NSObject

@property (nonatomic, weak) id <CLXMatRaw2Mp4ProxyDelegate> delegate;
@property (nonatomic, weak) id <CLXMatRaw2Mp4ProxyDataSource> dataSource;

/**
 云端回放 开始下载视频

 @param deviceId 设备ID
 @param filePath 本地存储路径
 @param fileName 文件名，非必传
 @param region 设备当前机房region
 @param timelineArray 下载区间 timelineArr[0] = 开始时间;timelineArr[1] = 结束时间;
 @return 是否成功
 */
- (BOOL)start:(NSString *)deviceId filePath:(NSString *)filePath fileName:(NSString *)fileName region:(NSString *)region timelineArray:(NSArray *)timelineArray;


/**
 Relay/P2P回放 开始下载视频

 @param device 设备（CLCameraDevice）
 @param filePath 本地存储路径
 @param fileName 文件名，非必传
 @param timelineArray 下载区间 timelineArr[0] = 开始时间;timelineArr[1] = 结束时间;
 @return 是否成功
 */
- (BOOL)start:(CLCameraDevice *)device filePath:(NSString *)filePath fileName:(NSString *)fileName timelineArray:(NSArray *)timelineArray;

/**
 @remark 结束下载，必须调用此接口保存的视频才能正常播放

 @return 是否成功
 */
- (BOOL)stop;

@end
