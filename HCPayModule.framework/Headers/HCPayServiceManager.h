//
//  HCPayServiceManager.h
//  HCPayModule
//
//  Created by Zac on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^CompletionBlock)(NSDictionary * _Nullable resultDic);


///支付类型
typedef NS_ENUM(NSInteger, HCPayType)
{
    HCPayAli = 1 << 0,//支付宝 1
    HCPayWx = 1 << 1,//微信 2
};

/**
 * 支付结果回调
 */

typedef void(^HCPayBlock)(BOOL success,NSString * _Nonnull msg);

typedef void(^HCCompletionBlock)(NSDictionary * _Nullable resultDic);

NS_ASSUME_NONNULL_BEGIN

@interface HCPayServiceManager : NSObject 

+ (id)sharedInstance;

/**
 * 处理授权信息Url
 *
 * @param resultUrl        钱包返回的授权结果url
 * @param payType 支付类型
 * @param completionBlock  授权结果回调

 */
- (void)hc_processAuthUrl:(NSURL *)resultUrl
                  payType:(HCPayType)payType
          standbyCallback:(CompletionBlock)completionBlock;


/**
 拉起微信支付
 
 @param orderSign 拉起支付所用签名数据
 @param resultBlock <#resultBlock description#>
 */
- (void)hc_paymentWXResultWithOrdersign:(NSString *)orderSign
                            resultBlock:(HCPayBlock)resultBlock;

/**
 拉起微信支付(universalLink)
 
 @param orderSign 拉起支付所用签名数据
 @param resultBlock <#resultBlock description#>
 @param universalLink <#universalLink description#>
 */
- (void)hc_paymentWXResultWithOrdersign:(NSString *)orderSign
                          universalLink:(NSString *)universalLink
                            resultBlock:(HCPayBlock)resultBlock;


/**
 拉起支付宝支付
 
 @param orderSign 拉起支付所用签名数据
 @param scheme 调用支付的app注册在info.plist中的scheme
 @param resultBlock <#resultBlock description#>
 */
- (void)hc_paymentAliWithOrdersign:(NSString *)orderSign
                            scheme:(NSString *)scheme
                       resultBlock:(HCPayBlock)resultBlock;


/**
 拉起支付宝H5支付
 
 @param url 拉起支付所用h5
 @param scheme 调用支付的app注册在info.plist中的scheme
 @param resultBlock <#resultBlock description#>
 */
- (BOOL)hc_paymentAliH5WithOrdersign:(NSString *)url
                            scheme:(NSString *)scheme
                       resultBlock:(HCPayBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
