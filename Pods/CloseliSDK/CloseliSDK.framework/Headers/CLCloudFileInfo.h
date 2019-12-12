
typedef NS_ENUM(NSInteger, CLXAsFileType) {
    CLXAS_FILETYPE_OTHER = 0,              ///< Other files
	CLXAS_FILETYPE_FOLDER = 4,             ///< Folder/Directory
    CLXAS_FILETYPE_LECAM_SAVED_CLIP = 100,
};

@interface CLCloudFileInfo : NSObject

@property (nonatomic, copy) NSString *deviceUUID;

@property (nonatomic, copy) NSString *szName;///< file's name
@property (nonatomic, copy) NSString *szPathRemote;///< path in server
@property (nonatomic, copy) NSString *szDownloadServer;///< host name for server
@property (nonatomic, copy) NSString *szComments;//
@property (nonatomic, copy) NSString *szDuration;//video duration
@property (nonatomic, strong) NSDate *createTime;
@property (nonatomic, strong) NSDate *modifyTime;
@property (nonatomic, strong) NSDate *fileTime;
@property (nonatomic, assign) BOOL isHidden;///< file is hidden or not
@property (nonatomic, assign) int64_t llSize;///< file's size
@property (nonatomic, assign) int eUploadStatus;//upload state,
@property (nonatomic, copy) NSString *uploadError;
@property (nonatomic, assign) CLXAsFileType fileType;//file type in CLXAsFileType
@property (nonatomic, assign) int version;///file version in server
@property (nonatomic) NSInteger shareStatus;
@property (nonatomic, assign) BOOL isFolder;
///readonly items
@property(nonatomic, copy) NSString *szFileID;///< the unique file id in server
@property(nonatomic, copy) NSString *szParentID;///< the parent id in server
@property(nonatomic, copy) NSString *szThumbnailID;//thumbnail id in server

@property(nonatomic, strong) CLCloudFileInfo *parentFile;

- (id)initWithOther:(CLCloudFileInfo *)otherFile;

- (NSString *)getThumbnailURL;
- (NSString *)getSourceURL;

@end
