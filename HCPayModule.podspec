#
# Be sure to run `pod lib lint HCPayModule.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'HCPayModule'
  s.version          = '1.0.3'
  s.summary          = 'HCPayModule.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/hondaVSP/HCPayModule'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '445878662@qq.com' => 'gongm@reachauto.com' }
  s.source           = { :git => 'https://github.com/hondaVSP/HCPayModule.git', :tag => s.version }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  s.static_framework = true

  # 暴露出去的头文件
  s.public_header_files = 'HCPayModule/Classes/HCPayServiceManager.h'
  
  s.vendored_frameworks = 'HCPayModule.framework'

  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'x86_64 armv7 arm64',
    'OTHER_LDFLAGS' => '-lObjC'
  }

  s.frameworks = 'Security','CoreGraphics','WebKit'

  
  s.dependency 'WechatOpenSDK'
  s.dependency 'AlipaySDK-iOS'
  s.dependency 'MJExtension'
  s.dependency 'Aspects'
  
end
