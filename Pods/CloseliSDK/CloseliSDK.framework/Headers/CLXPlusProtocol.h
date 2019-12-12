/**
 @brief 相关方法
 */
@protocol CLXPlusProtocol
/**
 *  获取Domain
 *  @param type         类型
 *  @return NSString    对应的Domain
 */
- (NSString*)getApiDomainString:(Base_API_Type)type;

/**
 *  获取CA证书路径
 *  @return NSString       证书路径
 */
- (NSString*)getServerCAFilePath;

/**
 *  获取CA证书路径
 *  @return NSString       证书路径
 */
- (NSString*)getServerCAFilePathIfSupport;

/**
 *  获取Domain PreUrl
 *  @return NSString       PreUrl
 */
- (NSString*)getDvrPlanPreUrl;

/**
 *  获取Domain RelayServerUrl
 *  @return NSString       ServerUrl
 */
- (NSString*)getFullRelayServerUrl;

/**
 *  获取Domain PurchaseUrl
 *  @param isInternational
 *  @return NSString           PurchaseUrl
 */
- (NSString*)getPurchaseUrl:(BOOL)isInternational;

/**
 *  服务器环境类型
 *  @return BOOL      是否是Pro环境
 */
- (BOOL)isServerPro;

@end
