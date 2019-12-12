//
//  CLXFaceDetectionProtocol.h
//  CLSDK

#ifndef CLXFaceDetectionProtocol_h
#define CLXFaceDetectionProtocol_h

#import "CLXHttpClientDefine.h"
#import "CLXFaceDetectionModel.h"

/**
 @brief 人脸检测相关API
 */
@protocol CLXFaceDetectionProtocol <NSObject>

/**
 获取指定设备关联的人脸id列表.
 
 @param deviceId 设备mac地址
 @param dvrdays 套餐天数，如7天、30天
 @param limit 返回的人脸数据数量, 不传表示返回所有
 @param personType 0代表陌生人，1代表熟人，nil代表所有
 @param completion Completion Handler <CLXFDFaceListModel>
 */
- (void)getDeviceFaceList:(nullable NSString *)deviceId
                  dvrdays:(NSInteger)dvrdays
                    limit:(nullable NSString *)limit
               personType:(nullable NSString *)personType
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 保存指定人员的姓名.
 
 @param deviceId 设备mac地址
 @param personId 人脸唯一标志
 @param personName 人脸名称，不能为空字符串
 @param pushStatus 推送开关，取值1/0，1表示开启，0表示关闭
 @param label 人脸标签 空表示删除，其他数值表示变更.{ "家人","朋友”,“邻居”,"快递员","可疑人员"，"危险人物"}
 @param completion Completion Handler
 */
- (void)saveFaceInfo:(nullable NSString *)deviceId
            personId:(nonnull NSString *)personId
          personName:(nonnull NSString *)personName
          pushStatus:(nullable NSString *)pushStatus
               label:(nullable NSString *)label
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除指定人员的姓名.
 
 @param personIds 人脸唯一标志列表
 @param completion Completion Handler
 */
- (void)deleteFaceInfo:(nonnull NSArray *)personIds
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取人脸特征排序后的照片(最多9张).
 
 @param deviceId 设备mac地址
 @param personId 人脸唯一标志
 @param limit 返回的人脸数据数量, 不传表示返回所有
 @param completion Completion Handler
 */
- (void)getFacePicList:(nonnull NSString *)deviceId
              personId:(nonnull NSString *)personId
                 limit:(nullable NSString *)limit
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取人脸检测图片地址.
 
 @param deviceId 设备mac地址
 @param personId 人脸唯一标志
 @return 拼接后的图片地址
 */
- (nonnull NSString *)fetchFacePicUrl:(nonnull NSString *)deviceId
                     personId:(nonnull NSString *)personId;

/**
 将熟人设置成陌生人.
 
 @param deviceId 设备mac地址
 @param personId 人脸唯一标志列表
 @param completion Completion Handler
 */
- (void)makeFaceStranger:(nullable NSString *)deviceId
                personId:(nullable NSString *)personId
              completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取人脸标签列表

 @param completion 返回
 {
 　　"code":"200",
 　　"msg":"success",
 　　"memo":"",
 　　"data":[ "家人","朋友”,“邻居","快递员","可疑人员"，"危险人物"]
 }
 */
- (void)getFaceLabelList:(CLXHttpTaskCompletionHandler)completion;

/**
 获取人脸数据信息

 @param personIds personid数组
 @param callbackModel 需要返回的数据model，基类是CLXPersonFaceInfo
 @param completion 返回callbackModel数据类型
 */
- (void)getPersonFaceInfo:(nonnull NSArray *)personIds
            callbackModel:(nonnull Class<CLXPersonFaceInfo>)callbackModel
               completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取某用户下人脸头像列表 ，按套餐内天获取（日期是一个区间[startDate,endDate]）

 @param deviceId 设备ID
 @param uid 用户ID
 @param startDate 开始时间，不小于当前时间减去套餐天数的时间，20190503
 @param endDate 结束时间，不大于当前时间，大于则按照当前时间计算，时间跨度最大7天，超过7天，按7天算（以传值startDate,endDate准确的那个值，向前或者向后减去7天，都不准确按照当前时间减7天）20190510
 @param completion 返回
 {
 "msg":"success",
 "code":"200",
 "data":{
 "20190531":[
 {
 "personName":"",
 "score":"0",
 "appearDate":"20190531",
 "personId":"a4e6b1f6837111e9860c02e522212e96",
 "label":"",
 "deviceId":"xxxxS_0c8c24d3a5c0,xxxxS_20323347eeee",
 "url":"http://xxxx/app/fs/v1/face/pic/get/spe?client_id=1cad3c83-d87&pic_id=6959&token=49f820a79bdc4b5a80c584c8eb7b3ef6&timestamp=1559308595398&sign=0d7f016dacb96d7dd7e9b2e7a2a32f77",
 "featureId":"a4bb8562837111e985de02e522212e96"
 }
 ],}}
 */
- (void)getFacePicList:(nullable NSString *)deviceId
                   uid:(nullable NSString *)uid
             startDate:(nonnull NSString *)startDate
               endDate:(nonnull NSString *)endDate
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 人脸合并接口

 @param sourcePersonId 源人脸id
 @param targetPersonId 目标人脸id
 @param completion {success or fail}
 */
- (void)mergePersonFaceWithSourceId:(nonnull NSString *)sourcePersonId
                     targetPersonId:(nonnull NSString *)targetPersonId
                         completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除单张人脸图片

 @param picId picId
 @param deviceId 设备ID
 @param completion {success or fail}
 */
- (void)deleteFacePicWithPicId:(nullable NSString *)picId
                      deviceId:(nullable NSString *)deviceId
                    completion:(CLXHttpTaskCompletionHandler)completion;

@end
#endif /* CLXFaceDetectionProtocol_h */
