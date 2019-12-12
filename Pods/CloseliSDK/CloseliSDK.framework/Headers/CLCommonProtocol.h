//
//  CLCommonProtocol.h

#import "CLRegionDispatcher.h"
#import "CLSDKHeader.h"

typedef void (^_Nonnull CLXSDKInitCallback)(BOOL isSuccessed);

/**
 @brief 一些通用的接口，包括SDK初始化、日志开关，获取SDK版本号等
 */
@protocol CLCommonProtocol <NSObject>

/**
 @remark SDK初始化
 
 @param productKey 平台提供的productKey
 @param productPassword 平台提供的productSecret
 @param serverEnv 服务器类型, @see CLXServerEnv
 @return SDK单例
 */
- (nonnull id)initWithProductKey:(nonnull NSString *)productKey withPassword:(nonnull NSString *)productPassword serverEnv:(CLXServerEnv)serverEnv;

/**
 @remark DeviceData初始化, 也可以通过 [[CLRegionDispatcher alloc] init] 直接初始化
 
 @return CLRegionDispatcher实例
 */
- (nonnull CLRegionDispatcher *)getDeviceData;

/**
 @remark 获取当前SDK实例对象，需要初始化之后才可以获取
 
 @return SDK单例
 */
+ (nonnull id)sharedInstance;

#pragma mark - SDK Util
/**
 @remark 获取当前设备mac
 
 @param symbol YES
 */
- (nullable NSString *)getConnectId:(BOOL)symbol;

/**
 @remark 设置 CLSDK 调试 log 开关. 注意: 该接口需要在sdk初始化之后，而且在调用sdk其他接口之前，进行设置.
 
 @param flag  调试log枚举.指定要打开哪些log.可以用|符号来打开多个开关。例：DebugFlag_tcpBuffer | DebugFlag_cloud
 */
- (void)setDebugWithFlag:(debugFlag_E)flag;

/**
 @remark 获取当前Libs版本
 
 @return version 字符串
 */
- (nonnull NSString *)getCurrentLibsVersion;

/**
 @remark 设置单独的requestId
 
 @param className 类名
 @param requestId ID
 */
- (void)attachRequestIdOnAPIClass:(nonnull NSString *)className requestId:(nonnull NSString *)requestId;

/**
 @remark 是否开启动态域名
 
 @param callback 是否初始化成功
 */
+ (void)enableAutoDns:(CLXSDKInitCallback)callback retryTime:(NSInteger)retryTime;

/**
 @remark 重新设置环境
 
 @param serverEnv 四套环境
 @param productKey 平台提供
 @param productSecret 平台提供
 */
- (void)resetSDKWithServerEnv:(CLXServerEnv)serverEnv productKey:(nonnull NSString *)productKey productSecret:(nonnull NSString *)productSecret;

/**
 @remark 更新配置域名，域名需与初始化环境一致。例如 初始化设置的是CLXServerEnvPro，就不能设置CLXServerEnvStg的域名
 
 @param domains 需要更新的域名。例如 @{ @"api_server_ip" : @"api.xxxx.cn" }
 */
- (BOOL)updateDomains:(nonnull NSDictionary *)domains;

/**
 检测网络工具

 @param progress 进度
 @param completeBlock 完成回调
 */
- (void)checkNetworkProgress:(void(^_Nullable)(NSDictionary * _Nullable result))progress completeBlock:(void(^_Nullable)(NSDictionary * _Nullable result))completeBlock;

/**
 请求工具

 @param requestUrl 完整的URL，例如 http://test.com/getInfo
 @param requestParams 请求参数
 @param completion 请求完成回调
 */
- (void)requestServerWithURL:(NSString *_Nullable)requestUrl requestParams:(NSDictionary *_Nullable)requestParams               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 请求sign工具

 @param params 参数
 @param signType sign类型, 见以下枚举
 {
     SignatureWithMD5V1,
     SignatureWithRSA,
     SignatureWithMD5,
     SignatureWithDES
 }
 @param secretKey 签名key
 @return 返回结果
 */
- (NSString *_Nullable)getSignString:(NSDictionary *_Nullable)params signType:(NSInteger)signType secretKey:(NSString *_Nullable)secretKey;

@end
