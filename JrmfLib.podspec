#
#  Be sure to run `pod spec lint JrmfStandardDemo.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|


  s.name         = "JrmfLib"
  s.version      = "1.0.1"
  s.summary      = "some sources of jrmf360"
  s.homepage     = "http://weibo.com/vamCriss"
  s.license      = 'MIT'
  s.author       = { "criss" => "ericluo0114@hotmail.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/VamCriss/JrmfLib.git", :tag => s.version }
  s.resource     = 'jrmfLib/*.{bundle,cer,framework}'
  s.requires_arc = true

  s.subspec 'AlipayLib' do |ss|
    ss.resource     = 'jrmfLib/AlipayLib/**'
    ss.frameworks = 'SystemConfiguration', 'CoreGraphics', 'QuartzCore', 'CoreText', 'CoreGraphics', 'UIKit', 'Foundation', 'CFNetwork', 'CoreMotion'
    ss.libraries = 'z', 'c++'
  end


  s.subspec 'WeChatSDK' do |ss|
    ss.frameworks = 'AVFoundation', 'Security', 'SystemConfiguration', 'CoreTelephony', 'CFNetwork'
    ss.libraries = 'sqlite3.0', 'stdc++', 'z.1.2.5'

    ss.subspec 'WXSDK' do |sss|
       sss.vendored_libraries = 'jrmfLib/WeChatSDK/WXSDK/libWeChatSDK.a'
       sss.source_files = 'jrmfLib/WeChatSDK/WXSDK/*.h'
    end

    ss.subspec 'SPaySDK' do |sss|
      sss.frameworks = 'Foundation', 'UIKit', 'CoreMotion', 'CoreTelephony', 'SystemConfiguration', 'CoreGraphics'
      sss.source_files = 'jrmfLib/WeChatSDK/SPaySDK/*.{a,h}'
      sss.resource = 'jrmfLib/WeChatSDK/SPaySDK/SPaySDKResource.bundle'
    end
  end

end
