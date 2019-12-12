//
//  CLXRegionDispatcherProtocol.h

#ifndef CLXRegionDispatcherProtocol_h
#define CLXRegionDispatcherProtocol_h

#import <Foundation/Foundation.h>
#import "CLXTimelineInterval.h"
#import "CLXFileInfo.h"
#import "CLXDeviceDataModel.h"
#import "CLXHttpClientDefine.h"
#import "CLTimelineEventClip.h"

/*!
 @brief 平台分机房相关API，主要是跟视频、图片等文件相关
 */
@protocol CLXRegionDispatcherProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configDeviceDataToken:(nullable NSString *)token;

/**
 获取内存中设备的regionInfo
 
 @param deviceId 设备mac（xxxS_）
 */
- (NSArray *_Nullable)getRegionList:(NSString *_Nonnull)deviceId;

/**
 清除内存中设备的regionInfo，如果有deviceId则清除对应，nil则清除所有
 
 @param deviceId 设备mac（xxxS_）
 */
- (void)clearRegionList:(NSString *_Nullable)deviceId;

#pragma mark - file
/**
 获取文件列表
 
 @param deviceId required，设备ID
 @param pageSize required，分页时每页显示的文件数量
 @param lastClipTime required，上一次clip的时间戳(首次传当前时间戳) 毫秒
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {CLXFileList}
 */
- (void)getFileList:(NSString *_Nonnull)deviceId
           pageSize:(NSNumber *_Nonnull)pageSize
       lastClipTime:(NSDate *_Nullable)lastClipTime
           needMore:(BOOL (^_Nullable)(void))needMore
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取文件信息
 
 @param deviceId required，设备ID
 @param fileId required，文件ID
 @param abbr required，region别名
 @param extra optional，额外的返回信息，可以多个，用,分隔。目前支持：comment返回comment oem用来保存camera信息，thumbnail 如果是图片或视频，返回缩略图，duration 如果是视频，返回duration
 @param version optional，如果指定，返回指定的历史版本（如果存在）文件的所有属性；如果不指定，返回最新版本文件的所有属性
 @param https optional，使用该参数且值为true(不区分大小写)后，downloadServer返回值以https开头
 @param completion optional，Completion Handler: {CLXFileInfo}
 */
- (void)getFileInfo:(NSString *_Nonnull)deviceId
             fileId:(NSString *_Nonnull)fileId
               abbr:(NSString *_Nonnull)abbr
              extra:(NSString *_Nullable)extra
            version:(NSString *_Nullable)version
              https:(BOOL)https
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 文件更名
 
 @param deviceId required，设备ID
 @param fileId required，文件ID
 @param abbr required，region别名
 @param name required，更改后的file名称
 @param completion optional，Completion Handler: {}
 */
- (void)renameFile:(NSString *_Nonnull)deviceId
            fileId:(NSString *_Nonnull)fileId
              abbr:(NSString *_Nonnull)abbr
              name:(NSString *_Nonnull)name
        completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除文件
 
 @param deviceId required，设备ID
 @param fileId required，文件ID，支持传入多个ID，以逗号分开
 @param abbr required，region别名
 @param version optional, 该参数只对文件有效。如果指定，删除指定的历史版本；如果不指定，则删除文件本身以及所有历史版本
 @param completion optional，Completion Handler: {}
 */
-(void)deleteFile:(NSString *_Nonnull)deviceId
           fileId:(NSString *_Nonnull)fileId
             abbr:(NSString *_Nonnull)abbr
          version:(NSString *_Nullable)version
       completion:(CLXHttpTaskCompletionHandler)completion;

/**
 下载文件
 
 @mark 需要在子线程里调用该方法
 @param deviceId required，设备ID
 @param fileId required，文件ID，支持传入多个ID，以逗号分开
 @param abbr required，region别名
 @param version optional, 该参数只对文件有效。如果指定，删除指定的历史版本；如果不指定，则删除文件本身以及所有历史版本
 @param downloadPath required，下载文件路径
 @param progress optional，下载进度
 @param timeOut optional，超时时间,单位为ms毫秒;超时检查.在timeOut时间内无更新的文件将不能下载.不传则不检查
 @param completion optional，Completion Handler: {path<NSString *>}
 */
- (NSURLSessionTask *_Nullable)downloadfile:(NSString *_Nonnull)deviceId
                                  fileId:(NSString *_Nonnull)fileId
                                    abbr:(NSString *_Nonnull)abbr
                                 version:(NSString *_Nullable)version
                            downloadPath:(NSString *_Nonnull)downloadPath
                                progress:(void (^_Nullable)(NSProgress *_Nonnull))progress
                                 timeOut:(NSString *_Nullable)timeOut
                              completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - clip
