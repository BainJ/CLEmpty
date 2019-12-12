
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 @brief CLXPlayerInterface
 */
@protocol CLXPlayerInterface <NSObject>

/**
 播放
 @return YES成功 NO失败
 */
- (BOOL)play;

/**
 暂停
 @return YES成功 NO失败
 */
- (BOOL)pause;

/**
 帧率
 @return 帧率
 */
- (long)getPlayFPS;

/**
 码率
 @return 码率
 */
- (long)getBitrate;

/**
 拖动点按位置
 @return 拖动点按位置
 */
- (double)getPosition;

/**
 画面Size
 @return 画面Size
 */
- (CGSize)getVideoSize;

 /**
  是否是回放
  @return YES 是 NO 否
  */
- (BOOL)isTimelinePlayback;


/**
 修改视频播放视图
 @param mainScreen 设备的内部屏幕边界
 @param newFrame 播放的新Frame
 @return YES 成功 NO 失败
 */
- (BOOL)changeScreen:(CGRect)mainScreen andFrame:(CGRect)newFrame;

/**
 设置音量
 @param volume 0-100 0静音 100最大音量
 */
- (void)setVolume:(float)volume;

/**
 截屏
 @param image image指针
 @param bOriginalPic 原始尺寸
 @return YES NO
 */
- (BOOL)getPlayerOpenGLSnapshot:(UIImage **)image andOption:(BOOL)bOriginalPic;

/**
 AudioTalk的指针
 @param audioOutput AudioTalk的指针
 @return YES NO
 */
- (BOOL)getPlayerAudioOutputHandle:(void **)audioOutput;

/**
 倍速播放
 @param rate 1、2、4、8等
 */
- (void)setPlaybackSpeed:(float)rate;

/**
 当前的时间
 @return 当前播放的时间
 */
- (double)getCurrentTime;

/**
 开始的时间
 
 @return 当前播放的时间
 */
- (NSDate *)getStartTime;
#pragma mark - FishEye
/**
 Pinch手势事件更新View

 @param viewVelocity Pinch手势 scale
 @param midPoint 手势View中心点坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchPinch:(float)viewVelocity withMidPoint:(CGPoint)midPoint;

/**
 double tap手势事件更新View

 @param tapPoint double tap坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewDoubleTap:(CGPoint)tapPoint;

/**
 touch move更新View

 @param viewXYVelocityDict means the velocity for touch move of X and Y
 例:
 NSDictionary *viewXYVelocityDict = @{
 @"mViewXVelocity":@([(UIPanGestureRecognizer *)panges velocityInView:panges.view].x),
 @"mViewYVelocity":@([(UIPanGestureRecognizer *)panges velocityInView:panges.view].y)
 };
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchXYVelocity:(NSDictionary * )viewXYVelocityDict;

/**
 touch move更新View

 @param touchEventType touch event事件
 TOUCH_UP == 0
 TOUCH_DOWN == 1
 TOUCH_MOVE == 2
 @param touchPoint1 touch point 1坐标
 @param touchPoint2 touch point 2坐标
 @return 是否设置成功
 */
- (BOOL)updatePlayerViewTouchEvent:(int)touchEventType andStart:(CGPoint)touchPoint1 andEnd:(CGPoint)touchPoint2;

/**
 设置自动巡航模式

 @param curiseStatus 0（关） or 1（开）
 @param velocity 速率默认 1.0
 @return 是否设置成功
 */
- (BOOL)setAutoCuriseModeVelocity:(int)curiseStatus andVelocity:(float)velocity;

/**
 设置YUV数据流
 （接口应该在CLXPlayerDelegate：- (void)onPlayerConfig;代理方法中调用才生效）
 @param bufAddr 返回数据流地址
 @param bufLen 流的字节长度 视频大小的3/2，例如1280p:1280*960*3/2;
 @param pMutex 安全锁
 @return 是否设置成功
 */
-(BOOL)setFEYUVBuffer:(char *)bufAddr BufLen:(int)bufLen mutexBuf:(pthread_mutex_t*)pMutex;

/**
 设置鱼眼模式

 @param mode means display type for fisheye camera， unsupport fisheye when Mode is 0
 @return 是否设置成功
 */
- (BOOL)setFEMode:(int)mode;

/**
 设置鱼眼基础动画

 @param bIsNeedAnimation 是否需要动画
 @param dict contain string: "fCamZ", "fCamTranZ", "fCamRotZ", "fCamTranY", "fTz", "fCamAngleZ", "fzAngle", used to save FishEye current status。通过getFECurrentStatus获取NSDictionary
 @return 是否设置成功
 */
- (BOOL)setFEBasicAnimation:(BOOL)bIsNeedAnimation andCurrentFEStatus:(NSDictionary*)dict;

/**
 获取当前视图状态

 @param dict used to save FishEye current status
 @return 是否设置成功
 */
- (BOOL)getFECurrentStatus:(NSDictionary**)dict;

/**
 开关鱼眼背景星云

 @param bIsNeedStar 星星开关
 @param bIsNeedCloud 云开关
 @return 是否设置成功
 */
- (BOOL)setStarCloudBackground:(BOOL)bIsNeedStar andCloud:(BOOL)bIsNeedCloud;

#pragma mark - 
/**
 获取缩放比例

 @return float
 */
- (float)getAmultiple;

/**
 停止openGL绘图，在主动或被动停止播放或进入后台时需调用
 */
- (void)stopOpenGLDrawing;

/**
 设置player参数
 */
- (BOOL)setPlayerConfig:(int)config andValue:(void *)value;

/**
 @remark 获取player参数

 @param cfgID: ID of config;
 @param cfgValue: value of the config;
 @return YES
 */
- (BOOL)getConfig:(int)cfgID andValue:(void *)pCfgValue;

/**
 @remark 设置播放器放大倍数
 
 @param scale 原始放大倍数，初始化为1.0
 */
- (void)setOpenGLFullView:(float)scale;

/**
 @remark 设置画面畸变矫正
 
 @param distortionParam 参数来源于设置项 @see CLXVideoAdjustData
 */
- (BOOL)setDistortionParam:(NSString *)distortionParam;

/**
 @remark 设置retry机制重试时间
 
 @param time 秒，默认是10S
 */
- (void)setPlayRetryTime:(NSInteger)time;

@end
