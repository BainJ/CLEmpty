

#import <Foundation/Foundation.h>

@class CLXMP4Muxer;

@protocol CLXMP4MuxerDatasource <NSObject>

/*!
 @method     itemAudioType
 @abstract   获取播放单元音频类别
 @return     音频类别
 
 typedef enum _CLXDeviceAudioType
 {
 CLXDeviceAudio_AAC = 0,
 CLXDeviceAudio_G726 = 1,
 CLXDeviceAudio_G711ALAW = 2,
 CLXDeviceAudio_G711ULAW = 3,
 }CLXDeviceAudioType;
 */
- (int) itemAudioType;


/**
 保存本地路径的文件名
 */
- (NSString *) fileName;


@end

/*!
 @protocol  CLXMP4MuxerDelegate
 @abstract  muxer代理，录制时的状态回调
 */
@protocol CLXMP4MuxerDelegate <NSObject>

/**
 录视频代理 录视频的秒数记录
 @param recordTime 秒数
 */
- (void)currentRecordDurition:(NSInteger)recordTime;

/**
 录视频代理 停止记录视频
 @param sucFlag 是否成功记录
 @param filePath 视频存储的路径
 @param autoStop 是否自动停止 NO是手动停止
 */
- (void)stopRecordWithSucFlag:(BOOL)sucFlag filePath:(NSString*)filePath autoStop:(BOOL)autoStop;

@end

/*!
 @class     CLMP4Muxer
 @abstract  录制mp4工具封装
 */
@interface CLXMP4Muxer : NSObject

/*!
 @property  delegate
 @abstract  muxer代理，录制时的状态回调
 */
@property (nonatomic, weak) id<CLXMP4MuxerDelegate> delegate;

/*!
 @property  datasource
 @abstract  muxer代理，录制时的需要传入信息
 */
@property (nonatomic, weak) id<CLXMP4MuxerDatasource> datasource;

/*!
 @method    reset
 @abstract  重置 mp4 muxer
 */
- (void) reset;

/*!
 @method    setUpMuxerWithAudioType
 @param     audioType   音频类型
 @param     path        录制文件存储路径
 @abstract  初始化 mp4 muxer
 @return    标识指针用于拼装协议url
 */
- (void*) setUpMuxerWithAudioType:(int)audioType atSavePath:(char*)path;

/*!
 @method    startRecord
 @abstract  开始录制
 */
- (void) startRecord;

/*!
 @method    stopRecord
 @abstract  停止录制
 */
- (void)stopRecord;

/*!
 @method    isRecording
 @abstract  是否正在录制
 @return    YES 正在录制，NO otherwise
 */
- (BOOL) isRecording;

@end