/**
 创建视频剪辑
 
 @param deviceId required，设备ID
 @param channelId optional，1:qvga; 2:720p；不传默认为2
 @param startTime required，开始时间
 @param endTime required，结束时间
 @param clipFrom optional，区分视频剪辑场景，1：C31语音剪辑；2：标识报警事件收藏；3：新场景(云相册)报警事件收藏；4：新场景(云相册)默认生成普通mp4场景收藏；其他值或不传值为默认生成普通mp4
 @param isSync optional，控制同步操作还是异步操作，0：异步，1：同步；默认0
 @param isHighlights optional，默认为空，传 1 代表是highlights的makeclip操作
 @param title optional，用户指定的clip title，允许1-50个字符，不允许的字符为 \/:*?"<>l ，不填系统默认生成
 @param completion optional，Completion Handler: {NSDictionary}，返回字典：{@"fileId": @"xxxx", @"abbr": @"xxxx"}
 */
- (void)makeClip:(NSString *_Nonnull)deviceId
       channelId:(NSString *_Nullable)channelId
       startTime:(NSDate *_Nonnull)startTime
         endTime:(NSDate *_Nonnull)endTime
        clipFrom:(NSString *_Nullable)clipFrom
          isSync:(NSString *_Nullable)isSync
    isHighlights:(NSString *_Nullable)isHighlights
           title:(NSString *_Nullable)title
      completion:(CLXHttpTaskCompletionHandler)completion;

/**
 查询clip时间信息

 @param deviceId required，设备ID
 @param completion optional，Completion Handler: {clip_sum}
 */
- (void)getClipStorage:(NSString *_Nonnull)deviceId
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 查询设备的clip文件总数
 
 @param deviceId required，设备ID
 @param completion optional，Completion Handler: {CLXTimelineStorageResult}
 */
- (void)getClipSum:(NSString *_Nonnull)deviceId
        completion:(CLXHttpTaskCompletionHandler)completion;

#pragma mark - timeline
/**
 获取TimeLineSectionList
 
 @param deviceId required，设备ID
 @param channelId optional channel，default 2
 @param shareId optional,来自分享设备传shareId，其他传nil
 @param sectionModel required，保存的timeLine时段
 @param ifSupportPayment optional, default0, 不传或者0都是不支持未支付套餐，传1表示未支付取数据
 @param pageSize required，分页时每页显示的文件数量
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {CLTimelineData}
 */
- (void)getTimelineSectionList:(NSString *_Nonnull)deviceId
                     channelId:(NSString *_Nullable)channelId
                       shareId:(NSString *_Nullable)shareId
                  sectionModel:(CLXTimeSection *_Nonnull)sectionModel
              ifSupportPayment:(NSString *_Nullable)ifSupportPayment
                      pageSize:(NSNumber *_Nonnull)pageSize
                      needMore:(BOOL (^_Nullable)(void))needMore
                    completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取TimeLineEventList

 @param deviceId required，设备ID
 @param channelId optional channel，default 2
 @param shareId optional,来自分享设备传shareId，其他传nil
 @param eventType optional, 对应事件type作为过滤条件，传nil则默认获取所有event
 @param gbFlag optional, 区分normal和国标；
 @param sectionModel required，保存的timeLine时段
 @param pageSize required，分页时每页显示的文件数量
 @param isSupport required，是否需要支持白名单功能
 @param personIds optional， 人脸ID
 @param personRelation optional，基于人脸ID查询方式。0：并集，所有包含person_id的事件；1：交集，所有同时包含person_id的事件。默认0。
 @param ifSupportPayment 不传或者0都是不支持未支付套餐， 1是支持未支付套餐
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {CLTimelineData}
 */
- (void)getTimelineEventList:(NSString *_Nonnull)deviceId
                   channelId:(NSString *_Nullable)channelId
                     shareId:(NSString *_Nullable)shareId
                   eventType:(NSString *_Nullable)eventType
                      gbFlag:(NSString *_Nullable)gbFlag
                sectionModel:(CLXTimeSection *_Nonnull)sectionModel
                    pageSize:(NSNumber *_Nonnull)pageSize
          isSupportWhiteList:(BOOL)isSupport
                   personIds:(NSArray *_Nullable)personIds
              personRelation:(NSString *_Nullable)personRelation
            ifSupportPayment:(NSString *_Nullable)ifSupportPayment
                    needMore:(BOOL (^_Nullable)(void))needMore
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 删除TimeLineEventList
 
 @param events required，CLTimelineEventClip类，会用到其中的eventID和downloadURL
 @param deviceId required，设备ID
 @param completion optional，Completion Handler: {}
 */
