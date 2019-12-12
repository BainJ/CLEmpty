//
//  CLXFileInfo.h

#import <Foundation/Foundation.h>

@interface CLXFileInfo : NSObject

@property (nonatomic, copy) NSString *fileId;
@property (nonatomic, copy) NSString *parentId;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *isFolder;
@property (nonatomic, copy) NSString *fileType;
@property (nonatomic, copy) NSString *uploadStatus;
@property (nonatomic, copy) NSString *size;
@property (nonatomic, assign) long long modifyTime;
@property (nonatomic, assign) long long createTime;
@property (nonatomic, assign) long long fileTime;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *downloadServer;
@property (nonatomic, copy) NSString *comment;
@property (nonatomic, copy) NSString *thumbnail;
@property (nonatomic, copy) NSString *duration;

@end

/**
 文件列表item
 */
@interface CLXFileListItem : NSObject

@property (nonatomic, copy) NSString *fileId;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *fileType;
@property (nonatomic, assign) long long fileSize;
@property (nonatomic, assign) long long fileTime;
@property (nonatomic, assign) long long duration;
@property (nonatomic, copy) NSString *downloadServer;

/**
 获取缩略图URL

 @return URL String
 */
- (NSString *)getThumbnailURL;

/**
 获取播放URL

 @return URL String
 */
- (NSString *)getSourceURL;

@end

/**
 文件列表
 */
@interface CLXFileList : NSObject

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, assign) NSUInteger pageSize;
@property (nonatomic, assign) long long lastClipTime;
@property (nonatomic, assign) BOOL hasMore;
@property (nonatomic, strong) NSArray <CLXFileListItem*>*dataList;

@end

/**
 时光缩影image列表item
 */
@interface CLXImageListItem : NSObject

@property (nonatomic, copy) NSString *imageId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *fileTime;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, copy) NSString *downloadServer;
@property (nonatomic, copy) NSString *deviceId;

@end

/**
 时光缩影image列表
 */
@interface CLXImageList : NSObject

@property (nonatomic, copy) NSString *pageSize;
@property (nonatomic, assign) BOOL hasMore;
@property (nonatomic, copy) NSString *downloadServer;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, strong) NSArray <CLXImageListItem *> *images;

@end

@interface CLXAlbumListItem : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *downloadServer;
@property (nonatomic) NSUInteger picId;
@property (nonatomic) long long startTime;
@property (nonatomic) long long endTime;
@property (nonatomic) NSUInteger remainDays;

@end

@interface CLXPicListItem : NSObject

@property (nonatomic, copy) NSString *downloadServer;
@property (nonatomic) NSString *picId;
@property (nonatomic) long long picTime;
@property (nonatomic) NSString *picName;
@end

@interface CLXTimelineStorageResult : NSObject

@property (nonatomic, assign) unsigned long long uid;               //-> uid
@property (nonatomic, assign) unsigned long long did;               //-> did
@property (nonatomic, copy) NSString *deviceId;                     //-> device id
@property (nonatomic, assign) unsigned long long totalTime;         //-> 最大存储时间
@property (nonatomic, assign) unsigned long long usedTime;          //-> 已用存储时间

@end
