

#import "CLXMP4Muxer.h"

/*!
 @class     CLMP4Muxer
 @abstract  录制mp4工具类
 */
@interface CLXMp4MuxerHelper : NSObject

/*!
 @method     initMp4MuxerWithDatasource
 @param     datasource 录制时需要的信息
 @param     delegate 录制状态代理
 @abstract  初始化mp4工具类
 @return    录制mp4工具实例
 */
- (instancetype)initMp4MuxerWithDatasource:(id<CLXMP4MuxerDatasource>)datasource
                             MuxerDelegate:(id<CLXMP4MuxerDelegate>)delegate;

/*!
 @method     startRecord
 @abstract  开始录制
 @return    Yes 开始成功， no otherwise
 */
- (BOOL)startRecord;

/*!
 @method     stopRecord
 @abstract  结束录制
 */
- (BOOL)stopRecord ;

/*!
 @method     muxerBlock
 @abstract  创建录制指针内存块，用于加入tcpbuffer中
 @return    指针内存块
 */
- (void*)muxerBlock;

/*!
 @method     reset
 @abstract  充值 mp4Muxer 释放资源
 */
- (void)reset;

@end