- (void)deleteTimelineEvents:(NSArray <CLTimelineEventClip *>*_Nonnull)events
                    deviceId:(NSString *_Nonnull)deviceId
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 单个删除TimeLineEventList

 @param deviceID required，设备ID
 @param channelId optional，目前支持：1:qvga; 2:720p, 3:1080p，只校验格式，自己保证有效性。
 @param eventId required，事件ID
 @param eventType required，事件type
 @param startTime required，事件开始时间
 @param region required，每个事件model downloadURL属性
 @param completion optional，Completion Handler: {}
 */
- (void)deleteTimelineEvent:(nonnull NSString *)deviceID
                  channelId:(nullable NSString *)channelId
                    eventId:(nonnull NSString *)eventId
                  eventType:(nonnull NSString *)eventType
                  startTime:(nonnull NSDate *)startTime
                     region:(nonnull NSString *)region
                 completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 删除timelineSection
 
 @param deviceId required，设备ID
 @param channelId optional，目前支持：1:qvga; 2:720p, 3:1080p，只校验格式，自己保证有效性。
 @param startTime startTime
 @param endTime endTime
 @param ifDeleteClip 是否删除Clip Video
 @param completion Completion Handler
 */
- (void)deleteTimelineSectionsWithDeviceId:(nonnull NSString *)deviceId
                                 channelId:(nullable NSString *)channelId
                                 startTime:(nullable NSDate *)startTime
                                   endTime:(nullable NSDate *)endTime
                              ifDeleteClip:(BOOL)ifDeleteClip
                                completion:(CLXHttpTaskCompletionHandler)completion;
/**
 @remark 获取某一设备在套餐有效期内每天的事件类别及对应数量

 @param deviceId required，设备ID
 @param channelId optional，1:qvga; 2:720p；不传默认为2
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {NSDictionary}, 返回字典 {"deviceId":"xxxxS_t0000000aa09", "queryTime":1532007882361, "region":"china", "eventEveryDay": [{"date":"20180719", "value": [{"count":2, "eventType":"0"}] }
 */
- (void)getEventSummary:(nonnull NSString *)deviceId
              channelId:(nullable NSString *)channelId
               needMore:(BOOL (^_Nonnull)(void))needMore
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 判断某一设备在套餐有效期内每天是否有fr事件
 
 @param deviceId required，设备ID
 @param channelId optional，1:qvga; 2:720p；
 @param completion optional，Completion Handler: {NSDictionary}, 返回字典 {"deviceId":"xxxxS_t0000000aa09", "queryTime":1532007882361, "region":"china", "frEveryDay": [] , "date" : "yyyyMMdd", "hasFr" : ""}
 */
- (void)getFRSummary:(nonnull NSString *)deviceId
           channelId:(nullable NSString *)channelId
          completion:(CLXHttpTaskCompletionHandler)completion
              isStop:(void(^_Nullable)(void))isStop;

/**
 @remark 获取某一设备在套餐有效期内每天是否有视频回放数据
 
 @param deviceId required，设备ID
 @param channelId optional，1:qvga; 2:720p；不传默认为2
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {NSDictionary}, 返回字典 {"deviceId":"xxxxS_t0000000aa09",  "region":"china", "sectionEveryDay": [ {"date":"20181024", "hasData":true}] }
 */
- (void)getSectionSummary:(nonnull NSString *)deviceId
                channelId:(nullable NSString *)channelId
                 needMore:(BOOL (^_Nonnull)(void))needMore
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取某个用户下的摄像头设备的最新event信息.
 
 @param deviceId 设备ID （多个设备时：设备的ID逗号分隔多个，eg: xxxxS_xxxxxx, xxxxS_yyyy
        当设备个数大于5时，平台返回错误码20068，需要APP分批次调用）
 @param channelId 1:qvga; 2:720p；不传默认为2
 @param limitNum 获取多少条记录
 @param eventType optional, 事件类型 
    （当eventType非空时，limit_num默认= 1，eventType只能是一个，且不要针对同一个设备同时调用多于1个的EventType的情况（也就是同一时间段多次调用），
    发现存在这种情况，平台会做屏蔽操作）;
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion Completion Handler
 */
- (void)getRecentEventList:(nonnull NSString *)deviceId
                 channelId:(nullable NSString *)channelId
                  limitNum:(nullable NSNumber *)limitNum
                 eventType:(nullable NSString *)eventType
                  needMore:(BOOL (^_Nonnull)(void))needMore
                completion:(CLXHttpTaskCompletionHandler)completion;
#pragma mark - Album and picture
/**
 获取图片列表
 
 @param deviceId required，设备ID
 @param pageSize optional，分页时每页显示的文件数量，默认200
 @param fileTime optional，查询时间点，从这个时间向左侧查询，不传默认为当前时间
 @param startTime required，开始时间
 @param endTime required，结束时间
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {CLXImageList}
 */
- (void)getImageList:(NSString *_Nonnull)deviceId
            pageSize:(NSNumber *_Nullable)pageSize
            fileTime:(NSDate *_Nullable)fileTime
           startTime:(NSDate *_Nonnull)startTime
             endTime:(NSDate *_Nonnull)endTime
            needMore:(BOOL (^_Nullable)(void))needMore
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 创建时光隧道
 
 @param completion optional，Completion Handler: deviceId<NSString *>}
 */
- (void)checkNewAlbum:(CLXHttpTaskCompletionHandler)completion;

/**
 获取Album列表
 
 @param deviceId required，设备ID
 @param needMore optional，是否自动请求更多分页数据，return NO或者传nil时只请求一次，可以在block里设置条件
 @param completion optional，Completion Handler: {NSArray<CLXAlbumListItem>}
 */
- (void)getAlbumList:(NSString *_Nonnull)deviceId
            needMore:(BOOL (^_Nullable)(void))needMore
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取Album图片
 
 @param deviceId required，设备ID
 @param region required，Album图片的authServer
 @param startTime required，开始时间
 @param endTime required，结束时间
 @param completion optional，Completion Handler: {NSArray<CLXPicListItem>}
 */
- (void)getAlbumPicList:(NSString *_Nonnull)deviceId
                 region:(NSString *_Nonnull)region
              startTime:(NSDate *_Nonnull)startTime
                endTime:(NSDate *_Nonnull)endTime
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除Album图片
 
 @param deviceId required，设备ID
 @param region required，Album图片的authServer
 @param startTime optional，开始时间
 @param endTime optional，结束时间
 @param picIds required，图片id的集合
 @param completion optional，Completion Handler: {}
 */
- (void)deleteAlbumPicList:(NSString *_Nonnull)deviceId
                    region:(NSString *_Nonnull)region
                 startTime:(NSDate *_Nullable)startTime
                   endTime:(NSDate *_Nullable)endTime
                    picIds:(NSArray *_Nullable)picIds
                completion:(CLXHttpTaskCompletionHandler)completion;

/**
 重命名Album图片
 
 @param deviceId required，设备ID
 @param region required，Album图片的authServer
 @param picId required，图片id
 @param name required，更改后的pic名称
 @param completion optional，Completion Handler: {}
 */
- (void)renameAlbumPic:(NSString *_Nonnull)deviceId
                region:(NSString *_Nonnull)region
                 picId:(NSString *_Nonnull)picId
                  name:(NSString *_Nonnull)name
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除Album
 
 @param deviceId required，设备ID
 @param region required，Album的authServer
 @param startTime required，开始时间
 @param endTime required，结束时间
 @param completion optional，Completion Handler: {}
 */
- (void)deleteAlbum:(NSString *_Nonnull)deviceId
             region:(NSString *_Nonnull)region
          startTime:(NSDate *_Nonnull)startTime
            endTime:(NSDate *_Nonnull)endTime
         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 收藏Album
 
 @param deviceId required，设备ID
 @param region required，Album的authServer
 @param title optional，相册命名，不传则由系统自动生成，传入则不包含特殊字符
 @param from optional，来源，0：app, 1: camera 不传系统默认为app发起
 @param sync optional，是否同步 “0”：同步，“1”：异步，不传默认异步
 @param startTime required，开始时间
 @param endTime required，结束时间
 @param completion optional，Completion Handler: {fileId<NSString>}
 */
- (void)collectAlbum:(NSString *_Nonnull)deviceId
              region:(NSString *_Nonnull)region
               title:(NSString *_Nullable)title
                from:(NSString *_Nullable)from
                sync:(NSString *_Nullable)sync
           startTime:(NSDate *_Nonnull)startTime
             endTime:(NSDate *_Nonnull)endTime
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取图片url

 @param deviceId required，设备ID
 @param region required，图片下载的server
 @param fileId required，图片id
 @return imageUrl，返回完整的图片下载地址
 */
- (NSString *_Nonnull)getImageUrl:(NSString *_Nonnull)deviceId
                           region:(NSString *_Nonnull)region
                           fileId:(NSString *_Nonnull)fileId;

/**
 获取缩略图

 @param deviceId required，设备ID
 @param region required，图片下载的server
 @param fileId required，图片id
 @return thumbnailUrl，返回完整的thumbnail下载地址
 */
- (NSString *_Nonnull)getThumbnailUrl:(NSString *_Nonnull)deviceId
                               region:(NSString *_Nonnull)region
                               fileId:(NSString *_Nonnull)fileId;

/**
 @remark 获取告警事件缩略图

 @param deviceId 设备ID
 @param eventId 事件ID
 @param startTime 事件开始时间
 @param completion Completion Handler: {thumbnailUrl<NSString>}
 */
- (void)getEventThumnailUrl:(nonnull NSString *)deviceId
                    eventId:(nonnull NSString *)eventId
                  startTime:(nonnull NSDate *)startTime
                 completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXRegionDispatcherProtocol_h */
